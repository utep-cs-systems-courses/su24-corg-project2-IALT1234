#include <msp430.h>
#include "../demos/timerLib/libTimer.h"
#include "../demos/11-buzzer/buzzer.h"
#include "../demos/1-led/led.h"

#define BUTTON1 BIT0
#define BUTTON2 BIT2
#define BUTTON3 BIT3

void button_init(){
  P2DIR &= ~(BUTTON1 | BUTTON2 | BUTTON3);
  P2REN |= (BUTTON1 | BUTTON2 | BUTTON3);
  P2OUT |= (BUTTON1 | BUTTON2 | BUTTON3);  
  
}
int button1_pressed(){
  return !(P2IN & BUTTON1);
}
int button2_pressed(){
  return !(P2IN & BUTTON2);
}
int button3_pressed(){
  return !(P2IN & BUTTON3);
}
