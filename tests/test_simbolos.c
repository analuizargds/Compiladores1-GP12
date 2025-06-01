#include <stdio.h>
#include <assert.h>
#include "../simbolos.h"

void test_insercao_busca()
{
    printf("\n=== Teste de Inserção e Busca ===\n");

    iniciarTabelaSimbolos();

    Simbolo *s1 = inserirSimbolo("var1", TIPO_INT);
    assert(s1 != NULL);
    assert(s1->nivel == 0);
    assert(s1->tipo == TIPO_INT);

    Simbolo *b1 = buscarSimbolo("var1");
    assert(b1 != NULL);
    assert(b1 == s1);

    Simbolo *s2 = inserirSimbolo("var2", TIPO_FLOAT);
    assert(s2 != NULL);
    assert(s2->nivel == 0);
    assert(s2->tipo == TIPO_FLOAT);

    Simbolo *s3 = inserirSimbolo("var1", TIPO_INT);
    assert(s3 == NULL);

    finalizarTabelaSimbolos();
    printf("Teste de inserção e busca passou!\n");
}

void test_escopos()
{
    printf("\n=== Teste de Escopos ===\n");

    iniciarTabelaSimbolos();

    inserirSimbolo("global", TIPO_INT);

    iniciarEscopo();
    assert(nivelEscopoAtual() == 1);
    inserirSimbolo("local1", TIPO_FLOAT);

    iniciarEscopo();
    assert(nivelEscopoAtual() == 2);
    inserirSimbolo("local2", TIPO_INT);

    Simbolo *s1 = buscarSimboloNoEscopoAtual("local2");
    assert(s1 != NULL);
    assert(s1->nivel == 2);

    Simbolo *s2 = buscarSimbolo("local1");
    assert(s2 != NULL);
    assert(s2->nivel == 1);

    Simbolo *s3 = buscarSimbolo("global");
    assert(s3 != NULL);
    assert(s3->nivel == 0);

    Simbolo *s4 = inserirSimbolo("global", TIPO_FLOAT);
    assert(s4 != NULL);
    assert(s4->nivel == 2);

    finalizarEscopo();
    assert(nivelEscopoAtual() == 1);

    finalizarEscopo();
    assert(nivelEscopoAtual() == 0);

    assert(buscarSimboloNoEscopoAtual("local1") == NULL);
    assert(buscarSimboloNoEscopoAtual("local2") == NULL);

    finalizarTabelaSimbolos();
    printf("Teste de escopos passou!\n");
}

void test_impressao()
{
    printf("\n=== Teste de Impressão ===\n");

    iniciarTabelaSimbolos();

    inserirSimbolo("x", TIPO_INT);
    inserirSimbolo("y", TIPO_FLOAT);

    printf("\nImprimindo escopo global:\n");
    imprimirEscopoAtual();

    iniciarEscopo();
    inserirSimbolo("z", TIPO_INT);

    printf("\nImprimindo escopo interno:\n");
    imprimirEscopoAtual();

    printf("\nImprimindo tabela completa:\n");
    imprimirTabelaSimbolos();

    finalizarEscopo();
    finalizarTabelaSimbolos();
    printf("Teste de impressão completo!\n");
}

void test_erros()
{
    printf("\n=== Teste de Tratamento de Erros ===\n");

    iniciarTabelaSimbolos();

    Simbolo *s1 = inserirSimbolo(NULL, TIPO_INT);
    assert(s1 == NULL);

    Simbolo *s2 = buscarSimbolo(NULL);
    assert(s2 == NULL);

    finalizarEscopo();

    Simbolo *s3 = buscarSimbolo("inexistente");
    assert(s3 == NULL);

    finalizarTabelaSimbolos();
    printf("Teste de erros passou!\n");
}

int main()
{
    printf("Iniciando testes da tabela de símbolos...\n");

    test_insercao_busca();
    test_escopos();
    test_impressao();
    test_erros();

    printf("\nTodos os testes passaram com sucesso!\n");
    return 0;
}