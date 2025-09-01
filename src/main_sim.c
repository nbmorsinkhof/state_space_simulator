#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include "simulator.h"
#include "physics.h"
#include "integrator.h"



typedef struct {
    Simulator* simulator;
    float *state_initial;
    float sim_time;
    float dt;
} Simargs;

void *runThread(void* arg){
    Simargs* args = (Simargs*) arg;
    
    run_simulation(
        args->simulator,
        (args->state_initial),
        args->sim_time,
        args->dt
    );
    return NULL;
}

int main(void){

    Simargs* sim_args = malloc(sizeof(Simargs));
    /* init simulator*/
    int dim = 2;
    sim_args->simulator = init_simulation(
        pendulum,
        euler,
        dim
    );
    float state_initial[] = {-0.1*3.14, 0};
    sim_args->state_initial = state_initial;
    sim_args->sim_time = 10.0;
    sim_args->dt = 0.01;


    pthread_t sim_thread;
    pthread_create(&sim_thread, NULL, runThread, sim_args);
    pthread_join(sim_thread, NULL);

    free(sim_args);
    return 0;
}