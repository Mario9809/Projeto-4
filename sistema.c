#include "sistema.h"

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

    int tipoConta;
    do {
        printf("Digite o tipo de conta (1 - Comum, 2 - Plus): ");
        scanf("%d", &tipoConta);
        clearBuffer();

        if (tipoConta == 1) {
            strcpy(cliente[*pos].Tipo_de_conta, "Comum");
            break;
        } else if (tipoConta == 2) {
            strcpy(cliente[*pos].Tipo_de_conta, "Plus");
            break;
        } else {
            printf("Opção inválida. Digite novamente.\n");
        }
    } while (1);

    printf("Digite o saldo inicial da conta: ");
    scanf("%f", &cliente[*pos].Saldo_inicial);
    clearBuffer();

    printf("Crie uma senha: ");
    scanf("%15s", cliente[*pos].Senha);
    clearBuffer();

    // Atualizar o saldo atual com o saldo inicial
    cliente[*pos].Saldo_atual = cliente[*pos].Saldo_inicial;

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
        printf("Nome: %s, Sobrenome: %s, CPF: %d, Tipo de conta: %s, Saldo Atual: %.2f\n" , cliente[i].Nome, cliente[i].Sobrenome, cliente[i].CPF, cliente[i].Tipo_de_conta, cliente[i].Saldo_atual);
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
    printf("Digite o número do CPF do cliente: ");
    scanf("%d", &cpf);
    clearBuffer();

    char senha[16];
    printf("Digite a senha: ");
    scanf("%15s", senha);
    clearBuffer();

    float valor;
    printf("Digite o valor a ser debitado: ");
    scanf("%f", &valor);
    clearBuffer();

    int indice_cliente = -1;
    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf && strcmp(cliente[i].Senha, senha) == 0) {
            indice_cliente = i;
            break;
        }
    }

    if (indice_cliente == -1) {
        printf("CPF ou senha incorretos. Operação de débito não autorizada.\n");
        return SENHA;
    }

    float saldo_anterior = cliente[indice_cliente].Saldo_atual; // Salva o saldo anterior
    float novo_saldo = saldo_anterior; // Cria uma variável para o novo saldo

    if (strcmp(cliente[indice_cliente].Tipo_de_conta, "Comum") == 0) {
        // Conta comum
        if (saldo_anterior - valor < -1000) {
            printf("Saldo insuficiente. Operação de débito não autorizada.\n");
            return SALDO_INSUFICIENTE;
        }
        novo_saldo -= valor * 1.05; // Aplica taxa de 5%
    } else if (strcmp(cliente[indice_cliente].Tipo_de_conta, "Plus") == 0) {
        // Conta Plus
        if (saldo_anterior - valor < -5000) {
            printf("Saldo insuficiente. Operação de débito não autorizada.\n");
            return SALDO_INSUFICIENTE;
        }
        novo_saldo -= valor * 1.03; // Aplica taxa de 3%
    }

    cliente[indice_cliente].Saldo_atual = novo_saldo; // Atualiza o saldo atual

    printf("Débito de %.2f realizado com sucesso!\n", valor);
    printf("Saldo anterior: %.2f\n", saldo_anterior);
    printf("Novo saldo: %.2f\n", novo_saldo);
    return OK;
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
