#include <stdio.h>
#include "physics.h"

void simple_model(float state[], float ddt_state[]){
    ddt_state[0] = -2*state[0] + state[1]*state[0];
    ddt_state[1] = -1*state[1];
}