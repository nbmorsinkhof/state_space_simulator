#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "physics.h"
#include "integrator.h"

#include "time.h"


typedef struct Simulator Simulator;

Simulator* init_simulation(
    Model model,
    Integrator integrator,
    int dim
);

void run_simulation(
    Simulator *simulator,
    float state_initial[],
    float sim_time,
    float dt
);

void end_simulation();
#endif