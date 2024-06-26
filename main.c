#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  carregar_dados();
  int opcao;

  do {
    printf("\n1. Nova conta\n");
    printf("2. Listar clientes\n");
    printf("3. Deletar conta\n");
    printf("4. Débito\n");
    printf("5. Depósito\n");
    printf("6. Extrato\n");
    printf("7. Transferência entre contas\n");
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
      listar_contas();
      break;
    case 3:
      printf("Você selecionou a opção de deletar uma conta.\n");
      deletar_conta();
      break;
    case 4:
      printf("Você selecionou a opção de debitar valor na conta.\n");
      debitar();
      break;
    case 5:
      printf("Você selecionou a opção de fazer um depósito.\n");
      depositar();
      break;
    case 6:
      printf("Você selecionou a opção de conferir extrato.\n");
      extrato();
      break;
    case 7:
      printf("Você selecionou a opção de fazer uma transferência.\n");
      transferencia();
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