%{
#include <stdio.h>
#include <stdlib.h>
#include "../ast/ast.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
ASTNode* root;
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
%type <strValue> HEX

%type <node> programa lista_declaracoes declaracao
%type <node> stmt expr atrib_expr or_expr and_expr bitor_expr bitxor_expr
%type <node> bitand_expr equal_expr relacao_expr shift_expr add_expr mult_expr
%type <node> unary_expr fator var chamada argumentos lista_args
%type <node> declaracao_variavel lista_variaveis variavel
%type <node> fun_declaracao parametros lista_parametros param
%type <node> composto_stmt if_stmt while_stmt return_stmt for_stmt do_stmt
%type <node> continue_stmt switch_stmt
%type <node> case_list case_stmt comandos_break comandos_opt
%type <node> declaracao_tipo struct_declaracao union_declaracao enum_declaracao typedef_declaracao
%type <node> tipo expr_stmt lista_identificadores
%type <node> inicializador lista_inicializadores
%type <node> for_parer for_init

%%

programa:
    lista_declaracoes { root = $1; }
;

lista_declaracoes:
    lista_declaracoes declaracao { $$ = concatenarStmt($1, $2); }
    | declaracao { $$ = $1; }
;

declaracao:
    declaracao_variavel SEMICOLON { $$ = $1; }
    | fun_declaracao { $$ = $1; }
    | stmt { $$ = $1; }
    | declaracao_tipo { $$ = $1; }
    ;

declaracao_tipo:
    struct_declaracao { $$ = $1; }
    | union_declaracao { $$ = $1; }
    | enum_declaracao { $$ = $1; }
    | typedef_declaracao { $$ = $1; }
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE { $$ = criarNoSwitch($3, $6); }
    ;

for_stmt:
    FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt {
        $$ = criarNoFor($3, $5, $7, $9);
    }
;

for_init:
    expr { $$ = $1; }
    | declaracao_variavel { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
    ;

for_parer:
    expr { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
    ;

do_stmt:
    DO stmt WHILE LPAREN expr RPAREN SEMICOLON { $$ = criarNoDoWhile($5, $2); }
    ;

continue_stmt:
    CONTINUE SEMICOLON { $$ = criarNoContinue(); }
    ;

case_list:
    case_list case_stmt { $$ = concatenarStmt($1, $2); }
    | case_stmt { $$ = $1; }
    ;

case_stmt:
    CASE expr COLON comandos_break { $$ = criarNoCase($2, $4); }
    | DEFAULT COLON comandos_break { $$ = criarNoCase(NULL, $3); }
    ;

comandos_break:
    comandos_opt BREAK SEMICOLON { $$ = concatenarStmt($1, criarNoBreak()); }

comandos_opt:
    /* vazio */ { $$ = NULL; }
    | lista_declaracoes { $$ = $1; }
    ;

declaracao_variavel:
    tipo lista_variaveis { $$ = criarNoVarDecl($2->valor_str, criarNoType($1->valor_str)); }
;

tipo:
    INT { $$ = criarNoType("int"); }
    | FLOAT { $$ = criarNoType("float"); }
    | CHAR { $$ = criarNoType("char"); }
    | VOID { $$ = criarNoType("void"); }
    | DOUBLE { $$ = criarNoType("double"); }
    | STRUCT ID { $$ = criarNoUnion("struct", $2); }
    | UNION ID { $$ = criarNoUnion("union", $2); }
    | ENUM ID { $$ = criarNoEnum($2); }
    ;

lista_variaveis:
    variavel { $$ = $1; }
    | lista_variaveis COMMA variavel { $$ = concatenarStmt($1, $3); }
    ;

variavel:
    ID { $$ = criarNoVar($1); }
    | ID ASSIGN expr { $$ = criarNoAssign('=', criarNoVar($1), $3); }
    | ID ASSIGN inicializador { $$ = criarNoAssign('=', criarNoVar($1), $3); }
    ;

fun_declaracao:
    tipo ID LPAREN parametros RPAREN composto_stmt { $$ = criarNoFuncDecl($2, $1, $4, $6); }
    ;

parametros:
    lista_parametros { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
    ;

lista_parametros:
    lista_parametros COMMA param { $$ = concatenarParam($1, $3); }
    | param { $$ = $1; }
    ;

param:
    tipo ID { $$ = criarNoParam($2, $1); }
    ;

inicializador:
    LBRACE lista_inicializadores RBRACE { $$ = $2; }
    ;

lista_inicializadores:
    expr { $$ = criarNoInit($1, NULL); }
    | lista_inicializadores COMMA expr { $$ = criarNoInit($3, $1); }
    | /* vazio */ { $$ = NULL; }
    ;

stmt:
    expr_stmt { $$ = $1; }
    | composto_stmt { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    | switch_stmt { $$ = $1; }
    | do_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | continue_stmt { $$ = $1; }
    ;

expr_stmt:
    expr SEMICOLON { $$ = $1; }
    | SEMICOLON { $$ = NULL; }
    ;

composto_stmt:
    LBRACE lista_declaracoes RBRACE { $$ = $2; }
    | LBRACE RBRACE { $$ = NULL; }
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
    atrib_expr { $$ = $1; }
    ;

atrib_expr:
    or_expr { $$ = $1; }
    | var ASSIGN atrib_expr { $$ = criarNoAssign('=', $1, $3); }
    | var PLUS_ASSIGN atrib_expr { $$ = criarNoBinOp('+', $1, $3); }
    | var MINUS_ASSIGN atrib_expr { $$ = criarNoBinOp('-', $1, $3); }
    | var MULT_ASSIGN atrib_expr { $$ = criarNoBinOp('*', $1, $3); }
    | var DIV_ASSIGN atrib_expr { $$ = criarNoBinOp('/', $1, $3); }
    ;

or_expr:
    and_expr { $$ = $1; }
    | or_expr OR and_expr { $$ = criarNoBinOp('|', $1, $3);}
    ;

and_expr:
    bitor_expr { $$ = $1; }
    | and_expr AND bitor_expr { $$ = criarNoBinOp('&', $1, $3); }
    ;

bitor_expr:
    bitxor_expr { $$ = $1; }
    | bitor_expr BITOR bitxor_expr { $$ = criarNoBinOp('|', $1, $3);}
    ;

bitxor_expr:
    bitand_expr { $$ = $1; }
    | bitxor_expr BITXOR bitand_expr { $$ = criarNoBinOp('^', $1, $3); }
    ;

bitand_expr:
    equal_expr { $$ = $1; }
    | bitand_expr BITAND equal_expr { $$ = criarNoBinOp('&', $1, $3); }
    ;

equal_expr:
    relacao_expr { $$ = $1; }
    | equal_expr EQ relacao_expr { $$ = criarNoBinOp('=', $1, $3);}
    | equal_expr NE relacao_expr { $$ = criarNoBinOp('!', $1, $3);}
    ;

relacao_expr:
    shift_expr { $$ = $1; }
    | relacao_expr GT shift_expr { $$ = criarNoBinOp('>', $1, $3); }
    | relacao_expr LT shift_expr { $$ = criarNoBinOp('<', $1, $3); }
    | relacao_expr GE shift_expr { $$ = criarNoBinOp('g', $1, $3); }
    | relacao_expr LE shift_expr { $$ = criarNoBinOp('l', $1, $3); }
    ;


shift_expr:
    add_expr { $$ = $1; }
    | shift_expr SHIFTLEFT add_expr { $$ = criarNoBinOp('[', $1, $3); }
    | shift_expr SHIFTRIGHT add_expr { $$ = criarNoBinOp(']', $1, $3); }
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
    | INCREMENT var { $$ = criarNoUnaryOp('+', $2); }
    | DECREMENT var { $$ = criarNoUnaryOp('-', $2); }
    | MINUS unary_expr %prec UMINUS { $$ = criarNoUnaryOp('-', $2); }
    | PLUS unary_expr %prec UPLUS { $$ = criarNoUnaryOp('+', $2); }
    | NOT unary_expr { $$ = criarNoUnaryOp('!', $2); }
    | BITNOT unary_expr { $$ = criarNoUnaryOp('~', $2); }
;

fator:
    NUM { $$ = criarNoInt($1); }
    | FLOAT { $$ = criarNoFloat($1); }
    | CHAR_LITERAL { $$ = criarNoChar($1); }
    | HEX { $$ = criarNoHex($1); }
    | STRING { $$ = criarNoString($1); }
    | var { $$ = $1; }
    | chamada { $$ = $1; }
    | LPAREN expr RPAREN { $$ = $2; }
    | var INCREMENT { $$ = criarNoUnaryOp('+', $1); }
    | var DECREMENT { $$ = criarNoUnaryOp('-', $1); }
;

var:
    ID { $$ = criarNoVar($1); }
    | var DOT ID { $$ = criarNoVar($3); }
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

typedef_declaracao:
    TYPEDEF tipo ID SEMICOLON { $$ = criarNoVar($3); }
;

lista_identificadores:
    ID { $$ = criarNoVar($1); }
    | lista_identificadores COMMA ID { $$ = concatenarStmt($1, criarNoVar($3)); }
    ;

struct_declaracao:
    STRUCT ID LBRACE lista_declaracoes RBRACE SEMICOLON { $$ = criarNoUnion("struct", $2); }
    ;

union_declaracao:
    UNION ID LBRACE lista_declaracoes RBRACE SEMICOLON { $$ = criarNoUnion("union", $2); }
    ;

enum_declaracao:
    ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON { $$ = criarNoEnum($2); }
    ;

%%
