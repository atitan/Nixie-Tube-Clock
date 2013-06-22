/*
 * nixie_test.c
 *
 * Created: 2011/12/23 下午 05:39:58
 *  Author: ATI
 */ 

#include "divergence.h"
#include "nixie-test.h"

//變數宣告
char put_num[8];
char put_con[8];
unsigned char year0,year1,mon0,mon1,day0,day1,hour0,hour1,min0,min1,sec0,sec1;
int tuning_switch = 0;
int time_switch = 0;
int diver_switch = 0;
int is_date = 0;

int main(void)
{

	//Port初始化
		DDRB = 0xFF;
		DDRD = 0xF3;
		DDRC = 0x00;
		PORTC = 0xFF;
	
	//RTC通訊初始化
		i2c_init(100000);
		unsigned char val[1] = {0x00};
		i2c_2_write(0x07, val, 1);	// Disable SQW
		i2c_2_read(0x00, val, 1);
		if ((val[0] & 0x80) == 0x80)
		{
			val[0] = val[0] & 0x7F;
			i2c_2_write(0x00, val, 1);	// Reset CH bit
		}			
		read_rtc_time();
	
	//RTC初始化失敗
		if( !(year0 >= 0 && year0 <= 9) ){
			while(1){
				set_num_v(0,0,0,0,0,0,0,0);
				set_col_v(1,1,1,1,1,1,1,1);
				disp_tube(1);
			}
		}

	//主迴圈
    while(1)
    {
		if (((PINC >> 1) & 0x01) == 0)
		{
			tuning_switch++;
			
			if (tuning_switch>50)
			{
				tuning_switch = 0;
				time_tuning();
			}
		}
		else
		{
			tuning_switch = 0;
		}
		
		if (((PINC >> 2) & 0x01) == 0)
		{
			if (time_switch == 20 )
			{
				time_switch = 20;
			}
			else if(time_switch == 40)
			{
				time_switch = 40;
			}
			else
			{
				time_switch++;
			}
		}
		else 
		{
			if (time_switch < 20 || time_switch == 40)
			{
				time_switch = 0;
				is_date = 0;
			}
			else if(time_switch > 21 && time_switch < 40)
			{
				time_switch = 21;
				is_date = 1;
			}
			else if(time_switch == 20)
			{
				time_switch = 21;
				is_date = 1;
			}
		}
		
		if (((PINC >> 3) & 0x01) == 0)
		{
			diver_switch++;
			if (diver_switch>100)
			{
				diver_switch = 0;
				divergence_mode();
			}
		} 
		else
		{
			if (diver_switch>=20 && diver_switch<=100)
			{
				diver_switch = 0;
				divergence_value(1000);
			}
			else
			{
				diver_switch = 0;
			}
		}
				
		timer_mode();
		read_rtc_time();
		
		if (0==min1 && 0==sec0 && 0==sec1)
		{
			divergence_value(800);
		}
	
	
	}//迴圈結束

}//主程式結束

//讀取RTC時間
void read_rtc_time()
{
	unsigned char time_data[7];
	
	i2c_2_read( 0x00 , time_data ,7);

	year0 = (time_data[6] >> 4) & 0x0f;
	year1 = time_data[6] & 0x0f;
	mon0  = (time_data[5] >> 4) & 0x01;
	mon1  = time_data[5]& 0x0f;
	day0  = (time_data[4] >> 4) & 0x03;
	day1  = time_data[4]& 0x0f;
	hour0 = (time_data[2] >> 4) & 0x03;
	hour1 = time_data[2]& 0x0f;
	min0  = (time_data[1] >> 4) & 0x07;
	min1  = time_data[1]& 0x0f;
	sec0  = (time_data[0] >> 4) & 0x07;
	sec1  = time_data[0]& 0x0f;

}

//時間模式
void timer_mode(){
	
	if (is_date)
	{
		set_num_v(2,0,year0,year1,mon0,mon1,day0,day1);
		set_col_v(0,0,0,1,0,1,0,1);
		disp_tube(1);
	}
	else
	{
		set_num_v(hour0,hour1,10,min0,min1,10,sec0,sec1);
		set_col_v(0,0,1,0,0,1,0,0);
		disp_tube(1);
		
	}
	
}

//燈管數字設定
void set_num_v(char buff1,char buff2,char buff3,char buff4,
					char buff5,char buff6,char buff7,char buff8){
	put_num[0]=buff1;
	put_num[1]=buff2;
	put_num[2]=buff3;
	put_num[3]=buff4;
	put_num[4]=buff5;
	put_num[5]=buff6;
	put_num[6]=buff7;
	put_num[7]=buff8;
}

//燈管小數點設定
void set_col_v(char buff1,char buff2,char buff3,char buff4,
					char buff5,char buff6,char buff7,char buff8){
	put_con[0]=buff1;
	put_con[1]=buff2;
	put_con[2]=buff3;
	put_con[3]=buff4;
	put_con[4]=buff5;
	put_con[5]=buff6;
	put_con[6]=buff7;
	put_con[7]=buff8;
}

////////////////////////
// 燈管掃描
//
// count : 掃描次數
////////////////////////
void disp_tube(int count){
	
	int i,j;
	char set_tube = 0;
	for(j = 0 ; j < count ; j++){
		for(i = 0 ; i < 8; i++){
			set_tube = (put_num[i] << 4)
						+ (put_con[i] & 0x01)
						+ (put_con[i] & 0x02);		// 燈號設定
			PORTD = (PORTD & 0x00) + set_tube;
			_delay_us(10);
			if( put_num[i] < 10 || put_con[i] > 0 ){
				PORTB = 0b00000001 << i;		// 亮燈位置
			}	
			_delay_us(60);			// 表示時間
			
			//PORTD = (PORTD & 0xfc);			// 清除選擇線
			PORTB = 0x00;			// 關燈
			_delay_us(600);			// 關燈時間
		}
	}
}

