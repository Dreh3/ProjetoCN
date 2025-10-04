#ifndef METHODS_H
#define METHODS_H

#include <time.h>
#include <stdio.h>


#define number_of_methods 4
typedef struct METHOD{
    float root;
    unsigned int iterations;
    float final_precision;
    char *name;
    double time;
}METHOD_;

typedef struct DATA{
    METHOD_ method_data[number_of_methods];
    float precision_wanted;
    unsigned int max_iterations;
    float start_point;
    float end_point;
    float x0;
    float x1;
}METHOD_DATA;

/*
Retirar retornos
*/

unsigned int method_bisection(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
// unsigned int method_false_position(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
// unsigned int method_newton_raphson(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
// unsigned int method_secant(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void initial_input(METHOD_DATA *method_data);
void comparative_table(METHOD_DATA *method_data,float (*function)(float)); //chama todas as funções e monta a tabela

#endif