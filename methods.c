#include "methods.h"

//implementar validação de dados depois

//pedir todos os dados juntos para calcular todos os método em sequência?

void initial_input(METHOD_DATA *method_data){
    float precision;
    float max_iterations;
    float start_point;
    float end_point;
    float x0;
    float x1;

    //Requisição de dados ao usuário
    printf("[DADOS] Digite a precisão desejada: ");
    scanf("%d", precision);
    printf("\n[DADOS] Digite o número máximo de iterações: ");
    scanf("%d", max_iterations);

    //Requisição de dados ao usuário - intervalos
    printf("[DADOS] Digite o valor inicial do intervalo: ");
    scanf("%d", start_point);
    printf("\n[DADOS] Digite o valor final do intervalo: ");
    scanf("%d", end_point);

    //Requisição de dados ao usuário - intervalos
    printf("[DADOS - SECANTE] Digite o valor da primeira estimativa: ");
    scanf("%d", x0);
    printf("\n[DADOS - SECANTE] Digite o valor da segunda estimativa: ");
    scanf("%d", x1);

    method_data->max_iterations=max_iterations;
    method_data->precision_wanted=precision;
    method_data->end_point=end_point;
    method_data->start_point=start_point;
    method_data->x0=x0;
    method_data->x1=x1;
};

unsigned int method_bisection(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    clock_t initial_time = 0, final_time=0;
    //passa a função por parâmetro

    //salva o nome do método
    data->method_data[pos].name = "Bissecção";

    //cálculos do método

    data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);
};

unsigned int method_secant(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    clock_t initial_time = 0, final_time=0;
    //passa a função por parâmetro

    //salva o nome do método
    data->method_data[pos].name = "Secante";

    //cálculos do método
    data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);
};

unsigned int method_fake_position(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    clock_t initial_time = 0, final_time=0;
    //passa a função por parâmetro

    //salva o nome do método
    data->method_data[pos].name = "Falsa posição";

    //cálculos do método
    data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);
};

unsigned int method_newton_raphson(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    clock_t initial_time = 0, final_time=0;
    //passa a função por parâmetro

    //salva o nome do método
    data->method_data[pos].name = "Newton-Raphson";

    //cálculos do método
    data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);
};

void comparative_table(METHOD_DATA *data, float (*function)(float)){
    method_bisection(&data,0,function_pointer);
    method_fake_position(&data,1,function_pointer);
    method_secant(&data,2,function_pointer);
    method_newton_raphson(&data,3,function_pointer);
    //colocar pointer na struct?
    printf("");  //pedir para o chat a tabela

};