//調時模式
void time_tuning()
{	
	//宣告變數
	unsigned char tuned_time[7];
	unsigned char time_tuning_buffer[12];
	
	//同步時間
	time_tuning_buffer[0] = year0;
	time_tuning_buffer[1] = year1;
	time_tuning_buffer[2] = mon0;
	time_tuning_buffer[3] = mon1;
	time_tuning_buffer[4] = day0;
	time_tuning_buffer[5] = day1;
	time_tuning_buffer[6] = hour0;
	time_tuning_buffer[7] = hour1;
	time_tuning_buffer[8] = min0;
	time_tuning_buffer[9] = min1;
	time_tuning_buffer[10] = sec0;
	time_tuning_buffer[11] = sec1;
	
	//計數器歸零
	int breaking = 0, i = 0, button_speed = 0;
	
	//防暴衝
	while(1)
	{
		set_num_v(2,0,time_tuning_buffer[0],time_tuning_buffer[1],time_tuning_buffer[2],time_tuning_buffer[3],time_tuning_buffer[4],time_tuning_buffer[5]);
		set_col_v(0,0,1,0,0,0,0,0);
		disp_tube(1);
		
		if (((PINC >> 1) & 0x01) == 1)
		{
			break;
		}
	}
	
	for(i=0; i<12; i++){
		while((1)){
			if( i<6 ){
				set_num_v(2,0,time_tuning_buffer[0],time_tuning_buffer[1],time_tuning_buffer[2],time_tuning_buffer[3],time_tuning_buffer[4],time_tuning_buffer[5]);
				set_col_v(0,0,0,0,0,0,0,0);
				put_con[i+2]=1;
			}else{
				set_num_v(time_tuning_buffer[6],time_tuning_buffer[7],10,time_tuning_buffer[8],time_tuning_buffer[9],10,time_tuning_buffer[10],time_tuning_buffer[11]);
				set_col_v(0,0,0,0,0,0,0,0);
				if(i < 8){
					put_con[i-6]=1;
				}else if(i >= 8 && i < 10){
					put_con[i-5]=1;
				}else{
					put_con[i-4]=1;
				}
			}
			disp_tube(1);
			
			if (((PINC >> 0) & 0x01) == 0)
			{
				button_speed++;
				if (button_speed>20)
				{
					button_speed = 0;
					time_tuning_buffer[i]++;
					
					if( i == 0 || i == 1 || i == 9 || i == 11 ){
						if( time_tuning_buffer[i] > 9 ){
							time_tuning_buffer[i] = 0;
						}
					}else if( i == 2 ){
						if( time_tuning_buffer[i] > 1 ){
							time_tuning_buffer[i] = 0;
						}
					}else if( i == 3 ){
						if( time_tuning_buffer[i-1] == 1 ){
							if( time_tuning_buffer[i] > 2 ){
								time_tuning_buffer[i] = 0;
							}
						}else{
							if( time_tuning_buffer[i] > 9 ){
								time_tuning_buffer[i] = 1;
							}
						}
					}else if( i == 4 ){
						if( time_tuning_buffer[i] > 3 ){
							time_tuning_buffer[i] = 0;
						}
					}else if( i == 5 ){
						if( time_tuning_buffer[i-1] == 3 ){
							if( time_tuning_buffer[i] > 1 ){
								time_tuning_buffer[i] = 0;
							}
						}else{
							if( time_tuning_buffer[i-1] == 0 ){
								if( time_tuning_buffer[i] > 9 ){
									time_tuning_buffer[i] = 1;
								}
							}else{
								if( time_tuning_buffer[i] > 9 ){
									time_tuning_buffer[i] = 0;
								}
							}
						}	
					}else if( i == 6 ){
						if( time_tuning_buffer[i] > 2 ){
							time_tuning_buffer[i] = 0;
						}
					}else if( i == 7 ){
						if( time_tuning_buffer[i-1] == 2 ){
							if( time_tuning_buffer[i] > 3 ){
								time_tuning_buffer[i] = 0;
							}
						}else{
							if( time_tuning_buffer[i] > 9 ){
								time_tuning_buffer[i] = 0;
							}
							
						}
					}else if( i == 8 || i == 10){
						if( time_tuning_buffer[i] > 5 ){
							time_tuning_buffer[i] = 0;
						}
					}
				}
			}
			else
			{
				button_speed = 0;
			}
			
			if (((PINC >> 1) & 0x01) == 0)
			{
				breaking++;
				if (breaking>30)
				{
					button_speed = 0;
					breaking = 0;
					break;
				}
			}
			else
			{
				breaking = 0;
			}
		}
	}
	
	//匯集時間
	tuned_time[6] = (time_tuning_buffer[0] << 4) + time_tuning_buffer[1];
	tuned_time[5] = (time_tuning_buffer[2] << 4) + time_tuning_buffer[3];
	tuned_time[4] = (time_tuning_buffer[4] << 4) + time_tuning_buffer[5];
	tuned_time[2] = (time_tuning_buffer[6] << 4) + time_tuning_buffer[7];
	tuned_time[1] = (time_tuning_buffer[8] << 4) + time_tuning_buffer[9];
	tuned_time[0] = (time_tuning_buffer[10] << 4) + time_tuning_buffer[11];
	
	//寫入
	i2c_2_write(0x00, tuned_time, 7);
	
	//重新讀取時間
	read_rtc_time();
	
}