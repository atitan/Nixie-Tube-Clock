//----------------------------------------------------------
// I2C用関数 by Takuya Matsubara
//----------------------------------------------------------
#include <avr/io.h>

char i2c_wait(void);
void i2c_start();
void i2c_stop();
void i2c_writebyte(unsigned char dat);
unsigned char i2c_readbyte(char noack);

#ifndef F_CPU
#define F_CPU    8000000    //CPUクロック周波数 8MHz
#endif

//----------------------------------------------------------
// I2C初期化
void i2c_init(long bitrate)
{
    TWSR = 0;    //プリスケーラ値 CLK/1 
    TWBR = ((F_CPU / bitrate) - 16) / (2*1);  // SCLの周波数
    TWCR = (1 << TWEN);
}

//----------------------------------------------------------
// 通信終了までウエイト
// 戻り値：0=正常 / -1=エラー
char i2c_wait(void)
{
    while((TWCR & (1 << TWINT))==0){
    }

    switch(TWSR)
    {
    case 0x20:    //TW_MT_SLA_NACK
    case 0x58:    //TW_MR_DATA_NACK
    case 0x38:    //TW_MT_ARB_LOST
        return(-1); // エラー発生
        break;
    default:
        break;
    }
    return(0);      // 正常終了
}

//----------------------------------------------------------
// 通信開始
void i2c_start()
{
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    i2c_wait();
}

//----------------------------------------------------------
// 通信終了
void i2c_stop()
{
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

//----------------------------------------------------------
// 1バイト送信
void i2c_writebyte(unsigned char dat)
{
    TWDR = dat;
    TWCR = (1<<TWINT) | (1<<TWEN);
    i2c_wait();
}

//----------------------------------------------------------
// 1バイト受信
unsigned char i2c_readbyte(char noack)
{
    if (noack) {
       TWCR = (1<<TWINT)|(1<<TWEN);    //NO ACK
    } else {
       TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);    //ACK
    }
    i2c_wait();
    return (TWDR);
}

//----------------------------------------------------------
// EEPROM書き込み
// 引数（スレーブアドレス,アドレス,データ,バイト数）
void i2c_2_write(
    unsigned char addr,
    unsigned char* data,
    unsigned char bytecnt)
{
    i2c_start();
    i2c_writebyte(0xD0);     // SLA + W
    i2c_writebyte(addr);    // address(high 8bits)
    while(bytecnt > 0){
        i2c_writebyte(*data++);
        bytecnt--;
    }
    i2c_stop();
}

//----------------------------------------------------------
// EEPROM読み込み
// 引数（スレーブアドレス,アドレス,データ,バイト数）
void i2c_2_read(
    unsigned char addr,
    unsigned char* data, unsigned char bytecnt)
{
    i2c_start();
    i2c_writebyte(0xD0);      // SLA + W 
    i2c_writebyte(addr);     // address(high 8bits)
    i2c_start();
    i2c_writebyte(0xD1);  // SLA + R 
    while(bytecnt > 0){
        *data++ = i2c_readbyte(bytecnt == 1);
        bytecnt--;
    }
    i2c_stop();
}
