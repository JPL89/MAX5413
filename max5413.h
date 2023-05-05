// @File		MAX5413.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		04/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MAX5413_H
#define MAX5413_H

#define MAX5413_CLK             PORTCbits.RC0
#define MAX5413_DIN             PORTCbits.RC1
#define MAX5413_CS              PORTCbits.RC2

#define MAX5413_CLK_TRIS        TRISCbits.RC0
#define MAX5413_DIN_TRIS        TRISCbits.RC1
#define MAX5413_CS_TRIS         TRISCbits.RC2

#define MAX5413_POT_0           0x00
#define MAX5413_POT_1           0x01

void Spi_transfer(unsigned int data)
{
    for(unsigned int mask = 0x100; mask; mask >>=1)
    {
        MAX5413_CLK = 1;
        
        if(data & mask) 
            MAX5413_DIN = 1;
        else MAX5413_DIN = 0;
        
        MAX5413_CLK = 0;
    }
}

void MAX5413_Init(void)
{
    MAX5413_CLK_TRIS = 0;
    MAX5413_DIN_TRIS = 0;
    MAX5413_CS_TRIS = 0;
    
    MAX5413_CS = 1;
}

void MAX5413_Set(unsigned char pot, unsigned char data)
{
    unsigned int address = 0; 
    
    address = pot;
    address <<= 8;
    address |= data;
    
    MAX5413_CS = 0;    
    Spi_transfer(address);    
    MAX5413_CS = 1;
}

#endif
