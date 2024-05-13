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

void listar_contas() {
  printf("\nLista de clientes com conta no banco:\n");
  for (int i = 0; i < qtd_contas; i++) {
    printf("\nNome: %s\nCPF: %s\nTipo de conta: %s\nSaldo: R$ %.2f\n",
           clientes[i].nome, clientes[i].cpf,
           clientes[i].tipo == COMUM ? "Comum" : "Plus", clientes[i].saldo);
  }
}

void debitar() {
  char cpf[11], senha[10];
  double valor;
  printf("\nCPF: ");
  scanf("%s", cpf);
  printf("Senha: ");
  scanf("%s", senha);

  int i;
  for (i = 0; i < qtd_contas; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0 &&
        strcmp(clientes[i].senha, senha) == 0) {
      break;
    }
  }

  if (i == qtd_contas) {
    printf("Dados inválidos! Verifique o CPF e senha digitados.\n");
    return;
  }

  printf("Valor que deseja debitar da conta (R$): ");
  scanf("%lf", &valor);

  if (clientes[i].tipo == COMUM && valor > (clientes[i].saldo + 1000)) {
    printf("Você não possui limite suficiente para esta operação.\n");
    return;
  } else if (clientes[i].tipo == PLUS && valor > (clientes[i].saldo + 5000)) {
    printf("Você não possui limite suficiente para esta operação.\n");
    return;
  }

  //taxa
  double taxa;
  if (clientes[i].tipo == COMUM) {
      taxa = 0.05;
  } else {
      taxa = 0.03;
  }
  double valor_atual = valor + (valor * taxa);
  clientes[i].saldo = clientes[i].saldo - valor_atual;
  printf("Debito realizado com sucesso.\n");

  //salva op
  operacao op;
  strcpy(op.cpf, cpf);
  op.valor = -valor_atual;
  operacoes[qtd_operacoes++] = op;
}