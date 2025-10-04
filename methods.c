#include "methods.h"
#include <math.h>
//implementar validação de dados depois

//pedir todos os dados juntos para calcular todos os método em sequência?

/*
DÚVIDA:

muda algo quando eu quero que iguale a 0 e depois a 5?

*/

// float problem_teste(float x){
//     printf("Entra na function teste");
//     return 999;
// };

// float (*function_pointer) (float) = problem_teste;

void initial_input(METHOD_DATA *method_data){
    float precision=0;
    unsigned int max_iterations=0;
    float start_point=0;
    float end_point=0;
    float x0=0;
    float x1=0;

    //Requisição de dados ao usuário
    printf("[DADOS] Digite a precisão desejada: ");
    scanf("%f", &precision);
    printf("\n[DADOS] Digite o número máximo de iterações: ");
    scanf("%ud", &max_iterations);

    //Requisição de dados ao usuário - intervalos
    printf("[DADOS] Digite o valor inicial do intervalo: ");
    scanf("%f", &start_point);
    printf("\n[DADOS] Digite o valor final do intervalo: ");
    scanf("%f", &end_point);

    //Requisição de dados ao usuário - intervalos
    printf("[DADOS - SECANTE] Digite o valor da primeira estimativa: ");
    scanf("%f", &x0);
    printf("\n[DADOS - SECANTE] Digite o valor da segunda estimativa: ");
    scanf("%f", &x1);

    method_data->max_iterations=max_iterations;
    method_data->precision_wanted=precision;
    method_data->end_point=end_point;
    method_data->start_point=start_point;
    method_data->x0=x0;
    method_data->x1=x1;

    printf("\nFinaliza o input");

    return;
};

unsigned int method_bisection(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    clock_t initial_time = 0, final_time=0;
    float root_temp = 0, a_temp = data->start_point, b_temp = data->end_point;
    data->method_data[pos].final_precision = data->precision_wanted+1;
    printf("\nExecutando a bissecação...");
    data->method_data[pos].name = "Bissecção";  //salva o nome do método
    //vai ter que ser while
    unsigned int k = 0;
    initial_time = clock(); //marca o tempo inicial
    while(k <= data->max_iterations && data->method_data[pos].final_precision >= data->precision_wanted){
        k++;
        root_temp = (a_temp+b_temp)/2;
        if((function(a_temp)*function(root_temp) < 0))
            b_temp = root_temp;
        else
            a_temp = root_temp;
        
        data->method_data[pos].final_precision = fabs(a_temp-b_temp);
    };
    final_time = clock();
    data->method_data[pos].iterations = k;
    data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);
    data->method_data[pos].root = root_temp;
    return 0;
};

// unsigned int method_secant(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
//     clock_t initial_time = 0, final_time=0;
//     //passa a função por parâmetro
    
//     //salva o nome do método
//     data->method_data[pos].name = "Secante";

//     //cálculos do método
//     data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);

//     data->method_data[pos].root = function(data->x0);

//     if(data->method_data[pos].iterations>data->max_iterations)
//         return 1;

//     return 0;
// };

// unsigned int method_fake_position(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
//     clock_t initial_time = 0, final_time=0;
//     //passa a função por parâmetro

//     //salva o nome do método
//     data->method_data[pos].name = "Falsa posição";

//     //cálculos do método
//     data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);

//     data->method_data[pos].root = function(data->x0);

//     if(data->method_data[pos].iterations>data->max_iterations)
//         return 1;

//     return 0;
// };

// unsigned int method_newton_raphson(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
//     clock_t initial_time = 0, final_time=0;
//     //passa a função por parâmetro

//     //salva o nome do método
//     data->method_data[pos].name = "Newton-Raphson";

//     //cálculos do método
//     data->method_data[pos].time = (double)(final_time - initial_time)/(CLOCKS_PER_SEC*1000);

//     data->method_data[pos].root = function(data->x0);

//     if(data->method_data[pos].iterations>data->max_iterations)
//         return 1;

//     return 0;
// };

void comparative_table(METHOD_DATA *data, float (*function)(float)){
    method_bisection(data,0, function);
    //method_fake_position(data,1,function);
    //method_secant(data,2,function);
    //method_newton_raphson(data,3,function);
    //colocar pointer na struct?
    //printf("");  //pedir para o chat a tabela

    //data->method_data[1].root = function(data->x0);
    printf("Dados para conferencia: ");
    printf("Nome: %s\nRaiz: %f\t Max iteraçoes: %u\t Tempo(ms): %lf\t Precisao %f",data->method_data[0].name, data->method_data[0].root,data->method_data[0].iterations,data->method_data[0].time,data->method_data[0].final_precision);
};