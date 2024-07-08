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
void play_note(int note){
 
  buzzer_set_period(note); __delay_cycles(4000000);
  buzzer_set_period(0); __delay_cycles(4000000);
}

void play_song(int notes[]){
  int length = sizeof(notes) / sizeof(notes[0]);
  for(int i = 0; i < length; i++){
    play_note(notes[i]);
  }
}

  
int main(void) {
  WDTCTL = WDTPW + WDTHOLD;
  button_init();
  buzzer_init();
  
  int A = 2272;
  int E = 3024;
  int E4 = 1516;
  int D = 1702;
  int G = 2551;
  int B = 2028;
  int F = 2863;
  int C3 = 3816;

  int notes[5] = {A,E,E4,D,G};
  play_song(notes);
}
