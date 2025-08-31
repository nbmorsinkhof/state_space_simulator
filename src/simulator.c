#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "simulator.h"
#include "physics.h"
#include "integrator.h"

void print_state(float state[], int n){
    for (int i=0; i<n; i++){
        printf("state[%d] = %.4f\n", i, state[i]);
    }
    printf("\n");
}

struct Simulator{
    int dim;
    float *state;
    Model model;
    Integrator integrator;
};


 Simulator* init_simulation(
    Model model,
    Integrator integrator,
    int dim
){
    struct Simulator *simulator = calloc(1, sizeof(struct Simulator));
    simulator = calloc(1, sizeof(Simulator));

    simulator->dim=dim;
    simulator->model=model;
    simulator->integrator=integrator;

    simulator->state = calloc((size_t)dim, sizeof *simulator->state);
    
    if (!simulator){
        printf("init failed");
        return NULL;
    } 
    printf("simulator initialized.");
    return simulator;
}

void run_simulation(
    Simulator *simulator,
    float state_init[],
    float sim_time,
    float dt
){
    int steps = sim_time/dt;
    Model model = simulator->model;
    Integrator integrator = simulator->integrator;
    float *state = simulator->state; 
    int dim = simulator->dim;


    for (int i=0; i<dim; i++){
        state[i] = state_init[i];
    }

    for (int step=0; step<steps; step++){
        integrator(state, model, dt, dim);
        print_state(state, dim);
        usleep(dt*1000000);
    }
}