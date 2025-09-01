#ifndef PHYSICS_H
#define PHYSICS_H


/* Model funcion definition */
typedef void (*Model)(float state[], float ddt_state[]);   // the API shape



/* Models*/
void simple_model(float state[], float ddt_state[]);

void pendulum(float state[], float ddt_state[]);

#endif