      #define led1 PORTA.f1
      #define led2 PORTA.f2
      #define led3 PORTA.f3
      #define led4 PORTA.f4
      
      
      // working
      //delay in blimk loop
      
      unsigned int cnt;

void interrupt()
     {

     T0CON=0x80;
     TMR0L=1;
     T0CON.TMR0ON=1;
     INTCON=0xA0;
     PORTC=0;
     UCON.f3=0;
     UCFG.f3=1;
      PORTA=0;


     if(cnt==1)
     {
     led1=1;
     TRISA=0;

     
     }
     if(cnt==2)
     {
     led2=1;
     TRISA=0;

     }
      if(cnt==3)
     {
     led3=1;
     TRISA=0;

     }
      if(cnt==4)
     {
     led4=1;
     TRISA=0;

     }

     }

void main()
     {
     OSCCON.f1=1;
     ADCON1=0xff;
      TRISA=0;
     TMR0L=1;
     T0CON=0xc0;
     INTCON=0xA0;
     OSCCON.f4=1;
     OSCCON.f5=1;
     OSCCON.f6=1;
       cnt=0;


      while(1)
      {

       cnt+=1;
      if(cnt==5)cnt=0;
      }


     
     }