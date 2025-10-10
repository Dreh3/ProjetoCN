#ifndef METHODS_H
#define METHODS_H

//Para poder limpar a tela
#ifdef _WIN32 // Verifica se o sistema é Windows
    #define LIMPA_TELA system("cls");
#else // Para outros sistemas (Linux, macOS, etc.)
    #define LIMPA_TELA system("clear");
#endif

//Inclusão de biblioteca necessárias
#include <time.h>
#include <stdio.h>
#include <sys\timeb.h>
#include <stdlib.h> 
#include <windows.h>
#include <math.h>

//Estrutura para armazenar os dados específicos de cada método
#define number_of_methods 4
typedef struct METHOD{
    float root;
    unsigned int iterations;
    float final_precision;
    char *name;
    float time;
}METHOD_;

//Estrutura para salvar os dados de todos os métodos e dados em comum
typedef struct DATA{
    METHOD_ method_data[number_of_methods];
    float precision_wanted;
    unsigned int max_iterations;
}METHOD_DATA;


//Protótipos das funções
void method_bisection(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void method_false_position(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void method_newton_raphson(METHOD_DATA *method_data, unsigned int pos, float (*function)(float),float (*d_function)(float));
void method_secant(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void initial_input(METHOD_DATA *method_data);
void comparative_table(METHOD_DATA *method_data,float (*function)(float),float (*d_function)(float)); //Chama todas as funções e monta a tabela

#endif