/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
// declaração das funções para serem entendidas pelo sistema
void soma();
void subtracao();
void multi();
void divisao();

//declaração da variável para ser dada como opção dentro do sistema
int main(void) {
  int opcao;
  
  printf("Escolha uma opção:\n");
  printf("1- Soma\n2- Subtração\n3- Multiplicação\n4- Divisão\n5- Sair\n");
  scanf("%d", &opcao);
  //Utilização de função relacionado a escolha do usuário
  switch(opcao) {
    case 1:
      soma();
      break;
    case 2:
      subtracao();
      break;
    case 3:
      multi();
      break;
    case 4:
      divisao();
      break;
    case 5:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida\n");
      break;
  }

  return 0;
}
//Escpecificando a função e as relações das variáveis dentro destas para executar a operação 
void soma() {
  float numeroA, numeroB, result;
  printf("\nDigite o numero A: ");
  scanf("%f", &numeroA);
  printf("\nDigite o numero B: ");
  scanf("%f", &numeroB);
  result = numeroA + numeroB;
  printf("\nO resultado é: %f\n", result);
}
//Escpecificando a função e as relações das variáveis dentro destas para executar a operação 

void subtracao() {
  float numeroA, numeroB, result;
  printf("\nDigite o numero A: ");
  scanf("%f", &numeroA);
  printf("\nDigite o numero B: ");
  scanf("%f", &numeroB);
  result = numeroA - numeroB;
  printf("\nO resultado é: %f\n", result);
}
//Escpecificando a função e as relações das variáveis dentro destas para executar a operação 

void multi() {
  float numeroA, numeroB, result;
  printf("\nDigite o numero A: ");
  scanf("%f", &numeroA);
  printf("\nDigite o numero B: ");
  scanf("%f", &numeroB);
  result = numeroA * numeroB;
  printf("\nO resultado é: %f\n", result);
}
//Escpecificando a função e as relações das variáveis dentro destas para executar a operação 

void divisao() {
  float numeroA, numeroB, result;
  printf("\nDigite o numero A: ");
  scanf("%f", &numeroA);
  printf("\nDigite o numero B: ");
  scanf("%f", &numeroB);
  if(numeroB != 0) {
    result = numeroA / numeroB;
    printf("\nO resultado é: %f\n", result);
  } else {
    printf("\nNão é possível dividir por zero!\n");
  }
}
