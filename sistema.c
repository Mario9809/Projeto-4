#include "sistema.h"
#include <stdio.h>
#include <string.h>

#define FILENAME "cliente.bin"
#define FILENAME1 "extrato.bin"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

ERROS Novo_cliente(Cliente cliente[], int *pos) {
    if (*pos >= TOTAL) {
        return MAX_CLIENTES;
    }

    printf("Digite o nome: ");
    scanf("%299s", cliente[*pos].Nome);
    clearBuffer();

    printf("Digite o Sobrenome: ");
    scanf("%299s", cliente[*pos].Sobrenome);
    clearBuffer();

    printf("Digite o CPF: ");
    scanf("%d", &cliente[*pos].CPF);
    clearBuffer();

    printf("Digite o tipo de conta (Comum ou Plus): ");
    scanf("%299s", cliente[*pos].Tipo_de_conta);
    clearBuffer();

    printf("Digite o saldo inicial da conta: ");
    scanf("%d", &cliente[*pos].Saldo_inicial);
    clearBuffer();

    printf("Crie uma senha: ");
    scanf("%15s", &cliente[*pos].Senha);
    clearBuffer();

    (*pos)++;
    printf("Novo cliente cadastrado com sucesso!!\n");
    return OK;
}

ERROS Listar_clientes(Cliente cliente[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    printf("Lista de Clientes:\n");
    for (int i = 0; i < *pos; i++) {
        printf("Nome: %s, Sobrenome: %s, CPF: %d, Tipo de conta: %s, Saldo Atual: %d\n" , cliente[i].Nome, cliente[i].Sobrenome, cliente[i].CPF, cliente[i].Tipo_de_conta, cliente[i].Saldo_atual);
    }

    return OK;
}

ERROS Apagar_cliente(Cliente cliente[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    int cpf;
    printf("Digite o número do CPF do cliente que deseja deletar: ");
    scanf("%d", &cpf);
    clearBuffer();

    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf) {
            encontrado = 1;
            for (int j = i; j < *pos - 1; j++) {
                cliente[j] = cliente[j + 1];
            }
            (*pos)--;
            break;
        }
    }
     printf("contato deletado com sucesso!!\n");
    return encontrado ? OK : NAO_ENCONTRADO;
}

ERROS Debito(Cliente cliente[], int *pos) {
    
    int cpf;
    printf("Digite o número do CPF do cliente que deseja      debitar: ");
    
    scanf("%d", &cpf);
    clearBuffer();
    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf) {
            
            
    
}

ERROS Deposito(Cliente cliente[], int *pos) {
    printf(" ");
    return 0;
}


ERROS Extrato(Cliente cliente[], int *pos) {
    printf(" ");
    return 0;
}

ERROS Transferencia_entre_contas(Cliente cliente[], int *pos) {
    printf(" ");
    return 0;
}

ERROS carregar(Cliente cliente[], int *pos) {
    printf(" ");
    return 0;
}
