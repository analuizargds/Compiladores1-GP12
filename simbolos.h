#ifndef SIMBOLOS_H
#define SIMBOLOS_H

#include "ast/ast.h"

typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR,
    TIPO_VOID,
    TIPO_DOUBLE,
    TIPO_STRUCT,
    TIPO_UNION,
    TIPO_ENUM,
    TIPO_FUNCAO,
    TIPO_ERRO,
    TIPO_VARIAVEL
} TipoSimbolo;

#define TAM_HASH 211
#define TAM_NOME 32

typedef struct simbolo
{
    char nome[TAM_NOME];
    TipoSimbolo tipo;
    int nivel;
    ASTNode *ast_node;
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