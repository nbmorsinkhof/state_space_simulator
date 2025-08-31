#include <stdio.h>
#include "integrator.h"
#include "physics.h"



void euler(float state[], Model model, float dt, int dim){
    float ddt_state[dim];
    model(state, ddt_state);
    
    for (int i=0; i<dim; i++){
        state[i] = state[i] + dt*ddt_state[i];
    }
}