#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <string.h>

#define TOTAL 1000
#define TAM_NOME 1000
#define TAM_SOBRENOME 1000
#define TAM_tipodeconta 300
#define TAM_CPF 300

typedef struct {
    char Nome[TAM_NOME];
    char Sobrenome[TAM_SOBRENOME];
    int CPF;
    char Tipo_de_conta[TAM_tipodeconta];
    float Saldo_inicial;
    float Saldo_atual; // Alterado para float para permitir valores decimais
    char Senha[16]; // Alterado para uma string para armazenar a senha
} Cliente;

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, SENHA, SALDO_INSUFICIENTE} ERROS;

void clearBuffer();

ERROS Novo_cliente(Cliente cliente[], int *pos);

ERROS Listar_clientes(Cliente cliente[], int *pos);

ERROS Apagar_cliente(Cliente cliente[], int *pos); 

ERROS Debito(Cliente cliente[], int *pos); 

ERROS Deposito(Cliente cliente[], int *pos);

ERROS Extrato(Cliente cliente[], int *pos);

ERROS Transferencia_entre_contas(Cliente cliente[], int *pos);

ERROS carregar(Cliente cliente[], int *pos);

#endif /* SISTEMA_H */