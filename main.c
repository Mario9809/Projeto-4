#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Cliente cliente[TOTAL];
    int pos;
    ERROS erro = carregar(cliente, &pos); // Carregar os dados dos clientes do arquivo

    if (erro != OK)
        pos = 0;

    int opcao;
    do {
        printf("\nMenu principal\n");
        printf("1 - Novo Cliente\n");
        printf("2 - Apagar Cliente\n");
        printf("3 - Listar Clientes\n");
        printf("4 - Débito\n");
        printf("5 - Depósito\n");
        printf("6 - Extrato\n");
        printf("7 - Transferência entre contas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Novo_cliente(cliente, &pos);
                salvar(cliente, pos); // Salvar os dados após cadastrar novo cliente
                break;
            case 2:
                Apagar_cliente(cliente, &pos);
                salvar(cliente, pos); // Salvar os dados após apagar cliente
                break;
            case 3:
                Listar_clientes(cliente, &pos);
                break;
            case 4:
                Debito(cliente, &pos);
                salvar(cliente, pos); // Salvar os dados após débito
                break;
            case 5:
                Deposito(cliente, &pos);
                salvar(cliente, pos); // Salvar os dados após depósito
                break;
            case 6:
                Extrato(cliente, &pos);
                break;
            case 7:
                Transferencia_entre_contas(cliente, &pos);
                salvar(cliente, pos); // Salvar os dados após transferência
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
