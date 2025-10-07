//Inclusão de biblioteca necessárias

#include "methods.h"
#include <math.h>

//Variáveis para cálculo de tempo
LARGE_INTEGER freq, start, end;
double elapsed_ns, elapsed_ps;

void initial_input(METHOD_DATA *method_data){

    //Requisição de dados ao usuário
    printf("\n\tDados iniciais necessários\n");
    printf("\nDigite a precisão desejada: ");
    scanf("%f", &method_data->precision_wanted);
    printf("\nDigite o número máximo de iterações: ");
    scanf("%ud", &method_data->max_iterations);

    return;
};

void method_bisection(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    float root_temp = 0, a_temp = 0, b_temp = 0;
    data->method_data[pos].final_precision = data->precision_wanted+1;
    data->method_data[pos].name = "Bisseccao";  //salva o nome do método

    printf("\n\tExecutando o método da bissecção...\n");
    
    //Requisição de dados ao usuário - intervalos
    printf("\nDigite o valor inicial do intervalo: ");
    scanf("%f", &a_temp);
    printf("\nDigite o valor final do intervalo: ");
    scanf("%f", &b_temp);
    
    unsigned int k = 0;

    //tempo
    // Frequência do contador de alta resolução
    QueryPerformanceFrequency(&freq);

    // Marca o tempo inicial
    QueryPerformanceCounter(&start);
    
    while(k <= data->max_iterations && data->method_data[pos].final_precision >= data->precision_wanted){
        k++;
        root_temp = (a_temp+b_temp)/2;
        if((function(a_temp)*function(root_temp) < 0))                      //Verifica qual metade está com a raiz
            b_temp = root_temp;
        else
            a_temp = root_temp;
        
        data->method_data[pos].final_precision = fabs(function(root_temp)); //Atualiza a precisão
        //time(&final_time);
    };

    // Marca o tempo final
    QueryPerformanceCounter(&end);

    // Tempo em nanosegundos
    elapsed_ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / (double)freq.QuadPart;

    data->method_data[pos].iterations = k;          //Salva o número de iterações
    
    data->method_data[pos].time = elapsed_ns/1000; //Salva o tempo em microsegundos
    data->method_data[pos].root = root_temp;       //Salva a raiz encontrada
    return;
};

void method_fake_position(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    float root_temp = 0, a_temp = 0, b_temp = 0;
    data->method_data[pos].final_precision = data->precision_wanted+1;
    data->method_data[pos].name = "Falsa posicao";
    
    printf("\n\tExecutando o método da Falsa Posição...\n");
    
    //requisição de dados ao usuário
    printf("\nDigite o valor inicial do intervalo: ");
    scanf("%f", &a_temp);
    printf("\nDigite o valor final do intervalo: ");
    scanf("%f", &b_temp);
    
    unsigned int k = 0;

    // Frequência do contador de alta resolução
    QueryPerformanceFrequency(&freq);

    // Marca o tempo inicial
    QueryPerformanceCounter(&start);

    while(k <= data->max_iterations && data->method_data[pos].final_precision >= data->precision_wanted){
        k++;
        root_temp = (a_temp*(function(b_temp)) - b_temp*function(a_temp))/(function(b_temp)-function(a_temp));
        if((function(a_temp)*function(root_temp) < 0))
            b_temp = root_temp;
        else
            a_temp = root_temp;
        
        data->method_data[pos].final_precision = fabs(function(root_temp));
        data->method_data[pos].iterations = k;
    };
    

    // Marca o tempo final
    QueryPerformanceCounter(&end);

    // Tempo em nanosegundos
    elapsed_ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / (double)freq.QuadPart;
    
    data->method_data[pos].time = elapsed_ns/1000; //Salva o tempo em microsegundos
    data->method_data[pos].root = root_temp;

    return;
};

