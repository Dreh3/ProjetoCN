#include <stdio.h>
#include "methods.h"

METHOD_DATA method_data;

float problem_1(float x){

};

float problem_2(float x){

};

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

            if(menu_option==1){
                function_pointer = problem_1;
            }else if (menu_option == 2){
                function_pointer = problem_2;
            }
            comparative_table(&method_data, function_pointer);
            printf("\n\t1 - Retornar ao menu inicial\n\t0 - Sair");
            scanf("%c",&menu_option);
        };
    };

};
