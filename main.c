#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Cliente cliente[TOTAL];
    int pos;
    ERROS erro = carregar(cliente, &pos);
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
                break;
            case 2:
                Apagar_cliente(cliente, &pos);
                break;
            case 3:
                Listar_clientes(cliente, &pos);
                break;
            case 4:
                Debito(cliente, &pos);
                break;
            case 5:
                Deposito(cliente, &pos);
                break;
            case 6:
                Extrato(cliente, &pos);
                break;
            case 7:
                Transferencia_entre_contas(cliente, &pos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha inválida.\n");
        }
    } while (opcao != 0);

    // Salvando os dados no arquivo antes de sair
    erro = salvar(cliente, pos);
    if (erro != OK)
        printf("Erro ao salvar os dados no arquivo.\n");

    return 0;
}
