#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simbolos.h"

static Escopo *escopoAtual = NULL;

static unsigned hash(char *s)
{
    unsigned h = 0;
    while (*s)
        h = (h << 4) + *s++;
    return h % TAM_HASH;
}

void iniciarTabelaSimbolos(void)
{
    escopoAtual = (Escopo *)malloc(sizeof(Escopo));
    if (escopoAtual == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para o escopo global\n");
        exit(1);
    }

    escopoAtual->nivel = 0;
    escopoAtual->anterior = NULL;
    for (int i = 0; i < TAM_HASH; i++)
    {
        escopoAtual->tabela[i] = NULL;
    }
}

void finalizarTabelaSimbolos(void)
{
    while (escopoAtual != NULL)
    {
        Escopo *temp = escopoAtual;
        escopoAtual = escopoAtual->anterior;

        for (int i = 0; i < TAM_HASH; i++)
        {
            Simbolo *s = temp->tabela[i];
            while (s != NULL)
            {
                Simbolo *prox = s->proximo;
                free(s);
                s = prox;
            }
        }
        free(temp);
    }
}

void iniciarEscopo(void)
{
    Escopo *novo = (Escopo *)malloc(sizeof(Escopo));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para novo escopo\n");
        exit(1);
    }

    novo->nivel = escopoAtual->nivel + 1;
    novo->anterior = escopoAtual;

    for (int i = 0; i < TAM_HASH; i++)
    {
        novo->tabela[i] = NULL;
    }

    escopoAtual = novo;
}

void finalizarEscopo(void)
{
    if (escopoAtual == NULL || escopoAtual->anterior == NULL)
    {
        fprintf(stderr, "Erro: Tentativa de finalizar escopo global\n");
        return;
    }

    Escopo *temp = escopoAtual;
    escopoAtual = escopoAtual->anterior;

    for (int i = 0; i < TAM_HASH; i++)
    {
        Simbolo *s = temp->tabela[i];
        while (s != NULL)
        {
            Simbolo *prox = s->proximo;
            free(s);
            s = prox;
        }
    }
    free(temp);
}

int nivelEscopoAtual(void)
{
    return escopoAtual->nivel;
}

Simbolo *inserirSimbolo(char *nome, TipoSimbolo tipo)
{
    if (nome == NULL)
    {
        fprintf(stderr, "Erro: Nome do símbolo não pode ser NULL\n");
        return NULL;
    }

    unsigned i = hash(nome);

    Simbolo *existente = buscarSimboloNoEscopoAtual(nome);
    if (existente != NULL)
    {
        return NULL;
    }

    Simbolo *s = (Simbolo *)malloc(sizeof(Simbolo));
    if (s == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para novo símbolo\n");
        return NULL;
    }

    strncpy(s->nome, nome, TAM_NOME - 1);
    s->nome[TAM_NOME - 1] = '\0';
    s->tipo = tipo;
    s->nivel = escopoAtual->nivel;
    s->proximo = escopoAtual->tabela[i];
    escopoAtual->tabela[i] = s;

    return s;
}

Simbolo *buscarSimbolo(char *nome)
{
    if (nome == NULL)
        return NULL;

    Escopo *escopo = escopoAtual;
    while (escopo != NULL)
    {
        unsigned i = hash(nome);
        for (Simbolo *s = escopo->tabela[i]; s != NULL; s = s->proximo)
        {
            if (strcmp(s->nome, nome) == 0)
            {
                return s;
            }
        }
        escopo = escopo->anterior;
    }
    return NULL;
}

Simbolo *buscarSimboloNoEscopoAtual(char *nome)
{
    if (nome == NULL)
        return NULL;

    unsigned i = hash(nome);
    for (Simbolo *s = escopoAtual->tabela[i]; s != NULL; s = s->proximo)
    {
        if (strcmp(s->nome, nome) == 0)
        {
            return s;
        }
    }
    return NULL;
}

void imprimirSimbolo(Simbolo *s)
{
    if (s == NULL)
        return;
    const char *tipo_str;
    switch (s->tipo)
    {
    case TIPO_INT:
        tipo_str = "int";
        break;
    case TIPO_FLOAT:
        tipo_str = "float";
        break;
    case TIPO_ERRO:
        tipo_str = "erro";
        break;
    default:
        tipo_str = "desconhecido";
    }
    printf("Nome: %-20s Tipo: %-10s Nível: %d\n",
           s->nome, tipo_str, s->nivel);
}

void imprimirEscopoAtual(void)
{
    printf("\n=== Escopo Nível %d ===\n", escopoAtual->nivel);
    for (int i = 0; i < TAM_HASH; i++)
    {
        for (Simbolo *s = escopoAtual->tabela[i]; s != NULL; s = s->proximo)
        {
            imprimirSimbolo(s);
        }
    }
    printf("=====================\n");
}

void imprimirTabelaSimbolos(void)
{
    printf("\n=== Tabela de Símbolos Completa ===\n");
    Escopo *escopo = escopoAtual;
    while (escopo != NULL)
    {
        printf("\n--- Escopo Nível %d ---\n", escopo->nivel);
        for (int i = 0; i < TAM_HASH; i++)
        {
            for (Simbolo *s = escopo->tabela[i]; s != NULL; s = s->proximo)
            {
                imprimirSimbolo(s);
            }
        }
        escopo = escopo->anterior;
    }
    printf("\n================================\n");
}