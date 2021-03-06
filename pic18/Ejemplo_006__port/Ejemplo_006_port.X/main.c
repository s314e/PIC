/*
 * File:   main.c
 * Author: Mauricio
 *
 * Created on 4 de enero de 2017, 2:30
 
 Para usar el codigo usar solo una de las funciones comentadas en el main,se recomienda el uso de osciloscopio para
 visualizar las ondas
1- TestCCP4 ,Varia el ciclo util en rg3 con los pulsadores
2- AutoTestCCP4 Varia automaticamente el ciclo util de 0-900
     ________________
    |                |
    |             RA5|<---external Pull-up 15k and buttom to ground
    |                |
    |                |       
    |             RB0|<---external Pull-up 15k and buttom to ground                    
    |                |       
    |           PORTD|-->LEDS
    |            RG3 |-->LED externo +220ohm
    |            MCLR|<---external Pull-up 4.7k and buttom to ground 
    |________________|
 */

#include <xc.h>
#include "PicConf.h"
#include "Modules.h"
#include"Ejemplo.h"


void main(void)
{
  InitConf(); //incia configuracion de reloj y puertos digitales
  
  ejemplo();
  TestInterrupt();
  while(1)
  {
    
     
  }
  return;
}



void interrupt portb_interrupt()
{
 INTCON&=~(BIT7|BIT6); //Disabled the global interrupts 
 //timer2 interrupt  0,010S
 if(INTCON&0X02)  
 {
  INTCON&=~0X02;
  LATD++;
  
 }
 
 INTCON|=(BIT7|BIT6); //global interrupt enable
}

