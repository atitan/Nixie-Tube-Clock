void i2c_init(long bitrate);

void i2c_2_write(unsigned char addr,unsigned char* data, unsigned char bytecnt);

void i2c_2_read(unsigned char addr,	unsigned char* data,unsigned char bytecnt);

char i2c_wait(void);
void i2c_start();
void i2c_stop();


char i2c_wait(void);
void i2c_start();
void i2c_stop();
void i2c_writebyte(unsigned char dat);
unsigned char i2c_readbyte(char noack);
