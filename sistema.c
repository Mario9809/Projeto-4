#include "sistema.h"


#define FILENAME "cliente.bin"
#define FILENAME1 "extrato.bin"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void registrarOperacao(Cliente *cliente, float valor) {
    if (cliente->num_operacoes < MAX_OPERACOES) {
        cliente->operacoes[cliente->num_operacoes++] = valor;
    } else {
        printf("Limite de operações excedido.\n");
    }
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
    cliente[*pos].num_operacoes = 0; // Inicializar o número de operações

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

ERROS Debito(Cliente cliente[], int *pos)             {
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
    registrarOperacao(&cliente[indice_cliente], -valor); // Registra a operação de débito

    printf("Débito de %.2f realizado com sucesso!\n", valor);
    printf("Saldo anterior: %.2f\n", saldo_anterior);
    printf("Novo saldo: %.2f\n", novo_saldo);
    return OK;
}

ERROS Deposito(Cliente cliente[], int *pos) {
    int cpf;
    printf("Digite o número do CPF do cliente que deseja depositar: ");
    scanf("%d", &cpf);
    clearBuffer();

    float valor;
    printf("Digite o valor a ser depositado: ");
    scanf("%f", &valor);
    clearBuffer();

    int indice_cliente = -1;
    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf) {
            indice_cliente = i;
            break;
        }
    }

    if (indice_cliente == -1) {
        printf("CPF incorreto.\n");
        return NAO_ENCONTRADO;
    }

    float saldo_anterior = cliente[indice_cliente].Saldo_atual; // Salva o saldo anterior
    float novo_saldo = saldo_anterior; // Cria uma variável para o novo saldo

    cliente[indice_cliente].Saldo_atual += valor; // Realiza o depósito
    registrarOperacao(&cliente[indice_cliente], valor); // Registra a operação de depósito

    printf("Depósito de %.2f realizado com sucesso!\n", valor);
    printf("Saldo anterior: %.2f\n", saldo_anterior);
    printf("Novo saldo: %.2f\n", cliente[indice_cliente].Saldo_atual);
    return OK;
}

ERROS Extrato(Cliente cliente[], int *pos) {
    int cpf;
    printf("Digite o número do CPF do cliente: ");
    scanf("%d", &cpf);
    clearBuffer();

    int indice_cliente = -1;
    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf) {
            indice_cliente = i;
            break;
        }
    }

    if (indice_cliente == -1) {
        printf("CPF incorreto.\n");
        return NAO_ENCONTRADO;
    }

    printf("Extrato da conta de CPF %d:\n", cliente[indice_cliente].CPF);
    printf("----------------------------------------\n");

    printf("Saldo inicial: %.2f\n", cliente[indice_cliente].Saldo_inicial);

    if (cliente[indice_cliente].num_operacoes == 0) {
        printf("Nenhuma operação realizada.\n");
    } else {
        printf("Operações realizadas:\n");
        float saldo_atual = cliente[indice_cliente].Saldo_inicial;
        for (int i = 0; i < cliente[indice_cliente].num_operacoes; i++) {
            if (cliente[indice_cliente].operacoes[i] > 0) {
                printf("Operação %d: Depósito de %.2f (+)\n", i + 1, cliente[indice_cliente].operacoes[i]);
                saldo_atual += cliente[indice_cliente].operacoes[i];
            } else {
                printf("Operação %d: Débito de %.2f (-)\n", i + 1, -cliente[indice_cliente].operacoes[i]);
                saldo_atual -= cliente[indice_cliente].operacoes[i];
            }
        }
        printf("----------------------------------------\n");
        printf("Saldo atual: %.2f\n", saldo_atual);
    }

    return OK;
}

ERROS Transferencia_entre_contas(Cliente cliente[], int *pos) {
    int cpf_origem, cpf_destino;
    printf("Digite o número do CPF da conta de origem: ");
    scanf("%d", &cpf_origem);
    clearBuffer();

    char senha[16];
    printf("Digite a senha da conta de origem: ");
    scanf("%15s", senha);
    clearBuffer();

    int encontrado_origem = 0;
    int indice_origem;

    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf_origem && strcmp(cliente[i].Senha, senha) == 0) {
            encontrado_origem = 1;
            indice_origem = i;
            break;
        }
    }

    if (!encontrado_origem) {
        printf("Conta de origem não encontrada ou senha incorreta.\n");
        return SENHA;
    }

    printf("Digite o número do CPF da conta de destino: ");
    scanf("%d", &cpf_destino);
    clearBuffer();

    int encontrado_destino = 0;
    int indice_destino;

    for (int i = 0; i < *pos; i++) {
        if (cliente[i].CPF == cpf_destino) {
            encontrado_destino = 1;
            indice_destino = i;
            break;
        }
    }

    if (!encontrado_destino) {
        printf("Conta de destino não encontrada.\n");
        return NAO_ENCONTRADO;
    }

    float valor;
    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);
    clearBuffer();

    if (cliente[indice_origem].Saldo_atual - valor >= 0) {
        float saldo_anterior_origem = cliente[indice_origem].Saldo_atual;
        float saldo_anterior_destino = cliente[indice_destino].Saldo_atual;

        cliente[indice_origem].Saldo_atual -= valor;
        cliente[indice_destino].Saldo_atual += valor;

        registrarOperacao(&cliente[indice_origem], -valor); // Registrar operação na conta de origem
        registrarOperacao(&cliente[indice_destino], valor); // Registrar operação na conta de destino

        printf("Transferência de %.2f realizada com sucesso!\n", valor);
        printf("Saldo anterior da conta de origem: %.2f\n", saldo_anterior_origem);
        printf("Novo saldo da conta de origem: %.2f\n", cliente[indice_origem].Saldo_atual);
        printf("Saldo anterior da conta de destino: %.2f\n", saldo_anterior_destino);
        printf("Novo saldo da conta de destino: %.2f\n", cliente[indice_destino].Saldo_atual);
        return OK;
    } else {
        printf("Saldo insuficiente na conta de origem para realizar a transferência.\n");
        return SALDO_INSUFICIENTE;
    }
}

ERROS carregar(Cliente cliente[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "rb");
    if (!arquivo) {
        return NAO_ENCONTRADO;
    }

    *pos = 0;
    while (fread(&cliente[*pos], sizeof(Cliente), 1, arquivo)) {
        (*pos)++;
        if (*pos >= TOTAL) {
            fclose(arquivo);
            return OK;
        }
    }

    fclose(arquivo);
    return OK;
}

ERROS salvar(Cliente cliente[], int pos) {
    FILE *arquivo = fopen(FILENAME, "wb");
    if (!arquivo) {
        return ERRO_ABRIR_ARQUIVO;
    }

    for (int i = 0; i < pos; i++) {
        if (fwrite(&cliente[i], sizeof(Cliente), 1, arquivo) != 1) {
            fclose(arquivo);
            return ERRO_ESCREVER_ARQUIVO;
        }
    }

    fclose(arquivo);
    return OK;
}
