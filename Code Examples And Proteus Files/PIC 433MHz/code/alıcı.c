/*
The simplest ASK-RF Module Usage Example for CCS C Compiler.
Copyright (c) 2016 Mesut Saygýoðlu
  
It is created to be used by a PIC16f628A.If you use a different PIC, you need 
to need to change the hardware RS-232 pins for respect to PIC you use.

*/
#include <16F628A.h>
#fuses HS,NOWDT,NOPROTECT, NOMCLR,NOLVP,NOPUT,NOCPD
#use delay (clock=16000000) 
#use rs232(baud=1200, xmit=PIN_B2, rcv=PIN_B1,stop=1, parity=N) 

 char xdata;
 int loopflag=0;
 
 #INT_RDA
 void haberlesmekesmesi()
 {
 disable_interrupts(int_rda);
 
   if(getch()=='M') 
    {
      while(getch()=='M') {}
             xdata=getch();
    }
     loopflag=2; 
     enable_interrupts(int_rda);
     enable_interrupts(GLOBAL);
 }
 
 void main()
 {
 
 setup_timer_1(T1_DISABLED); 
 setup_timer_2(T2_DISABLED,0,1); 
 setup_CCP1(CCP_OFF);  
 set_tris_a(0x00); 
 set_tris_b(0x02); 
 output_a(0x00);
 output_high(pin_b4); 
 
  while(1)
    {
      enable_interrupts(int_rda);
      enable_interrupts(GLOBAL);
 
     if (loopflag>1)
       { 
         if(xdata=='A' )
            {
              output_high(pin_a3);
              output_low(pin_a2);
            }

         if(xdata=='B' )
            {
               output_high(pin_a2);
               output_low(pin_a3);
            }
        }
     }
  }


