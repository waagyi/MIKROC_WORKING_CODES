//Timer1 as timer

//under development

//working

unsigned int cnt;
 void T1_Delay()
      {

       T1CON.RD16=1;    //in one 16 bit mode
       T1CON.T1RUN=0;   //clock comes from external
       T1CON.T1CKPS1=0; //i/p clock ps 1
       T1CON.T1CKPS0=0;
       T1CON.T1OSCEN=0;//osc shutoff
       T1CON.TMR1CS=0;  //rc0 ip as clk on fsc/4 edge
       T1CON.T1SYNC=0;  // sync with external clk

       PIE1.TMR1IE=1;
       PIR1.TMR1IF=0;
       INTCON.GIE=1;
       TMR1H=0xf8;
       TMR1l=0x30;
      }


void main()

     {
       //OSCCON=0xff   ;
       TRISB=0;
       TRISD=0;
       TRISC=0x03; //rc0 as input
       INTCON.PEIE=1;
        T1_Delay();
       T1CON.TMR1ON=1;

  while(1)
       {


     //  TMR1H=0;
//       TMR1L=0;

  
       }



       }
       void interrupt()
       {
          PORTD=~PORTD;
           T1_Delay();
          T1CON.TMR1ON=1;
       }



