//
// Created by kurum on 3/1/2023.
//

#ifndef CMAKELISTS_TXT_AD2DA_H
#define CMAKELISTS_TXT_AD2DA_H
#include <I2C.h>
#include <INTRINS.H>
void writeAD(unsigned char addr);
unsigned char read_AD(unsigned char addr);
void BuzzWarning();


#endif //CMAKELISTS_TXT_AD2DA_H
