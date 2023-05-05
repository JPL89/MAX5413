// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "max5413.h"

void main(void)
{
    __delay_ms(500);

    PIC18F2520();   
    
    MAX5413_Init();
         
    MAX5413_Set(0, 78);
    
    MAX5413_Set(1, 184);
    
    while(1)
    {               
        
    }
    
    return;
}