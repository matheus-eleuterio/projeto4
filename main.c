#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int opcao;

  do {
    printf("\n1. Nova conta\n");
    printf("2. Listar clientes\n");
    printf("3. Apagar cliente\n");
    printf("4. Débito\n");
    printf("5. Depósito\n");
    printf("6. Extrato\n");
    printf("7. Transferência entre contas\n");
    printf("8. Carregar Dados do banco\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Você selecionou a opção de criar uma nova conta.\n");
      nova_conta();
      break;
    case 2:
      printf("Você selecionou a opção de listar todas as contas.\n");
      break;
    case 3:
      printf("Você selecionou a opção de apagar uma conta.\n");
      break;
    case 4:
      printf("Você selecionou a opção de debitar valor na conta.\n");
      break;
    case 5:
      printf("Você selecionou a opção de fazer um depósito.\n");
      break;
    case 6:
      printf("Você selecionou a opção de conferir extrato.\n");
      break;
    case 7:
      printf("Você selecionou a opção de fazer uma transferência.\n");
      break;
    case 8:
      printf("Você selecionou a opção de carregar de um arquivo binário.\n");
      break;
    case 0:
      printf("Você saiu do programa.\n");
      break;
    default:
      printf("Opção inválida! Entre com uma opção válida ou digite 0 para "
             "sair.\n");
    }
  } while (opcao != 0);

  return 0;
}