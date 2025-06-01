%{
#include <stdio.h>
#include <stdlib.h>
#include "simbolos.h"
#include "../ast/ast.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
ASTNode* root;
int tipoDeclaracaoAtual;
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
    struct ASTNode* node;
}

%type <intValue> NUM
%type <floatValue> FLOAT
%type <strValue> ID STRING
%type <charValue> CHAR_LITERAL
%type <intValue> tipo

%type <node> programa lista_declaracoes declaracao
%type <node> stmt expr atrib_expr or_expr and_expr bitor_expr bitxor_expr
%type <node> bitand_expr equal_expr relacao_expr shift_expr add_expr mult_expr
%type <node> unary_expr fator var chamada argumentos lista_args
%type <node> declaracao_variavel lista_variaveis variavel
%type <node> fun_declaracao parametros lista_parametros param
%type <node> composto_stmt if_stmt while_stmt return_stmt for_stmt do_stmt
%type <node> continue_stmt switch_stmt
%type <node> case_list case_stmt comandos_break comandos_opt

%%

programa:
    { iniciarTabelaSimbolos(); }
    lista_declaracoes 
    { 
        root = $1;
        imprimirTabelaSimbolos(); 
        finalizarTabelaSimbolos(); 
    }
;

lista_declaracoes:
    lista_declaracoes declaracao { $$ = concatenarStmt($1, $2); }
    | declaracao { $$ = $1; }
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
    { 
        $$ = criarNoFor($3, $5, $7, $9); 
    }
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
    tipo 
    {
        $$ = criarNoType($1);
    }
    lista_variaveis 
    { 
        $$ = criarNoVarDecl($3->valor_str); 
    }
;

tipo:
    INT         { $$ = TIPO_INT; }
  | FLOAT       { $$ = TIPO_FLOAT; }
  | CHAR        { $$ = TIPO_ERRO; }
  | VOID        { $$ = TIPO_ERRO; }
  | DOUBLE      { $$ = TIPO_ERRO; }
  | STRUCT ID   { $$ = TIPO_ERRO; }
  | UNION ID    { $$ = TIPO_ERRO; }
  | ENUM ID     { $$ = TIPO_ERRO; }
;

lista_variaveis:
    variavel
    | lista_variaveis COMMA variavel
    ;

variavel:
    ID 
    {
        if (buscarSimboloNoEscopoAtual($1) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo($1, tipoDeclaracaoAtual);
        }
        $$ = criarNoVar($1);
    }
    |
    ID ASSIGN expr 
    {
        if (buscarSimboloNoEscopoAtual($1) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo($1, tipoDeclaracaoAtual);
        }
        $$ = criarNoAssign('=', criarNoVar($1), $3);
    }
    |
    ID ASSIGN inicializador 
    {
        if (buscarSimboloNoEscopoAtual($1) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo($1, tipoDeclaracaoAtual);
        }
        $$ = criarNoAssign('=', criarNoVar($1), $3);
    }
;

fun_declaracao:
    tipo ID LPAREN parametros RPAREN
    {
        if (buscarSimboloNoEscopoAtual($2) != NULL) {
            yyerror("Erro: Função já declarada");
        } else {
            inserirSimbolo($2, $1); // $1 = tipo de retorno
        }
        iniciarEscopo();
    }
    composto_stmt
    {
        finalizarEscopo();
    }
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
    {
        if (buscarSimboloNoEscopoAtual($2) != NULL) {
            yyerror("Erro: Parâmetro já declarado");
        } else {
            inserirSimbolo($2, $1); // $1 = tipo do parâmetro
        }
    }
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
    LBRACE lista_declaracoes RBRACE { $$ = criarNoBlock($2); }
    | LBRACE RBRACE { $$ = criarNoBlock(NULL); }
;

if_stmt:
    IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE { $$ = criarNoIf($3, $5, NULL); }
    | IF LPAREN expr RPAREN stmt ELSE stmt { $$ = criarNoIf($3, $5, $7); }
;

while_stmt:
    WHILE LPAREN expr RPAREN stmt { $$ = criarNoWhile($3, $5); }
;

return_stmt:
    RETURN expr SEMICOLON { $$ = criarNoReturn($2); }
    | RETURN SEMICOLON { $$ = criarNoReturn(NULL); }
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
    mult_expr { $$ = $1; }
    | add_expr PLUS mult_expr { $$ = criarNoBinOp('+', $1, $3); }
    | add_expr MINUS mult_expr { $$ = criarNoBinOp('-', $1, $3); }
;

mult_expr:
    unary_expr { $$ = $1; }
    | mult_expr MULT unary_expr { $$ = criarNoBinOp('*', $1, $3); }
    | mult_expr DIV unary_expr { $$ = criarNoBinOp('/', $1, $3); }
    | mult_expr MOD unary_expr { $$ = criarNoBinOp('%', $1, $3); }
;

unary_expr:
    fator { $$ = $1; }
    | NOT unary_expr { $$ = criarNoUnaryOp('!', $2); }
    | BITNOT unary_expr { $$ = criarNoUnaryOp('~', $2); }
    | MINUS unary_expr %prec UMINUS { $$ = criarNoUnaryOp('-', $2); }
    | PLUS unary_expr %prec UPLUS { $$ = criarNoUnaryOp('+', $2); }
;

fator:
    LPAREN expr RPAREN { $$ = $2; }
    | var { $$ = $1; }
    | chamada { $$ = $1; }
    | var INCREMENT
    | var DECREMENT
    | NUM { $$ = criarNoInt($1); }
    | FLOAT { $$ = criarNoFloat($1); }
    | HEX { $$ = criarNoHex($1); }
    | CHAR_LITERAL { $$ = criarNoChar($1); }
    | STRING { $$ = criarNoString($1); }
;

var:
    ID
    {
        if (buscarSimbolo($1) == NULL) {
            yyerror("Erro: Variável usada sem declaração");
        }
    }
    |
    var DOT ID
;

chamada:
    ID LPAREN argumentos RPAREN { $$ = criarNoCall($1, $3); }
;

argumentos:
    lista_args { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
;

lista_args:
    lista_args COMMA expr { $$ = concatenarArg($1, $3); }
    | expr { $$ = $1; }
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