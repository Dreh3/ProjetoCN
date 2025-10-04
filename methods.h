#include <time.h>

#define number_of_methods 4
struct METHOD{
    float root;
    unsigned int iterations;
    float final_precision;
    char *name;
    clock_t time;
};

typedef struct DATA{
    METHOD method_data[number_of_methods];
    float precision_wanted;
    unsigned int max_iterations;
    float start_point;
    float end_point;
    float x0;
    float x1;
}METHOD_DATA;

// typedef struct METHODS{
//     struct METHOD Secant;
//     struct METHOD Bisection;
//     struct METHOD Newton_Raphson;
//     struct METHOD False_position;
// }METHOD_DATA;


//METHOD METHOD_DATA[number_of_methods];
float (*function_pointer) (float);

//implementa as duas funções e passa elas por parâmetro;
//function_pointer = &nome_da_função;

//função para comparar métodos e construir tabela

/*
Retirar retornos
*/

unsigned int method_bisection(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
unsigned int method_false_position(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
unsigned int method_newton_raphson(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
unsigned int method_secant(METHOD_DATA *method_data, unsigned int pos, float (*function)(float));
void initial_input(METHOD_DATA *method_data);
void comparative_table(METHOD_DATA *method_data, float (*function)(float)); //chama todas as funções e monta a tabela

