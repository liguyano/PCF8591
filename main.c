
#include "MAtrix_key.h"
#include "AD2DA.h"
#include "SSS.h"
#include <math.h>
unsigned char yu = 1;/*用于记录月份*/
unsigned char code SMG_duanma[18]=
{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90,0x88,0x80,0xc6,0xc0,0x86,0x8e,
0xbf,0x7f};/*用于数码管段选*/
void SelectHC573(unsigned char channel)/*74HC573锁存器*/
{
    switch(channel)
    {
        /*
         * &0x1f 将前三位置0
         * | 0x80 将第一位置1
         * | 0xa0 1010 0000
         * */

        case 4:
            P2 = (P2 & 0x1f) | 0x80;
            break;
        case 5:
            P2 = (P2 & 0x1f) | 0xa0;
            break;
        case 6:
            P2 = (P2 & 0x1f)| 0xc0;//1100
            break;
        case 7:
            P2 = (P2 & 0x1f) | 0xe0;
            break;
    }
}

void DIAPlaySMG_Bit(unsigned char value, unsigned char pos)/*数码管显示*/
{
    P0 = 0xff;
    /*段选*/
    SelectHC573(6);
    P0 = 0x01 << pos;
    P2&=0x1f;
    /*位选*/
    SelectHC573(7);
    P0 = value;
    P2&=0x1f;
}

void DelaySMG(unsigned int t)/*数码管延时函数*/
{
    while(t--);
}
void showMoreNUm(unsigned char num,unsigned char start)
{
    unsigned char h,t=0;
    h=num/100;
    DIAPlaySMG_Bit(SMG_duanma[h],start+0);
    DelaySMG(50);
    num=num%100;
    t=num/10;
    DIAPlaySMG_Bit(SMG_duanma[t],start+1);DelaySMG(50);
    num%=10;
    DIAPlaySMG_Bit(SMG_duanma[num],start+2);DelaySMG(50);

}
void showIntNUm(unsigned int num)
{
    unsigned char i,s;
    for (i=1;i<6;i++)
    {
        s=num/ pow(10.0,5.0-i*1.0) ;
        num %= (unsigned int ) pow(10.0,5.0-i);
        DIAPlaySMG_Bit(SMG_duanma[s],i-1);
        Delay(10);
    }
}
/**
 * @brief get which key of that raw has been clicked;
 * @return means which one
 * */


void main()
{unsigned char t1;

    BuzzWarning();
    SelectHC573(5);
    P0&= 0xBF;
    P2&=0x1f;

    t1= read_AD(0x43);
    while (1)
    {
        t1= read_AD(0x43);
        showMoreNUm(t1,2);
        Delay(100);
    }
}
void time0() interrupt NUM1
{

}