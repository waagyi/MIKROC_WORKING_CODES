void init()
{
 T0CON.TMR0ON=1; //tmro on
 T0CON.T08BIT=0; //16 bit mode
 T0CON.T0CS=0; //internal clocl xource
 T0CON.f4=1; //increase in low to high
 T0CON.f3=1; //psa   not   assigned
 T0CON.f2=0; //psa assigned to 2 time (psa=000)
 T0CON.f1=0;
 T0CON.f0=0;

}


void main()
{
init();

ADCON1=0x0f;
RCON.f7=1;
TRISB=0;
PORTB=0;
TMR0l=200;
init();
INTCON=0x00;
INTCON.T0IE=1 ;//toie
INTCON.GIE=1; //gie

    for(;;)
    {

    }

}

 void interrupt()
 {
 INTCON.T0IE=0;
 INTCON.T0IF=0;
 PORTB=~PORTB;
 INTCON.T0IE=1;

 }
 
