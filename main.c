#include "sistema.h"
#include <stdio.h>



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
        printf("6 - Exrato\n");
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

              Listar_cientes(cliente, &pos);

              break;

          case 4:

              Débito(cliente, &pos);

              break;

          case 5:

              Depósito(cliente, &pos);

              break;

          case 6:

              Extrato(cliente, &pos);

              break;     

          case 7:

              Transferência_entre_contas(cliente, &pos);

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