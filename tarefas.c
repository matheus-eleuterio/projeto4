#include <stdio.h>
#include <string.h>
#include "tarefas.h"

Cliente clientes[MAX_CLIENTES];
Operacao operacoes[MAX_OPERACOES];
int numero_clientes = 0;
int numero_operacoes = 0;

void nova_conta() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo;
    printf("Nome: ");
    scanf("%s", novo.nome);
    printf("CPF: ");
    scanf("%s", novo.cpf);
    printf("Tipo de conta (0 - Comum, 1 - Plus): ");
    scanf("%d", &novo.tipo);
    printf("Valor inicial da conta: ");
    scanf("%lf", &novo.saldo);
    printf("Senha: ");
    scanf("%s", novo.senha);

    clientes[numClientes++] = novo;
    printf("Cliente cadastrado com sucesso!\n");
}