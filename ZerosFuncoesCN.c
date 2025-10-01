#include <stdio.h>
#include "Bisseccao.h"

//Funções para os métodos
//arquivos separados

//menu inicial em módulo?

int main(){


    int opcao_menu = 1;

    printf("Programa inicializado...");
    //pausa 


    //loop para repetir menu
    while(opcao_menu!=0){
        printf("\t\tMENU\n\t1 - Problema 1\n\t2 - Problema 2\n\t0 - Sair\nDigite a opção desejada: ");
        scanf("%d",&opcao_menu);

        if(opcao_menu!=0){
            if(opcao_menu==1){
                //resolve para o problema 1 acho que só muda a variável que armazena a função
            }else{
                //para o problema 2
            }
            //chama as funções com os métodos e pede os dados separadamente ou todos em sequência

            //mostra raiz e pausa para mostrar tabela comparativa
            
            //menu
            printf("\n\t1 - Retornar ao menu inicial\n\t0 - Sair");
            scanf("%d",&opcao_menu);
        }
    }

};
