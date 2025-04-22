%{
#include <stdio.h>
#include <stdlib.h>

/* Declarações para o parser */
int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
%}

/* Tokens básicos compartilhados */
%token SEMICOLON COMMA
%token LBRACE RBRACE LPAREN RPAREN
%token ASSIGN

/* Cada pessoa adicionará seus tokens e tipos aqui */
/* ------ TOKENS PESSOA 1 ------ */
/* Adicione seus tokens aqui */

/* ------ TOKENS PESSOA 2 ------ */
/* Adicione seus tokens aqui */

/* ------ TOKENS PESSOA 3 ------ */
/* Adicione seus tokens aqui */

/* ------ TOKENS PESSOA 4 ------ */
/* Adicione seus tokens aqui */

/* ------ TOKENS PESSOA 5 ------ */
/* Adicione seus tokens aqui */

/* ------ TOKENS PESSOA 6 ------ */
/* Adicione seus tokens aqui */

/* Definições de tipo para o parser */
%union {
    int intValue;
    float floatValue;
    char* strValue;
}

/* Regras de precedência e associatividade */
%left ASSIGN
/* Adicione suas próprias regras de precedência */

%%
/* Regra inicial e estrutura básica */
programa:
    declaracoes
    ;

declaracoes:
    declaracao
    | declaracoes declaracao
    | /* vazio */
    ;

declaracao:
    ;

/* ------ ÁREA PESSOA 1: TIPOS BÁSICOS E DECLARAÇÕES ------ */
/* Adicione suas regras gramaticais aqui */

/* ------ ÁREA PESSOA 2: OPERADORES E EXPRESSÕES ------ */
/* Adicione suas regras gramaticais aqui */

/* ------ ÁREA PESSOA 3: ESTRUTURAS CONDICIONAIS ------ */
/* Adicione suas regras gramaticais aqui */

/* ------ ÁREA PESSOA 4: ESTRUTURAS DE REPETIÇÃO ------ */
/* Adicione suas regras gramaticais aqui */

/* ------ ÁREA PESSOA 5: FUNÇÕES E ESCOPO ------ */
/* Adicione suas regras gramaticais aqui */

/* ------ ÁREA PESSOA 6: TIPOS COMPLEXOS E CONSTANTES ------ */
/* Adicione suas regras gramaticais aqui */

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) {
            yyin = f;
        } else {
            fprintf(stderr, "Não foi possível abrir o arquivo: %s\n", argv[1]);
            return 1;
        }
    }
    
    printf("Iniciando análise...\n");
    int result = yyparse();
    printf("Análise concluída com código: %d\n", result);
    
    return result;
}