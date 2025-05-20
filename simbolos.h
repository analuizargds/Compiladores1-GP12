#ifndef SIMBOLOS_H
#define SIMBOLOS_H

// adaptar quando tiver a AST
typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_ERRO
} TipoSimbolo;

#define TAM_HASH 211
#define TAM_NOME 32

typedef struct simbolo
{
    char nome[TAM_NOME];
    TipoSimbolo tipo;
    int nivel;
    struct simbolo *proximo;
} Simbolo;

typedef struct escopo
{
    int nivel;
    Simbolo *tabela[TAM_HASH];
    struct escopo *anterior;
} Escopo;

void iniciarTabelaSimbolos(void);
void finalizarTabelaSimbolos(void);

void iniciarEscopo(void);
void finalizarEscopo(void);
int nivelEscopoAtual(void);

Simbolo *inserirSimbolo(char *nome, TipoSimbolo tipo);
Simbolo *buscarSimbolo(char *nome);
Simbolo *buscarSimboloNoEscopoAtual(char *nome);

void imprimirTabelaSimbolos(void);
void imprimirEscopoAtual(void);
void imprimirSimbolo(Simbolo *s);

#endif