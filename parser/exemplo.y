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
%token IF ELSE WHILE RETURN
%token ID
%token EQ ASSIGN PLUS MINUS MULT DIV
%token SEMICOLON LBRACE RBRACE LPAREN RPAREN
%token STRING
%token INT FLOAT CHAR VOID DOUBLE
%token STRUCT UNION ENUM TYPEDEF 
%token HEX OCT DIGIT CARACT

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
    declaracao_variavel SEMICOLON
    | comando
    ;

declaracao_variavel:
    tipo lista_variaveis
    | typedef_declaracao
    | struct_declaracao
    | union_declaracao
    | enum_declaracao
    ;

tipo:
    INT
    | FLOAT
    | CHAR
    | VOID
    | DOUBLE
    | STRUCT ID
    | UNION ID
    | ENUM ID
    ;

lista_variaveis:
    variavel
    | lista_variaveis ',' variavel
    ;

variavel:
    ID
    | ID ASSIGN expressao
    ;

struct_declaracao:
    STRUCT ID LBRACE declaracoes RBRACE SEMICOLON
    ;

union_declaracao:
    UNION ID LBRACE declaracoes RBRACE SEMICOLON
    ;

enum_declaracao:
    ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON
    ;

lista_identificadores:
    ID
    | lista_identificadores ',' ID
    ;

typedef_declaracao:
    TYPEDEF tipo ID SEMICOLON
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

%%

/* Definição de yyerror */
void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}