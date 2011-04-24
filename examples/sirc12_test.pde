//SIRC-12 remote control driver by George Hadjikyriacou
//Version 0.1 (4/12/2010)
//License: GPL v3 (http://www.gnu.org/licenses/gpl.html)

#include <sirc12.h>

int ir_pin=2 ,ready_pin=13;
sirc12 remote;

void setup(){
  pinMode(ir_pin, INPUT);
  pinMode(ready_pin, OUTPUT);
  Serial.begin(9600);
}
void loop(){

  int code = remote.read_pulse(ir_pin, ready_pin);

  Serial.println("--------Start--------");
  Serial.print("SIRC code:");
  Serial.println(code);
  Serial.println("--------Stop--------");
}

