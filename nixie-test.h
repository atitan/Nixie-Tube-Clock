/*
 * nixie_test.h
 *
 * Created: 2012/2/26 下午 10:33:03
 *  Author: ATI
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>

//子程式宣告
void day_time(void);
void timer_mode(void);
void read_rtc_time(void);
void set_num_v(	char buff1,char buff2,char buff3,char buff4,
				char buff5,char buff6,char buff7,char buff8);
void set_col_v(	char buff1,char buff2,char buff3,char buff4,
				char buff5,char buff6,char buff7,char buff8);
void disp_tube(int count);
void time_tuning(void);

