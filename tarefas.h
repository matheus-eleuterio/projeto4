#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_CLIENTES 1000
#define MAX_OPERACOES 100

typedef enum { COMUM, PLUS } tipo_conta;

typedef struct {
    char nome[40];
    char cpf[11]; 
    tipo_conta tipo;
    double saldo;
    char senha[10];
} Cliente;

typedef struct {
    char cpf[11];
    double valor;
} Operacao;

Cliente clientes[MAX_CLIENTES];
Operacao operacoes[MAX_OPERACOES];
int numero_clientes = 0;
int numero_operacoes = 0;

void nova_conta();
void listar_clientes();
void apagar_cliente();
void debitar();
void depositar();
void extrato();
void transferencia();
void salvar();
void carregar();

#endif