void method_newton_raphson(METHOD_DATA *data, unsigned int pos, float (*function)(float), float (*d_function)(float)){
    // clock_t initial_time = 0, final_time=0;
    struct timeb initial_time, final_time;
    float root_temp = 0;
    data->method_data[pos].final_precision = data->precision_wanted+1;
    data->method_data[pos].name = "Newton-Raphson";
    
    printf("\n\tExecutando o método de Newton-Raphson...\n");
    
    //requisição de dados ao usuário
    printf("\nDigite o valor inicial: ");
    scanf("%f", &root_temp);

    //cálculos do método
    unsigned int k = 0;
    
    //tempo
    // Frequência do contador de alta resolução
    QueryPerformanceFrequency(&freq);

    // Marca o tempo inicial
    QueryPerformanceCounter(&start);
    
    while(k <= data->max_iterations && data->method_data[pos].final_precision >= data->precision_wanted){
        k++;
        //implementação do método
        root_temp = root_temp - (function(root_temp)/d_function(root_temp));
        data->method_data[pos].final_precision = fabs(function(root_temp));
        data->method_data[pos].iterations = k;
    };
    // Marca o tempo final
    QueryPerformanceCounter(&end);

    // Tempo em nanosegundos
    elapsed_ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / (double)freq.QuadPart;

    //printf("\nGastou aproximadamente %.0f ns\n", elapsed_ns);

    data->method_data[pos].time = elapsed_ns/1000; //Salva o tempo em microsegundos
    
    data->method_data[pos].root = root_temp;

    return;
};

void method_secant(METHOD_DATA *data, unsigned int pos, float (*function)(float)){
    float root_temp = 0, x0 = 0, x1 = 0;
    data->method_data[pos].final_precision = data->precision_wanted+1;
    data->method_data[pos].name = "Secante";
    
    printf("\n\tExecutando o método da Secante...\n");
    
    //requisição de dados ao usuário
    printf("\nDigite o valor da primeira estimativa: ");
    scanf("%f", &x0);
    printf("\nDigite o valor da segunda estimativa: ");
    scanf("%f", &x1);
    
    
    unsigned int k = 0;
    //tempo
    // Frequência do contador de alta resolução
    QueryPerformanceFrequency(&freq);

    // Marca o tempo inicial
    QueryPerformanceCounter(&start);

    while(k <= data->max_iterations && data->method_data[pos].final_precision >= data->precision_wanted){
        k++;
        
        root_temp = (x0*function(x1)-x1*function(x0))/(function(x1)-function(x0));
        x0 = x1;
        x1 = root_temp;

        data->method_data[pos].final_precision = fabs(function(root_temp));
        data->method_data[pos].iterations = k;
    };
   // Marca o tempo final
    QueryPerformanceCounter(&end);

    // Tempo em nanosegundos
    elapsed_ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / (double)freq.QuadPart;
    
    //printf("\nGastou aproximadamente %.0f ns\n", elapsed_ns);
    
    data->method_data[pos].time = elapsed_ns/1000; //Salva o tempo em microsegundos
    data->method_data[pos].root = root_temp;
   
    return;
};


void comparative_table(METHOD_DATA *data, float (*function)(float),float (*d_function)(float)){
    LIMPA_TELA;
    method_bisection(data,0, function);
    LIMPA_TELA; //limpar tela após cada método
    method_fake_position(data,1,function);
    LIMPA_TELA;
    method_secant(data,3,function);
    LIMPA_TELA;
    method_newton_raphson(data,2,function,d_function);
    LIMPA_TELA;

    printf("\n\n\t\t\t\tTABELA COMPARATIVA ENTRE OS MÉTODOS\n\n\n");
    //number_of_methods
    for(int pos =3; pos>=0; pos--){
        printf("| Nome: %16s | Raiz: %f | Precisão: %f | Tempo (us): %8.2f | Iterações: %5d|\n",
        data->method_data[pos].name,data->method_data[pos].root, data->method_data[pos].final_precision,
        data->method_data[pos].time, data->method_data[pos].iterations);
    };
    printf("\n\n");

    return;
};