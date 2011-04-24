//sirc.cpp
//SIRC-12 protocol library by George Hadjikyriacou
//Version 0.1 (4/12/2010)
//License: GPL v3 (http://www.gnu.org/licenses/gpl.html)

#include "WProgram.h"
#include "sirc12.h"

int sirc12::read_pulse(int ir_pin, int ready_pin)
{
    int pulsedata[7];
    int place[]={64,32,16,8,4,2,1};
    digitalWrite(ready_pin, HIGH);

    //1- read pulse from IR
    while (pulseIn(ir_pin, LOW) < 2400) {}
    pulsedata[0] = pulseIn(ir_pin, LOW);
    pulsedata[1] = pulseIn(ir_pin, LOW);
    pulsedata[2] = pulseIn(ir_pin, LOW);
    pulsedata[3] = pulseIn(ir_pin, LOW);
    pulsedata[4] = pulseIn(ir_pin, LOW);
    pulsedata[5] = pulseIn(ir_pin, LOW);
    pulsedata[6] = pulseIn(ir_pin, LOW);
    digitalWrite(ready_pin, LOW);

    //2- Create Binary
    for (int i=0; i<7; i++) {
        if (pulsedata[i] > 1000) {
            pulsedata[i] = 1;
        }
        else {
            if (pulsedata[i] > 400) {
                pulsedata[i] = 0;
            }
            else {
                pulsedata[i] = 2;
            }
        }
    }

    // 2.1- if error found
    for (int i=0; i<7; i++) {
        if (pulsedata[i] > 1) {
            return -1;
        }
    }

    // 3- Binary to decimal convertion
    int bintodec = 0;
    int seed = 1;
    for(int j=0;j<7;j++) {
      if (pulsedata[j] == 1){
          bintodec += seed;
       }
       seed = seed * 2;
    }
 return bintodec;
}

