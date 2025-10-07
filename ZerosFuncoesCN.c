#include <stdio.h>
#include "methods.h"
#include <math.h>
#include <locale.h>
#include <windows.h>

METHOD_DATA method_data;


float problem_1(float x){
    //float root = pow(x,3) - 5*pow(x,2) + 8*x - 4;
    float root = 3*pow(x,2) -10*x + 8; //usando a primeira derivada como função igualada a zero
    return root;
};

float problem_2(float x){
    float root = 80*exp((-2*x)) + 20*(exp(-0.1*x)) - 10; //adaptação para igualar a 0
    //float root = pow(x,3) - x -1;
    return root;
};

float d_problem_1(float x){
    //float root = 3*pow(x,2) -10*x + 8;
    float root = 6*x -10;
    return root;
};

float d_problem_2(float x){
    float root = -160*exp((-2*x)) -2*(exp(-0.1*x));
    return root;
};

//float (*function_pointer) (float) = problem_1;

int main(){

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int menu_option = 1;

    //loop para repetir menu
    while(menu_option!=0){
        printf("\n\n\t\tMENU INICIAL\n\n\t1 - Campo magnético 1\n\t2 - Concentração de bactérias\n\t0 - Sair\n\nDigite a opção desejada: ");
        scanf("%d",&menu_option);
        setbuf(stdin,NULL);
        LIMPA_TELA;
        if(menu_option==1 || menu_option==2){
            initial_input(&method_data); //pede só precisão e número máximo de iterações

            if(menu_option==1){
                comparative_table(&method_data, problem_1, d_problem_1);
            }else if (menu_option == 2){
                comparative_table(&method_data, problem_2, d_problem_2);
            };
            
        };
    
    };

};
