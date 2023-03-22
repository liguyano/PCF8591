
#include "AD2DA.h"
//
// Created by kurum on 3/1/2023.
//
void Delay1000ms()		//@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    _nop_();
    i = 30;
    j = 107;
    k = 115;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}
void BuzzWarning(){

    P2 = (P2 & 0x1f) | 0xa0;
    P0|=40;
Delay1000ms();
    P2 = (P2 & 0x1f) | 0xa0;
    P0&= 0xBF;
    P2&=0x1f;
}
void writeAD(unsigned char addr) {
    uchar ar=0;
    one_start();
    one_sendByte(0x90);
    ar=I2C_recv_ack();

    one_sendByte(0x41);
    I2C_recv_ack();
    one_sendByte(addr);
    I2C_recv_ack();
    one_stop();
}

unsigned char read_AD(unsigned char addr) {
    unsigned char result,ar;
    one_start();
    one_sendByte(0x90);
    ar=I2C_recv_ack();
    if (ar)
    {
        BuzzWarning();
        return 0x01;
    }
    one_sendByte(addr);
    ar=I2C_recv_ack();
    if (ar)
    {
        BuzzWarning();
        return 0x02;
    }
    one_start();
    one_sendByte(0x91);
    ar=I2C_recv_ack();
    if (ar)
    {
        BuzzWarning();
        return 0x03;
    }
    result=I2C_ReceiveByte();
    I2C_send_ac(1);
    one_stop();
    return result;
}
