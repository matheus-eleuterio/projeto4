#include "tarefas.h"
#include <stdio.h>
#include <string.h>

dados_cliente clientes[MAX_CONTAS];
operacao operacoes[MAX_OPERACOES];
extern int qtd_contas;
extern int qtd_operacoes;

void nova_conta() {
  if (qtd_contas >= MAX_CONTAS) {
    printf("Limite máximo de contas atingido!\n");
    return;
  }

  dados_cliente novo;
  printf("\nNome: ");
  scanf("%s", novo.nome);
  printf("CPF: ");
  scanf("%s", novo.cpf);
  printf("Selecione o tipo de conta (0 - Comum | 1 - Plus): ");
  scanf("%d", &novo.tipo);
  printf("Deposito inicial: ");
  scanf("%lf", &novo.saldo);
  printf("Senha: ");
  scanf("%s", novo.senha);

  clientes[qtd_contas++] = novo;
  printf("Nova conta cadastrada com sucesso!\n");
}

void deletar_conta() {
  char cpf[11];
  printf("\nCPF referente a conta que deseja deletar: ");
  scanf("%s", cpf);

  int i, encontrado = 0;
  for (i = 0; i < qtd_contas; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0) {
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    for (; i < qtd_contas - 1; i++) {
      clientes[i] = clientes[i + 1];
    }
    qtd_contas--;
    printf("Conta deletada com sucesso!\n");
  } else {
    printf("A conta não consta no nosso banco de dados.\n");
  }
}
