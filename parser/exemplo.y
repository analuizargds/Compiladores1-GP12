%{
#include <stdio.h>
#include <stdlib.h>

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
%token COMMA

/* Declaração de precedência e associatividade */
%right ASSIGN
%left EQ
%left PLUS MINUS
%left MULT DIV
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%union {
    int intValue;
    char* strValue;
}

%type <intValue> NUM
%type <strValue> ID STRING

%%
programa:
    lista_declaracoes
    ;

lista_declaracoes:
    lista_declaracoes declaracao 
    | declaracao
    ;

declaracao:
    fun_declaracao
    | stmt
    ;

fun_declaracao:
    ID LPAREN parametros RPAREN composto_stmt
    ;

parametros:
    lista_parametros
    | /* vazio */
    ;

lista_parametros:
    lista_parametros COMMA param
    | param
    ;

param:
    ID
    ;

stmt:
    expr_stmt
    | composto_stmt
    | if_stmt
    | while_stmt
    | return_stmt
    ;

expr_stmt:
    expr SEMICOLON
    | SEMICOLON
    ;

composto_stmt:
    LBRACE declaracoes_stmt RBRACE
    ;

declaracoes_stmt:
    declaracoes_stmt stmt
    | /* vazio */
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE
    | IF LPAREN expr RPAREN stmt ELSE stmt
    ;

while_stmt:
    WHILE LPAREN expr RPAREN stmt
    ;

return_stmt:
    RETURN SEMICOLON
    | RETURN expr SEMICOLON
    ;

expr:
    var ASSIGN expr
    | relacao_expr
    ;

var:
    ID
    ;

relacao_expr:
    add_expr
    | add_expr EQ add_expr
    ;

add_expr:
    add_expr PLUS mult_expr
    | add_expr MINUS mult_expr
    | mult_expr
    ;

mult_expr:
    mult_expr MULT fator
    | mult_expr DIV fator
    | fator
    ;

fator:
    LPAREN expr RPAREN
    | var
    | chamada
    | NUM
    | STRING
    ;

chamada:
    ID LPAREN argumentos RPAREN
    ;

argumentos:
    lista_args
    | /* vazio */
    ;

lista_args:
    lista_args COMMA expr
    | expr
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}