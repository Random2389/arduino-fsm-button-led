//SIGNALS AND PEDESTRIAN BUTTON
#define RED_BIT 3
#define YELLOW_BIT 4 
#define GREEN_BIT 5
#define pedbutton 2

//TIMINGS IN MS

#define TIME_LONG 5000
#define TIME_SHORT 2000
#define TIME_PREP 1000

//MASK FOR ALL LED

#define LED_MASK ((1<<RED_BIT) | (1<<YELLOW_BIT) | (1<<GREEN_BIT))
enum State{
    RED,RED_YELLOW,YELLOW,GREEN
};

State currentstate=RED;

void setup(){
    DDRB |= LED_MASK;
    PORTB &= ~LED_MASK;
    PORTB |= (1<<RED_BIT);
    DDRD &=~(1<<pedbutton);
    PORTD |=(1<<pedbutton); 
    
//INTERUPT CONFIG
    EICRA |=(1<<ISC01);
    EICRA&=~(1<<ISC00);
    EIMSK |=(1<<INT0);
    sei();    
     
}
volatile bool pedwait=false;
unsigned long currentTime=0;
unsigned long lastTime=0;

void loop(){
    currentTime=millis();
   
     
    switch(currentstate){
    
    case RED:          if(currentTime-lastTime>=TIME_LONG){
          PORTB&=~LED_MASK;
          PORTB |=(1<<YELLOW_BIT);
          currentstate=RED_YELLOW;
          lastTime=currentTime;
          }
          break;
     case RED_YELLOW:
       if(currentTime-lastTime>=TIME_PREP){
         pedwait=false;
         PORTB&=~LED_MASK;
         PORTB |= (1<<GREEN_BIT);
         currentstate=GREEN;
         lastTime=currentTime;
         }
         break;
         case GREEN:
                               if((currentTime-lastTime>=TIME_LONG)||(pedwait==true && currentTime-lastTime>=TIME_SHORT))
            {
            PORTB&=~LED_MASK;
            PORTB|=(1<<YELLOW_BIT);
            currentstate=YELLOW;
            lastTime=currentTime;
            pedwait=false; 
            }
            break;
        
        case YELLOW:                    
            if(currentTime-lastTime>=TIME_SHORT){
           PORTB&=~LED_MASK;       
           PORTB |=(1<<RED_BIT);  
           currentstate=RED;
           lastTime=currentTime;}
           break;
     
    
   default:
        currentstate=RED;
  }      
}
ISR(INT0_vect){
    pedwait=true;
}

