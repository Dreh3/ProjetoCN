#include <stdio.h>
#include "methods.h"
#include <math.h>

METHOD_DATA method_data;

float problem_1(float x){
    //float root = pow(x,3) - 5*pow(x,2) + 8*x - 4;
    float root = exp(x) - 3*x;
    //printf("\nEntra na function 1");
    return root;
};

float problem_2(float x){
    //float root = 80*exp((-2*x)) + 20*(exp(-0.1*x)) - 10; //adaptação para igualar a 0
    float root = exp(x) - 3*x;
    //printf("\nEntra na function 2");
    return root;
};

//float (*function_pointer) (float) = problem_1;

int main(){


    char menu_option = 1;

    printf("Programa inicializado...");
    //pausa 


    //loop para repetir menu
    while(menu_option!=0){
        printf("\t\tMENU\n\t1 - Problema 1\n\t2 - Problema 2\n\t0 - Sair\nDigite a opção desejada: ");
        scanf("%c",&menu_option);
        
        if(menu_option!=0){
            initial_input(&method_data);

            if(menu_option=='1'){
                comparative_table(&method_data, problem_1);
            }else if (menu_option == '2'){
                comparative_table(&method_data, problem_2);
            }
            
            printf("\n\t1 - Retornar ao menu inicial\n\t0 - Sair");
            scanf("%c",&menu_option);
        };
    };

};
