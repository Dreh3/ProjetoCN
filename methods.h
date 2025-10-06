#ifndef METHODS_H
#define METHODS_H

#ifdef _WIN32 // Verifica se o sistema é Windows
    #define LIMPA_TELA system("cls");
#else // Para outros sistemas (Linux, macOS, etc.)
    #define LIMPA_TELA system("clear");
#endif

#include <time.h>
#include <stdio.h>
#include <sys\timeb.h>
#include <stdlib.h> 
#include <windows.h>


#define number_of_methods 4
typedef struct METHOD{
    float root;
    unsigned int iterations;
    float final_precision;
    char *name;
    float time;
}METHOD_;

typedef struct DATA{
    METHOD_ method_data[number_of_methods];
    float precision_wanted;
    unsigned int max_iterations;
    //float start_point;
    //float end_point;
    //float x0;
    //float x1;
}METHOD_DATA;

/*
Retirar retornos
*/

unsigned int method_bisection(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
unsigned int method_false_position(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
unsigned int method_newton_raphson(METHOD_DATA *method_data, unsigned int pos, float (*function)(float),float (*d_function)(float));
// unsigned int method_secant(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void initial_input(METHOD_DATA *method_data);
void comparative_table(METHOD_DATA *method_data,float (*function)(float),float (*d_function)(float)); //chama todas as funções e monta a tabela

#endif