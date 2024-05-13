#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <string.h>

#define TOTAL 1000
#define TAM_NOME 1000
#define TAM_SOBRENOME 1000
#define TAM_TIPO_CONTA 300
#define TAM_CPF 300
#define MAX_OPERACOES 100

typedef struct {
    char Nome[TAM_NOME];
    char Sobrenome[TAM_SOBRENOME];
    int CPF;
    char Tipo_de_conta[TAM_TIPO_CONTA];
    float Saldo_inicial;
    float Saldo_atual;
    char Senha[16];
    int num_operacoes;  // Número de operações realizadas
    float operacoes[MAX_OPERACOES];  // Registro das operações
} Cliente;

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, SENHA, SALDO_INSUFICIENTE, ERRO_ABRIR_ARQUIVO, ERRO_ESCREVER_ARQUIVO} ERROS;

void clearBuffer();

ERROS Novo_cliente(Cliente cliente[], int *pos);

ERROS Listar_clientes(Cliente cliente[], int *pos);

ERROS Apagar_cliente(Cliente cliente[], int *pos); 

ERROS Debito(Cliente cliente[], int *pos); 

ERROS Deposito(Cliente cliente[], int *pos);

ERROS Extrato(Cliente cliente[], int *pos);

ERROS Transferencia_entre_contas(Cliente cliente[], int *pos);

ERROS carregar(Cliente cliente[], int *pos);

ERROS salvar(Cliente cliente[], int pos);

#endif /* SISTEMA_H */
