//sirc.h
//SIRC-12 protocol library by George Hadjikyriacou
//Version 0.1 (4/12/2010)
//License: GPL v3 (http://www.gnu.org/licenses/gpl.html)

#ifndef sirc12_h
#define sirc12_h

#include "WProgram.h"

class sirc12
{
public:
    int read_pulse(int ir_pin,int ready_pin);
};
#endif
