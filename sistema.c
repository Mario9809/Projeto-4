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
    printf("Novo CLiente cadastrado com sucesso!!\n");
    return OK;
}

ERROS listar(Cliente cliente[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    printf("Lista de Clientes:\n");
    for (int i = 0; i < *pos; i++) {
        printf("Nome: %s %s, CPF: %s, Tipo de conta: %s, Saldo Atual: %s\n" , cientes[i].Nome, cientes[i].CPF, clentes[i].Tipo_de_conta, clientes[i].Saldo_atual);
    }

    return OK;
}

ERROS Apagar_cliente(Cliente cliente[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATOS;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%15s", telefone);
    clearBuffer();

    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (strcmp(agenda[i].Telefone, telefone) == 0) {
            encontrado = 1;
            for (int j = i; j < *pos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*pos)--;
            break;
        }
    }
     printf("contato deletado com sucesso!!\n");
    return encontrado ? OK : NAO_ENCONTRADO;
}

ERROS salvar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "wb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    fwrite(agenda, sizeof(Agenda), *pos, arquivo);
    fclose(arquivo);
    printf("Agenda salva com sucesso!!\n");
    return OK;
}

ERROS carregar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "rb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    *pos = fread(agenda, sizeof(Agenda), TOTAL, arquivo);
    fclose(arquivo);
    printf("Agenda carregada com sucesso!!\n");
    return OK;
}
