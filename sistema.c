#include "sistema.h"
#include <stdio.h>
#include <string.h>

#define FILENAME "cliente.bin"
#define FILENAME "extrato.bin"

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

    printf("Digite o CPF: ");
    scanf("%299s", cliente[*pos].CPF);
    clearBuffer();

    printf("Digite o tipo de conta: ");
    scanf("%299s", cliente[*pos].Tipo_de_conta);
    clearBuffer();

    printf("Digite o saldo inicial da conta: ");
    scanf("%299s", cliente[*pos].Saldo_inicial);
    clearBuffer();

    printf("Crie uma senha: ");
    scanf("%15s", cliente[*pos].Senha);
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
        printf("Nome: %s %s, CPF: %s, Tipo de conta: %s, Saldo Atual: %s\n" , cliente[i].Nome, cliente[i].CPF, cliente[i].Tipo_de_conta, cliente[i].Saldo_atual);
    }

    return OK;
}

ERROS Apagar_cliente(Cliente cliente[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    char cpf[TAM_CPF];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%15s", CPF);
    clearBuffer();

    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (strcmp(cliente[i].CPF, cpf) == 0) {
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

ERROS Débito(Cliente cliente[], int *pos) {
    
   
}

ERROS Depósito(Cliente cliente[], int *pos) {
    
}


ERROS Extrato(Cliente cliente[], int *pos) {
    
}

ERROS Transferência_entre_contas(Cliente cliente[], int *pos) {
    
}