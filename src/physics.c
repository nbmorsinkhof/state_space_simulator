#include <stdio.h>
#include <math.h>
#include "physics.h"

void simple_model(float state[], float ddt_state[]){
    ddt_state[0] = -2*state[0] + state[1]*state[0];
    ddt_state[1] = -1*state[1];
}

void pendulum(float state[], float ddt_state[]){
    float g = 9.81;
    float l = 1;
    ddt_state[0] = state[1];
    ddt_state[1] = -(g/l)*sin(state[0]);
}