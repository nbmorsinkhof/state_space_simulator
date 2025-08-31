#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "physics.h"

typedef void (*Integrator)(float state[], Model model, float dt, int dim);


void euler(float state[], Model, float dt, int dim);

#endif