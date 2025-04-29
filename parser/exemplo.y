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
%token GE LE GT LT NE EQ
%token ASSIGN PLUS MINUS MULT DIV MOD
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
%token AND OR NOT
%token BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
%left OR
%left AND
%left BITOR
%left BITXOR
%left BITAND
%left EQ NE
%left GE LE GT LT
%left SHIFTLEFT SHIFTRIGHT
%left PLUS MINUS
%left MULT DIV MOD
%right UMINUS UPLUS
%right NOT BITNOT
%right INCREMENT DECREMENT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

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
    | ID ASSIGN inicializador
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

inicializador:
    LBRACE lista_inicializadores RBRACE
    ;

lista_inicializadores:
    expr
    | lista_inicializadores COMMA expr
    | /* vazio */
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
    | LBRACE RBRACE
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
    atrib_expr
    ;

atrib_expr:
    or_expr
    | var ASSIGN atrib_expr
    | var PLUS_ASSIGN atrib_expr
    | var MINUS_ASSIGN atrib_expr
    | var MULT_ASSIGN atrib_expr
    | var DIV_ASSIGN atrib_expr
    ;

or_expr:
    and_expr
    | or_expr OR and_expr
    ;

and_expr:
    bitor_expr
    | and_expr AND bitor_expr
    ;

bitor_expr:
    bitxor_expr
    | bitor_expr BITOR bitxor_expr
    ;

bitxor_expr:
    bitand_expr
    | bitxor_expr BITXOR bitand_expr
    ;

bitand_expr:
    equal_expr
    | bitand_expr BITAND equal_expr
    ;

equal_expr:
    relacao_expr
    | equal_expr EQ relacao_expr
    | equal_expr NE relacao_expr
    ;

relacao_expr:
    shift_expr
    | relacao_expr GT shift_expr
    | relacao_expr LT shift_expr
    | relacao_expr GE shift_expr
    | relacao_expr LE shift_expr
    ;

shift_expr:
    add_expr
    | shift_expr SHIFTLEFT add_expr
    | shift_expr SHIFTRIGHT add_expr
    ;

add_expr:
    mult_expr
    | add_expr PLUS mult_expr
    | add_expr MINUS mult_expr
    ;

mult_expr:
    unary_expr
    | mult_expr MULT unary_expr
    | mult_expr DIV unary_expr
    | mult_expr MOD unary_expr
    ;

unary_expr:
    fator
    | INCREMENT var
    | DECREMENT var
    | NOT unary_expr
    | BITNOT unary_expr
    | MINUS unary_expr %prec UMINUS
    | PLUS unary_expr %prec UPLUS
    ;

fator:
    LPAREN expr RPAREN
    | var
    | chamada
    | var INCREMENT
    | var DECREMENT
    | NUM
    | FLOAT
    | HEX
    | CHAR_LITERAL
    | STRING
    ;

var:
    ID
    | var DOT ID
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
