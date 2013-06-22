/*
 * divergence.c
 *
 * Created: 2012/2/25 下午 07:04:28
 *  Author: ATI
 */ 
#include "divergence.h"

void divergence_mode(void){
	int timing = 0;
	
	sg_lr_col(60);
	sg_rl_col(60);
	sg_lr_col(30);
	sg_rl_col(30);
	sg_lr_col3();
	sg_rl_num0();
	sg_lr_num1();
	sg_sc01();
	scl_num(4,1);
	scl_2_num(1,10,1,3,0,4,2,6);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(150);

	sg_count_up();
	sg_lr_col(30);
	sg_rl_col(30);
	sg_lr_colw();
	sg_rl_colw();
	scl_num(13,0);
	set_col_v(0,0,0,0,0,0,0,0);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(200);

	timing = 35;

	set_num_v(1,0,0,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(1,1,0,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(1,1,1,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(1,1,1,1,0,0,0,0);
	disp_tube(timing);
	set_num_v(1,1,1,1,1,0,0,0);
	disp_tube(timing);
	set_num_v(1,1,1,1,1,1,0,0);
	disp_tube(timing);
	set_num_v(1,1,1,1,1,1,1,0);
	disp_tube(timing);
	set_num_v(1,1,1,1,1,1,1,1);
	disp_tube(400);

	set_num_v(10,1,1,1,1,1,1,1);
	set_col_v(1,0,0,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(10,10,1,1,1,1,1,1);
	set_col_v(1,1,0,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(10,10,10,1,1,1,1,1);
	set_col_v(1,1,1,0,0,0,0,0);
	disp_tube(timing);
	set_num_v(10,10,10,10,1,1,1,1);
	set_col_v(1,1,1,1,0,0,0,0);
	disp_tube(timing);
	set_num_v(10,10,10,10,10,1,1,1);
	set_col_v(1,1,1,1,1,0,0,0);
	disp_tube(timing);
	set_num_v(10,10,10,10,10,10,1,1);
	set_col_v(1,1,1,1,1,1,0,0);
	disp_tube(timing);
	set_num_v(10,10,10,10,10,10,10,1);
	set_col_v(1,1,1,1,1,1,1,0);
	disp_tube(timing);
	set_num_v(10,10,10,10,10,10,10,10);
	set_col_v(1,1,1,1,1,1,1,1);
	disp_tube(60);
	set_num_v(10,10,10,10,10,10,10,10);
	set_col_v(2,2,2,2,2,2,2,2);
	disp_tube(60);
	set_num_v(10,10,10,10,10,10,10,10);
	set_col_v(3,3,3,3,3,3,3,3);
	disp_tube(300);
	
	timing = 35;
	
	set_col_v(3,3,3,3,3,3,3,2);
	disp_tube(timing);
	set_col_v(3,3,3,3,3,3,3,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,3,3,2,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,3,3,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,3,2,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,3,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,2,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,3,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,2,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,3,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,2,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,3,0,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,2,0,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(3,0,0,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(2,0,0,0,0,0,0,0);
	disp_tube(timing);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(timing);

	set_col_v(0,0,0,0,0,0,0,0);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(200);
	sg_sc012();
	sg_lr_col(18);
	sg_rl_col(18);

	sg_count_down();

	set_num_v(0,10,4,0,9,4,2,0);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(600);
	scl_num(9,1);
	scl_2_num(0,0,3,3,7,1,8,7);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(2000);

	scl_num(9,1);
	scl_2_num(1,0,0,4,8,5,9,6);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(2000);

}

void sg_lr_col(int bt){

//	int bt = 25;
	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);

	set_col_v(2,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(1,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,2,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,2,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,2,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,2,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,1,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,2,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,1,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,2,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,1,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,2);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
}

void sg_rl_col(int bt){
//	int bt = 7;
	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);

	set_col_v(0,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,2);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,1,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,2,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,1,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,2,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,1,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,2,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,2,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,2,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,2,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(1,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(2,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
}	

void sg_lr_col3(void){

	int bt = 30;

	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);

	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(2,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_col_v(1,0,0,0,0,0,0,2);
	disp_tube(bt);
	set_col_v(0,2,0,0,0,0,1,0);
	disp_tube(bt);
	set_col_v(0,1,0,0,0,0,2,0);
	disp_tube(bt);
	set_col_v(0,0,2,0,0,1,0,0);
	disp_tube(bt);
	set_col_v(0,0,1,0,0,2,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,1,2,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,2,1,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,1,0,0,2,0,0);
	disp_tube(bt);
	set_col_v(0,0,2,0,0,1,0,0);
	disp_tube(bt);
	set_col_v(0,1,0,0,0,0,2,0);
	disp_tube(bt);
	set_col_v(0,2,0,0,0,0,1,0);
	disp_tube(bt);
	set_col_v(1,0,0,0,0,0,0,2);
	disp_tube(bt);
	set_col_v(2,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_col_v(2,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_col_v(3,0,0,0,0,0,0,3);
	disp_tube(bt);
	set_col_v(3,2,0,0,0,0,1,3);
	disp_tube(bt);
	set_col_v(3,3,0,0,0,0,3,3);
	disp_tube(bt);
	set_col_v(3,3,2,0,0,1,3,3);
	disp_tube(bt);
	set_col_v(3,3,3,0,0,3,3,3);
	disp_tube(bt);
	set_col_v(3,3,3,2,1,3,3,3);
	disp_tube(bt);
	set_col_v(3,3,3,3,3,3,3,3);
	disp_tube(bt*9);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	
}

void sg_rl_num0(void){
	int bt = 30;

	set_col_v(0,0,0,0,0,0,0,0);
	set_num_v(10,10,10,10,10,10,10,10);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,10,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt*8);

}

void sg_lr_num1(void){

	int bt = 30;
	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);
	set_num_v(1,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,0,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,0,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,10,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,10,10);
	disp_tube(bt);

}

void sg_sc01(void){

	int bt = 18;

	set_num_v(10,10,10,10,10,10,10,10);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,10,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,0,0);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,0,0,1);
	disp_tube(bt);
	set_num_v(10,10,10,10,0,0,1,1);
	disp_tube(bt);
	set_num_v(10,10,10,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(10,10,0,0,1,1,0,0);
	disp_tube(bt);
	set_num_v(10,0,0,1,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(1,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,1,1,0,1);
	disp_tube(bt);
	set_num_v(0,1,0,1,1,0,1,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,1,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
//	set_num_v(10,10,10,10,10,10,10,10);
//	disp_tube(bt);

}

void scl_num(int ct,char flg){
	char i,j,k,l,m,n,o,p;
	for(;ct>0;ct--)
		for(i=0;i<10;i++){
			j=(i+2)%10;
			k=(i+4)%10;
			l=(i+7)%10;
			m=(i+5)%10;
			n=(i+1)%10;
			o=(i+8)%10;
			p=(i+6)%10;
			if( flg == 1){			
				j = 0x0f;
				set_col_v(0,1,0,0,0,0,0,0);
			}			
			set_num_v(i,j,k,l,m,n,o,p);
			disp_tube(3);
		}
}

void scl_2_num(char a,char b,char c,char d,char e,char f,char g,char h){

	char i,j,k,l,m,n,o,p;
	int ct; 
	for(ct = 0;ct < 9;ct++)
		for(i=0;i<10;i++){
			j=i;
			k=(i+4)%10;
			l=(i+7)%10;
			m=(i+5)%10;
			n=(i+1)%10;
			o=(i+8)%10;
			p=(i+6)%10;
			if(ct>1)l=d;
			if(ct>2)k=c;
			if(ct>3)m=e;
			if(ct>3)o=g;
			if(ct>4)j=a;
			if(ct>5)n=f;
			if(ct>7)p=h;
			
			set_num_v(j,10,k,l,m,n,o,p);
			set_col_v(0,1,0,0,0,0,0,0);
			if(ct != 9)
				disp_tube(3);
	}
			disp_tube(100);
}

void sg_count_up(void){

	char b1,b2,b3,b4,b5;
	char c1=0,c2=0;
	int cnt = 0;
	while(1){
		b1 = cnt / 1000;
		b2 = (cnt / 100)%10;
		b3 = (cnt / 10) %10;
		b4 = cnt % 10;
		if(cnt < 1000){b1 = 0x0f;}
		if(cnt < 100){b2 = 0x0f;c1=1;}else{c1=0;}
		if(cnt < 10){b3 = 0x0f;c2=1;}else{c2=0;}
		b5 = b4 + 3;
		if(b5 > 9){
			 b5-=10;
		}
		set_num_v(10,10,10,10,b2,b3,b4,b5);
		set_col_v(1,1,1,1,c1,c2,0,0);
		disp_tube(7);
		if(cnt == 280)break;
		cnt++;
	}
	set_num_v(10,10,10,10,b2,b3,b4,0);
	disp_tube(20);
	return;
}

void sg_lr_colw(void){

	int bt = 50;
	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);

	set_col_v(3,0,0,0,0,0,0,3);
	disp_tube(bt);
	set_col_v(0,3,0,0,0,0,3,0);
	disp_tube(bt);
	set_col_v(0,0,3,0,0,3,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,3,3,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,3,0,0,3,0,0);
	disp_tube(bt);
	set_col_v(0,3,0,0,0,0,3,0);
	disp_tube(bt);
	set_col_v(3,0,0,0,0,0,0,3);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
}

void sg_rl_colw(void){
	int bt = 50;
	set_num_v(0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f);

	set_col_v(3,0,0,0,0,0,0,3);
	disp_tube(bt);
	set_col_v(3,3,0,0,0,0,3,3);
	disp_tube(bt);
	set_col_v(3,3,3,0,0,3,3,3);
	disp_tube(bt);
	set_col_v(3,3,3,3,3,3,3,3);
	disp_tube(bt);
	set_col_v(0,3,3,3,3,3,3,0);
	disp_tube(bt);
	set_col_v(0,0,3,3,3,3,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,3,3,0,0,0);
	disp_tube(bt);
	set_col_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);

}

void sg_sc012(void){

	int bt = 20;

	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,1,1,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,1,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,1,1,0,1);
	disp_tube(bt);
	set_num_v(0,1,0,1,1,0,1,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,1,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,0,0,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,1,1,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,1,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,1,1,0,1);
	disp_tube(bt);
	set_num_v(0,1,0,1,1,0,1,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,1,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,0,0,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,1,1,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,1,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,1,0,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,1,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,0,0,0);
	disp_tube(bt);
	set_num_v(0,1,0,0,0,0,0,1);
	disp_tube(bt);
	set_num_v(1,0,0,0,0,0,1,1);
	disp_tube(bt);
	set_num_v(0,0,0,0,0,1,1,0);
	disp_tube(bt);
	set_num_v(0,0,0,0,1,1,0,0);
	disp_tube(bt);
	set_num_v(0,0,0,1,1,0,0,0);
	disp_tube(bt);
	set_num_v(0,0,1,1,0,0,0,1);
	disp_tube(bt);
	set_num_v(0,1,1,0,0,0,1,0);
	disp_tube(bt);
	set_num_v(1,1,0,0,0,1,0,0);
	disp_tube(bt);
	set_num_v(1,0,0,0,1,0,0,10);
	set_col_v(0,0,0,0,0,0,0,2);
	disp_tube(bt);
	set_num_v(0,0,0,1,0,0,10,10);
	set_col_v(0,0,0,0,0,0,2,2);
	disp_tube(bt);
	set_num_v(0,0,1,0,0,10,10,10);
	set_col_v(0,0,0,0,0,2,2,2);
	disp_tube(bt);
	set_num_v(0,0,1,0,10,10,10,10);
	set_col_v(0,0,0,0,2,2,2,2);
	disp_tube(bt);
	set_num_v(0,1,0,10,10,10,10,10);
	set_col_v(0,0,0,1,1,1,1,1);
	disp_tube(bt);
	set_num_v(1,0,10,10,10,10,10,10);
	set_col_v(0,0,2,2,2,2,2,2);
	disp_tube(bt);
	set_num_v(0,10,10,10,10,10,10,10);
	set_col_v(0,2,2,2,2,2,2,2);
	disp_tube(bt);
	set_num_v(10,10,10,10,10,10,10,10);
	set_col_v(2,2,2,2,2,2,2,2);
	disp_tube(bt*6);


//	set_num_v(10,10,10,10,10,10,10,10);
//	disp_tube(bt);

}

void sg_count_down(void){

	char b1,b2,b3,b4,b5;
	char c1=0,c2=0,c3=0;
	int cnt = 550;
	while(1){
		b1 = cnt / 1000;
		b2 = (cnt / 100)%10;
		b3 = (cnt / 10) %10;
		b4 = cnt % 10;
		if(cnt < 1000){b1 = 0x0f;}
		if(cnt < 100){b2 = 0x0f;c1=1;}
		if(cnt < 10){b3 = 0x0f;;c2=1;}
		b5 = b4 + 3;
		if(b5 > 9){
			 b5-=10;
		}
		set_num_v(10,10,10,10,b2,b3,b4,b5);
		set_col_v(1,1,1,1,c1,c2,c3,0);
		disp_tube(8);
		if(cnt == 0)break;
		cnt--;
	}
	return;
}

void divergence_value(int dtime){
	
	int a = rand() % 2;
	int b = rand() % 10;
	int c = rand() % 10;
	int d = rand() % 10;
	int e = rand() % 10;
	int f = rand() % 10;
	int g = rand() % 10;
		
	scl_2_num(a,10,b,c,d,e,f,g);
	set_col_v(0,1,0,0,0,0,0,0);
	disp_tube(dtime);
		
}