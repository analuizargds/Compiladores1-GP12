%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

%}

%token NUM
%token IF ELSE SWITCH CASE DEFAULT BREAK WHILE RETURN DO FOR CONTINUE
%token ID
%token EQ ASSIGN PLUS MINUS MULT DIV MOD
%token GE LE GT LT
%token COLON SEMICOLON LBRACE RBRACE LPAREN RPAREN
%token STRING
%token COMMA
%token DOT
%token INT FLOAT CHAR VOID DOUBLE
%token CHAR_LITERAL
%token STRUCT UNION ENUM TYPEDEF
%token HEX CARACT
%token INCREMENT DECREMENT
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN

/* Declaração de precedência e associatividade */
%right ASSIGN
%left EQ GE LE GT LT
%left PLUS MINUS
%left MULT DIV
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%nonassoc IFX

%union {
    int intValue;
    float floatValue;
    char* strValue;
    char charValue;
}

%type <intValue> NUM
%type <floatValue> FLOAT
%type <strValue> ID STRING
%type <charValue> CHAR_LITERAL

%%
programa:
    lista_declaracoes
    ;

lista_declaracoes:
    lista_declaracoes declaracao
    | declaracao
    ;

declaracao:
    declaracao_variavel SEMICOLON
    | fun_declaracao
    | stmt
    | declaracao_tipo
    ;

declaracao_tipo:
    struct_declaracao
    | union_declaracao
    | enum_declaracao
    | typedef_declaracao
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE
    ;

for_init:
    expr
    | declaracao_variavel
    | /* vazio */
    ;

for_parer:
    expr
    | /* vazio */
    ;

for_stmt:
    FOR LPAREN for_init SEMICOLON for_parer SEMICOLON for_parer RPAREN stmt
    ;

do_stmt:
    DO stmt WHILE LPAREN expr RPAREN SEMICOLON
    ;

continue_stmt:
    CONTINUE SEMICOLON
    ;


case_list:
    case_list case_stmt
    | case_stmt
    ;

case_stmt:
    CASE expr COLON comandos_break
    | DEFAULT COLON comandos_break
    ;

comandos_break:
    comandos_opt BREAK SEMICOLON
    ;

comandos_opt:
    /* vazio */
    | lista_declaracoes
    ;

declaracao_variavel:
    tipo lista_variaveis
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
    | lista_variaveis COMMA variavel
    ;

variavel:
    ID
    | ID ASSIGN expr
    ;

fun_declaracao:
    tipo ID LPAREN parametros RPAREN composto_stmt
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
    tipo ID
    ;

stmt:
    expr_stmt
    | composto_stmt
    | if_stmt
    | while_stmt
    | return_stmt
    | switch_stmt
    | do_stmt
    | for_stmt
    | continue_stmt
    ;

expr_stmt:
    expr SEMICOLON
    | SEMICOLON
    ;

composto_stmt:
    LBRACE lista_declaracoes RBRACE
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE
    | IF LPAREN expr RPAREN stmt ELSE stmt
    ;

while_stmt:
    WHILE LPAREN expr RPAREN stmt
    ;

return_stmt:
    RETURN expr SEMICOLON
    | RETURN SEMICOLON
    ;

expr:
    var ASSIGN expr
    | var PLUS_ASSIGN expr
    | var MINUS_ASSIGN expr
    | var MULT_ASSIGN expr
    | var DIV_ASSIGN expr
    | relacao_expr
    ;

var:
    ID
    | var DOT ID
    | var INCREMENT
    | var DECREMENT
    ;

relacao_expr:
    add_expr
    | add_expr EQ add_expr
    | add_expr GE add_expr
    | add_expr LE add_expr
    | add_expr GT add_expr
    | add_expr LT add_expr
    ;

add_expr:
    add_expr PLUS mult_expr
    | add_expr MINUS mult_expr
    | mult_expr
    ;

mult_expr:
    mult_expr MULT fator
    | mult_expr DIV fator
    | mult_expr MOD fator
    | fator
    ;

fator:
    LPAREN expr RPAREN
    | var
    | chamada
    | NUM
    | FLOAT
    | HEX
    | CHAR_LITERAL
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

struct_declaracao:
    STRUCT ID LBRACE lista_declaracoes RBRACE SEMICOLON
    ;

union_declaracao:
    UNION ID LBRACE lista_declaracoes RBRACE SEMICOLON
    ;

enum_declaracao:
    ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON
    ;

typedef_declaracao:
    TYPEDEF tipo ID SEMICOLON
    ;

lista_identificadores:
    ID
    | lista_identificadores COMMA ID
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}
