#define TOTAL 1000
#define TAM_NOME 300
#define TAM_tipodeconta 300

typedef struct {
    char Nome[TAM_NOME];
    int CPF;
    char Tipo_de_conta[TAM_tipodeconta];
    int Saldo_inicial;
    int Saldo_atual;
    int Senha;
} Cliente;

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, SENHA} ERROS;

typedef ERROS (*funcao)(cliente[], int*);