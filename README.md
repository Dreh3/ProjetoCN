# Comparador de Métodos para Resolução de Equações Algébricas e Transcendentes

__Programa que implementar métodos para encontrar raízes de funções__<br>
Repositório foi criado com o intuito de desenvolver um projeto prático sobre os métodos estudados na Unidade 1 a disciplina de Cálculo Numérico menistrada na Universidade do Vale do São Francisca - UNIVASF.

__Responsável pelo desenvolvimento:__
Andressa Sousa Fonseca

## Detalhamento do Projeto
O programa desenvolvido permite ao usuário escolher entre dois problemas de engnharia, um sobre campo magnético e outro sobre conecentração de bactérias. Em ambos os casos, o programa executa 4 métodos diferentes para encontrar
as raízes da função, são eles Bissecção, Falsa Posição, Secante e Newton-Raphson. Após, a escolha do problema, o usuário pode informar os parâmetros necessários para o cálculo de cada método.

__Os paraâmetros de entrada de cada método:__
1) Bissecção: valor inicial e final do intervalo.
2) Falsa Posição: valor inicial e final do intervalo
4) Newton-Raphson: uma estimativa inicial.
5) Secante: duas estimativas iniciais.
<br>
Ao final da execução dos métodos, o programa exibe uma tabela com os seguintes dados: raiz encontrada, precisão alcançada, número de iterações e o tempo total. Assim, é possível identificar
qual métodos foi mais eficiente ou mais rápido.

## Adaptação para outras funções
A adição de novas funções é bastante simples, basta incluir duas novas funções, uma que retorna o valor de y para a função original do problema e outra que retorna o valor de y para a função 
correspondente à primeira derivada do problema.

Em seguida, adiciona-se um item ao menu ou sobrecreve um existente e passa o ponteiro da novas funções como parâmetro da comparative_table():

Desse modo, já é possível executar o programa com o novo problema.

