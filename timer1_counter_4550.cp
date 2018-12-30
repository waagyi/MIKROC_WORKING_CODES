#line 1 "D:/MICROCONTROLLER CODINGS/mikroc/timer1_counter_4550.c"






unsigned int cnt;
 void T1_Delay()
 {

 T1CON.RD16=1;
 T1CON.T1RUN=0;
 T1CON.T1CKPS1=0;
 T1CON.T1CKPS0=0;
 T1CON.T1OSCEN=0;
 T1CON.TMR1CS=0;
 T1CON.T1SYNC=0;

 PIE1.TMR1IE=1;
 PIR1.TMR1IF=0;
 INTCON.GIE=1;
 TMR1H=0xf8;
 TMR1l=0x30;
 }


void main()

 {

 TRISB=0;
 TRISD=0;
 TRISC=0x03;
 INTCON.PEIE=1;
 T1_Delay();
 T1CON.TMR1ON=1;

 while(1)
 {






 }



 }
 void interrupt()
 {
 PORTD=~PORTD;
 T1_Delay();
 T1CON.TMR1ON=1;
 }
