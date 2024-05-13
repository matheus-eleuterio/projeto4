#include "tarefas.h"
#include <stdio.h>
#include <string.h>

dados_cliente clientes[MAX_CONTAS];
operacao operacoes[MAX_OPERACOES];
extern int qtd_contas;
extern int qtd_operacoes;

// >>>>>>>>>>>>>>>>>>>>> Função Nova Conta <<<<<<<<<<<<<<<<<<<<<<<<
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

// >>>>>>>>>>>>>>>>>>>>> Função Deletar Contas <<<<<<<<<<<<<<<<<<<<<<<<
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

// >>>>>>>>>>>>>>>>>>>>> Função Listar <<<<<<<<<<<<<<<<<<<<<<<<
void listar_contas() {
  printf("\nLista de clientes com conta no banco:\n");
  for (int i = 0; i < qtd_contas; i++) {
    printf("\nNome: %s\nCPF: %s\nTipo de conta: %s\nSaldo: R$ %.2f\n",
           clientes[i].nome, clientes[i].cpf,
           clientes[i].tipo == COMUM ? "Comum" : "Plus", clientes[i].saldo);
  }
}

// >>>>>>>>>>>>>>>>>>>>> Função Debitar <<<<<<<<<<<<<<<<<<<<<<<<
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

  // taxa
  double taxa;
  if (clientes[i].tipo == COMUM) {
    taxa = 0.05;
  } else {
    taxa = 0.03;
  }
  double valor_atual = valor + (valor * taxa);
  clientes[i].saldo = clientes[i].saldo - valor_atual;
  printf("Debito realizado com sucesso.\n");

  // salva op
  operacao op;
  strcpy(op.cpf, cpf);
  op.valor = -valor_atual;
  operacoes[qtd_operacoes++] = op;
}

// >>>>>>>>>>>>>>>>>>>>> Função Depositar <<<<<<<<<<<<<<<<<<<<<<<<
void depositar() {
  char cpf[11];
  double valor;
  printf("CPF: ");
  scanf("%s", cpf);

  int i;
  for (i = 0; i < qtd_contas; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0) {
      break;
    }
  }

  if (i == qtd_contas) {
    printf("Não foi possível localizar a conta. Verifique o CPF digitado.\n");
    return;
  }

  printf("Valor que deseja depositar na conta: ");
  scanf("%lf", &valor);

  clientes[i].saldo += valor;
  printf("Deposito realizado com sucesso.\n");

  operacao op;
  strcpy(op.cpf, cpf);
  op.valor = valor;
  operacoes[qtd_contas++] = op;
}

// >>>>>>>>>>>>>>>>>>>>> Função Transferência <<<<<<<<<<<<<<<<<<<<<<<<
void transferencia() {
  char conta_origem[11], senha_origem[10], conta_final[11];
  double valor;
  printf("\nDigite o CPF da conta de onde sairá o valor: ");
  scanf("%s", conta_origem);
  printf("Senha: ");
  scanf("%s", senha_origem);

  int i, j;
  for (i = 0; i < qtd_contas; i++) {
    if (strcmp(clientes[i].cpf, conta_origem) == 0 &&
        strcmp(clientes[i].senha, senha_origem) == 0) {
      break;
    }
  }

  if (i == qtd_contas) {
    printf("Dados inválidos! Verifique o CPF e senha digitado.\n");
    return;
  }

  printf("Digite o CPF da conta para qual quer realizar a transferência: ");
  scanf("%s", conta_final);

  for (j = 0; j < qtd_contas; j++) {
    if (strcmp(clientes[j].cpf, conta_final) == 0) {
      break;
    }
  }

  if (j == qtd_contas) {
    printf("Não foi possível encontrar a conta de destino. Verifique o CPF "
           "inserido.\n");
    return;
  }

  printf("Digite o valor que deseja transferir: R$ ");
  scanf("%lf", &valor);

  // verificando se tem saldo ou limite disponível
  if (clientes[i].tipo == COMUM && valor > (clientes[i].saldo + 1000)) {
    printf("Você não possui limite suficiente para esta operação.\n");
    return;
  } else if (clientes[i].tipo == PLUS && valor > (clientes[i].saldo + 5000)) {
    printf("Você não possui limite suficiente para esta operação.\n");
    return;
  }

  // debitar + depositar
  clientes[i].saldo -= valor;
  clientes[j].saldo += valor;
  printf("Transferencia realizada com sucesso.\n");

  operacao op_origem, op_final;
  // origem
  strcpy(op_origem.cpf, conta_origem);
  op_origem.valor = -valor;
  operacoes[qtd_operacoes++] = op_origem;
  // final
  strcpy(op_final.cpf, conta_final);
  op_final.valor = valor;
  operacoes[qtd_operacoes++] = op_final;
}

// >>>>>>>>>>>>>>>>>>>>> Função Extrato <<<<<<<<<<<<<<<<<<<<<<<<
void extrato() {
  char cpf[11], senha[10];
  printf("CPF: ");
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

  char nome_arquivo[30];
  sprintf(nome_arquivo, "%s_extrato.txt", clientes[i].cpf);
  FILE *arquivo = fopen(nome_arquivo, "w");
  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo de extrato.\n");
    return;
  }

  fprintf(arquivo, "Extrato Bancario\n");
  fprintf(arquivo, "Nome: %s\nCPF: %s\n\n", clientes[i].nome, clientes[i].cpf);
  fprintf(arquivo, "Operacoes:\n");

  for (int j = 0; j < qtd_operacoes; j++) {
    if (strcmp(operacoes[j].cpf, cpf) == 0) {
      if (operacoes[j].valor < 0) {
        fprintf(arquivo, "Debito: R$ %.2f\n", operacoes[j].valor);
      } else {
        fprintf(arquivo, "Credito: R$ %.2f\n", operacoes[j].valor);
      }
    }
  }

  fclose(arquivo);
  printf("Extrato gerado com sucesso.\n");
}
