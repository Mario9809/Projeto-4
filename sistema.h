#define TOTAL 1000
#define TAM_NOME 300
#define TAM_tipodeconta 300
#define TAM_CPF 300

typedef struct {
    char Nome[TAM_NOME];
    int CPF;
    char Tipo_de_conta[TAM_tipodeconta];
    int Saldo_inicial;
    int Saldo_atual;
    int Senha;
} Cliente;

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, SENHA} ERROS;

typedef ERROS (*funcao)(Cliente[], int*);


ERROS Novo_cliente(Cliente cliente[], int *pos) 

ERROS Listar_clientes(Cliente cliente[], int *pos)

ERROS Apagar_cliente(Cliente cliente[], int *pos) 

ERROS Débito(Cliente cliente[], int *pos) 

ERROS Depósito(Cliente cliente[], int *pos)

ERROS Extrato(Cliente cliente[], int *pos)
    
ERROS Transferência_entre_contas(Cliente cliente[], int *pos)
