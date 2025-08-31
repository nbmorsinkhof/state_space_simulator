#include <stdio.h>

#include "simulator.h"
#include "physics.h"
#include "integrator.h"

int main(void){
    int dim = 2;
    /* init simulator*/
    Simulator* simulator = init_simulation(
        simple_model,
        euler,
        dim
    );
    float state_initial[] = {5.0, 2.0};
    float sim_time = 10.0;
    float dt = 0.1;
    run_simulation(
        simulator,
        state_initial,
        sim_time,
        dt
    );

    return 0;
}