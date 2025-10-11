# Comparador de Métodos para Resolução de Equações Algébricas e Transcendentes

__Programa que implementa métodos para encontrar raízes de funções__<br>
Repositório foi criado com o intuito de desenvolver um projeto prático sobre os métodos estudados na Unidade 1 da disciplina de Cálculo Numérico menistrada na Universidade do Vale do São Francisco - UNIVASF.

__Responsável pelo desenvolvimento:__
Andressa Sousa Fonseca

## Detalhamento do Projeto
O programa desenvolvido permite ao usuário escolher entre dois problemas de engenharia, um sobre campo magnético e outro sobre concentração de bactérias. Em ambos os casos, o programa executa 4 métodos diferentes para encontrar as raízes da função, são eles Bissecção, Falsa Posição, Secante e Newton-Raphson. Após a escolha do problema, o usuário pode informar os parâmetros necessários para o cálculo de cada método.

__Os paraâmetros de entrada de cada método:__
1) Bissecção: valor inicial e final do intervalo.
2) Falsa Posição: valor inicial e final do intervalo
4) Newton-Raphson: uma estimativa inicial.
5) Secante: duas estimativas iniciais.

Ao final da execução dos métodos, o programa exibe uma tabela comparativa com os seguintes dados: raiz encontrada, precisão alcançada, número de iterações e o tempo total. Assim, é possível identificar qual método foi mais eficiente ou mais rápido.

## Adaptação para outras funções
A adição de novas funções é bastante simples, basta incluir duas novas funções, uma que retorna o valor de y para a função original do problema e outra que retorna o valor de y para a função correspondente à primeira derivada do problema.
```bash
float problem_2(float x){                                //função original
    float root = 80*exp((-2*x)) + 20*(exp(-0.1*x)) - 10; 
    return root;
};
float d_problem_2(float x){                              //função derivada
    float root = -160*exp((-2*x)) -2*(exp(-0.1*x));
    return root;
};
```
Em seguida, adiciona-se um item ao menu ou sobrecreve um existente e passa o ponteiro da novas funções como parâmetro da comparative_table():
```bash
if(menu_option==1){
  comparative_table(&method_data, problem_1, d_problem_1);        //Executa os métodos e monta a tabela
}else if (menu_option == 2){
  comparative_table(&method_data, problem_2, d_problem_2);
};
```
Desse modo, já é possível executar o programa com o novo problema.

