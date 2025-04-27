%{
#include <stdio.h>
#include <stdlib.h>

/* 
   Declarações explícitas para evitar warnings de 
   "implicit declaration of function yylex/yyerror"
*/
int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

%}

%token NUM
%token IF ELSE SWITCH CASE DEFAULT BREAK WHILE RETURN
%token ID
%token EQ ASSIGN PLUS MINUS MULT DIV
%token COLON SEMICOLON LBRACE RBRACE LPAREN RPAREN
%token STRING
%token INT FLOAT CHAR VOID DOUBLE

/* Declaração de precedência e associatividade */
%left ASSIGN
%left EQ
%left PLUS MINUS
%left MULT DIV
%nonassoc IFX
%nonassoc ELSE

%union {
    int intValue;
    char* strValue;
}

%type <intValue> NUM
%type <strValue> ID STRING

%%
/* A gramática */
programa:
    declaracoes
    ;

declaracoes:
    declaracao
    | declaracoes declaracao
    | /* vazio */
    ;

declaracao:
    comando
    | declaracao_variavel SEMICOLON    
    ;

comando:
    IF LPAREN expressao RPAREN comando %prec IFX
    | IF LPAREN expressao RPAREN comando ELSE comando
    | WHILE LPAREN expressao RPAREN comando
    | RETURN expressao SEMICOLON
    | expressao SEMICOLON
    | bloco
    ;

bloco:
    LBRACE declaracoes RBRACE
    ;

expressao:
    ID ASSIGN expressao
    | expressao EQ expressao
    | expressao PLUS expressao
    | expressao MINUS expressao
    | expressao MULT expressao
    | expressao DIV expressao
    | LPAREN expressao RPAREN
    | NUM
    | ID
    | STRING
    ;

switch_stmt:
    SWITCH LPAREN expressao RPAREN LBRACE case_list RBRACE
    ;

case_list:
    case_list case_stmt
    | case_stmt
    ;

case_stmt:
    CASE expressao COLON comandos_break
    | DEFAULT COLON comandos_break
    ;

comandos_break:
    comandos_opt BREAK SEMICOLON
    ;

comandos_opt:
    /* vazio */
    | declaracoes
    ;

declaracao_variavel:
    tipo lista_variaveis
    ;

tipo:
    TIPO_INT
    | TIPO_FLOAT
    | TIPO_CHAR
    | TIPO_VOID
    | TIPO_DOUBLE
    ;

lista_variaveis:
    variavel
    | lista_variaveis ',' variavel
    ;

variavel:
    ID
    | ID ASSIGN expressao
    ;

%%

/* Definição de yyerror */
void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}