/*
 * divergence.h
 *
 * Created: 2012/2/26 下午 10:35:42
 *  Author: ATI
 */ 
#include "nixie-test.h"

//宣告程式
void sg_count_down(void);
void sg_count_up(void);
void sg_lr_col3(void);
void sg_lr_colw(void);
void sg_rl_colw(void);
void sg_lr_col(int bt);
void sg_rl_col(int bt);
void sg_rl_num0(void);
void sg_lr_num1(void);
void sg_sc01(void);
void sg_sc012(void);
void scl_num(int ct,char flg);
void scl_2_num(char a,char b,char c,char d,char e,char f,char g,char h);
void scl_2_num_tr(char a,char b,char c,char d,char e,char f,char g,char h);
void divergence_mode(void);
void divergence_value(int dtime);