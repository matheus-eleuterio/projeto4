# Projeto 4: Quem Poupa Tem

### Descrição

O projeto teve como objetivo criar um sistema bancário desenvolvido em linguagem C. O sistema permite criar, listar, deletar contas, realizar depósitos, débitos, transferências e gerar extratos. Além disso, salva automaticamente as operações em um arquivo binário.

### Funcionalidades

1. *Criar Nova Conta*: Permite criar uma nova conta bancária fornecendo informações como nome, CPF, tipo de conta, depósito inicial e senha.
2. *Listar Clientes*: Exibe uma lista de todas as contas cadastradas no banco, mostrando o nome, CPF, tipo de conta e saldo.
3. *Deletar Conta*: Permite deletar uma conta do banco fornecendo o CPF da conta a ser deletada.
4. *Débito*: Permite debitar um valor de uma conta bancária, considerando limites e taxas conforme o tipo de conta.
5. *Depósito*: Permite depositar um valor em uma conta bancária.
6. *Extrato*: Gera um extrato bancário em formato de arquivo texto, detalhando todas as operações realizadas na conta.
7. *Transferência*: Permite transferir valores entre contas bancárias.

### Estrutura do Projeto

- *main.c*: Contém a função principal do programa e o menu de navegação.
- *tarefas.c*: Implementa as funções de operações do banco, como criar conta, listar contas, deletar conta, debitar, depositar, transferir e gerar extrato.
- *tarefas.h*: Cabeçalho do programa, onde é definido as estruturas de dados utilizadas no programa.

**Execução do código**

Siga os passos:

1) É necessário ter um compilador de C instalado na sua máquina. Neste projeto usaremos o GCC.
2) Abra o terminal na pasta que esta salvo os arquivos que compoem o projeto.
3) Digite "gcc main.c tarefas.c -o banco" no terminal para compilar o programa.
4) Digite "./banco" no terminal para executar o programa.
5) Selecione uma das opções apresentadas no menu.

### Uso

Ao executar o programa, será exibido um menu com as seguintes opções:

O banco de dados é criado após realizar a primeira operação bancária. O programa salva os dados das operações e dos clientes de forma automática num arquivo binário após realizar as operações, com exceção da função listar e gerar extrato.

1. *Nova conta*: Permite criar uma nova conta fornecendo as informações solicitadas.
2. *Listar clientes*: Exibe a lista de todas as contas cadastradas.
3. *Deletar conta*: Permite deletar uma conta fornecendo o CPF da conta.
4. *Débito*: Permite debitar um valor de uma conta.
5. *Depósito*: Permite depositar um valor em uma conta.
6. *Extrato*: Gera um extrato detalhado das operações de uma conta.
7. *Transferência entre contas*: Permite transferir valores entre contas.
0. *Sair*: Encerra o programa.

Projeto desenvolvido por Matheus Eleutério, Danilo Chiarelli e Jeferson Roque para a disciplina CC2632.

