#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_CONTAS 1000
#define MAX_OPERACOES 100

typedef enum { COMUM, PLUS } tipo_conta;

typedef struct {
    char nome[40];
    char cpf[11]; 
    tipo_conta tipo;
    double saldo;
    char senha[10];
} dados_cliente;

typedef struct {
    char cpf[11];
    double valor;
} operacao;

dados_cliente clientes[MAX_CONTAS];
operacao operacoes[MAX_OPERACOES];
int qtd_clientes = 0;
int qtd_operacoes = 0;

void nova_conta();
void listar_clientes();
void apagar_cliente();
void debitar();
void depositar();
void extrato();
void transferencia();
void carregar_dados();

#endif
