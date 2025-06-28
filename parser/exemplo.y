%{
#include <stdio.h>
#include <stdlib.h>
#include "../ast/ast.h"
#include "../semantic/semantic.h"
#include "../simbolos.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
extern int yylineno;
ASTNode* root;

// Função para reportar erros de construções não suportadas
void report_unsupported_feature(const char* feature, int line) {
    fprintf(stderr, "Erro na linha %d: %s não é suportado nesta versão do compilador\n", line, feature);
}
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
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token QUESTION
%token AND OR NOT
%token BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT

// Tokens para construções não suportadas completamente
%token LBRACKET RBRACKET INCLUDE POINTER AMPERSAND

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left QUESTION
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
%type <node> stmt expr atrib_expr ternary_expr or_expr and_expr bitor_expr bitxor_expr
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

%%

programa:
    { 
        /* Inicializar tabela de símbolos no início do programa */
        iniciarTabelaSimbolos(); 
    }
    lista_declaracoes { 
        root = $2; 
        /* Finalizar tabela de símbolos no final */
        finalizarTabelaSimbolos();
    }
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
    | error SEMICOLON { 
        $$ = NULL; 
        yyerror("Declaração inválida"); 
    }
    ;

declaracao_tipo:
    struct_declaracao { 
        /* Verificar se struct já foi declarada no escopo atual */
        if ($1 && $1->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($1->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' já declarada neste escopo", $1->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo($1->valor_str, TIPO_STRUCT);
            }
        }
        $$ = $1; 
    }
    | union_declaracao { 
        /* Verificar se union já foi declarada no escopo atual */
        if ($1 && $1->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($1->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' já declarada neste escopo", $1->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo($1->valor_str, TIPO_UNION);
            }
        }
        $$ = $1; 
    }
    | enum_declaracao { 
        /* Verificar se enum já foi declarado no escopo atual */
        if ($1 && $1->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($1->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' já declarado neste escopo", $1->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo($1->valor_str, TIPO_ENUM);
            }
        }
        $$ = $1; 
    }
    | typedef_declaracao { 
        /* Verificar se typedef já foi declarado no escopo atual */
        if ($1 && $1->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($1->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Typedef '%s' já declarado neste escopo", $1->valor_str);
                yyerror(erro);
            } else {
                /* Para typedef, assumir o tipo base (seria determinado pela análise completa) */
                inserirSimbolo($1->valor_str, TIPO_INT); /* Placeholder - tipo seria determinado pelo typedef */
            }
        }
        $$ = $1; 
    }
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE {
        /* Iniciar novo escopo para o switch */
        iniciarEscopo();
    }
    case_list RBRACE { 
        /* Finalizar escopo do switch */
        finalizarEscopo();
        $$ = criarNoSwitch($3, $7); 
    }
    | SWITCH LPAREN expr RPAREN error { 
        $$ = NULL; 
        yyerror("Estrutura switch incompleta ou inválida"); 
    }
    ;

for_stmt:
    FOR LPAREN {
        /* Iniciar novo escopo para o for */
        iniciarEscopo();
    }
    expr SEMICOLON expr SEMICOLON expr RPAREN stmt {
        /* Finalizar escopo do for */
        finalizarEscopo();
        $$ = criarNoFor($4, $6, $8, $10);
    }
    | FOR LPAREN error RPAREN stmt {
        $$ = NULL;
        yyerror("Formato inválido para estrutura for");
    }
;

do_stmt:
    DO stmt WHILE LPAREN expr RPAREN SEMICOLON { 
        $$ = criarNoDoWhile($5, $2); 
    }
    | DO stmt WHILE LPAREN error RPAREN SEMICOLON {
        $$ = NULL;
        yyerror("Expressão inválida na condição do do-while");
    }
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
    | CASE error COLON { 
        $$ = NULL; 
        yyerror("Expressão inválida em case"); 
    }
    ;

comandos_break:
    comandos_opt BREAK SEMICOLON { $$ = concatenarStmt($1, criarNoBreak()); }
    | comandos_opt { $$ = $1; }
    ;

comandos_opt:
    /* vazio */ { $$ = NULL; }
    | lista_declaracoes { $$ = $1; }
    ;

declaracao_variavel:
    tipo lista_variaveis { 
        /* Processar cada variável na lista com o tipo especificado */
        ASTNode *current = $2;
        TipoSimbolo tipo_var = TIPO_ERRO;
        
        /* Converter string do tipo para TipoSimbolo */
        if ($1 && $1->valor_str) {
            if (strcmp($1->valor_str, "int") == 0) tipo_var = TIPO_INT;
            else if (strcmp($1->valor_str, "float") == 0) tipo_var = TIPO_FLOAT;
            else if (strcmp($1->valor_str, "char") == 0) tipo_var = TIPO_CHAR;
            else if (strcmp($1->valor_str, "double") == 0) tipo_var = TIPO_DOUBLE;
            else if (strcmp($1->valor_str, "void") == 0) tipo_var = TIPO_VOID;
        }
        
        /* Percorrer lista de variáveis e inserir na tabela de símbolos */
        while (current != NULL) {
            if (current->valor_str) {
                Simbolo *existente = buscarSimboloNoEscopoAtual(current->valor_str);
                if (existente != NULL) {
                    char erro[256];
                    snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' já declarada neste escopo", current->valor_str);
                    yyerror(erro);
                } else {
                    inserirSimbolo(current->valor_str, tipo_var);
                }
            }
            current = current->prox;
        }
        
        $$ = criarNoVarDecl($2->valor_str, criarNoType($1->valor_str)); 
    }
    | tipo error { 
        $$ = NULL; 
        yyerror("Declaração de variável inválida"); 
    }
;

tipo:
    INT { $$ = criarNoType("int"); }
    | FLOAT { $$ = criarNoType("float"); }
    | CHAR { $$ = criarNoType("char"); }
    | VOID { $$ = criarNoType("void"); }
    | DOUBLE { $$ = criarNoType("double"); }
    | STRUCT ID { 
        /* Verificar se struct foi declarada */
        Simbolo *struct_sym = buscarSimbolo($2);
        if (struct_sym == NULL || struct_sym->tipo != TIPO_STRUCT) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' não declarada", $2);
            yyerror(erro);
        }
        $$ = criarNoUnion("struct", $2); 
    }
    | UNION ID { 
        /* Verificar se union foi declarada */
        Simbolo *union_sym = buscarSimbolo($2);
        if (union_sym == NULL || union_sym->tipo != TIPO_UNION) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' não declarada", $2);
            yyerror(erro);
        }
        $$ = criarNoUnion("union", $2); 
    }
    | ENUM ID { 
        /* Verificar se enum foi declarado */
        Simbolo *enum_sym = buscarSimbolo($2);
        if (enum_sym == NULL || enum_sym->tipo != TIPO_ENUM) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' não declarado", $2);
            yyerror(erro);
        }
        $$ = criarNoEnum($2); 
    }
    ;

lista_variaveis:
    variavel { $$ = $1; }
    | lista_variaveis COMMA variavel { $$ = concatenarStmt($1, $3); }
    ;

variavel:
    ID { 
        $$ = criarNoVar($1); 
    }
    | ID ASSIGN expr { 
        ASTNode *var = criarNoVar($1);
        ASTNode *assign = criarNoAssign('=', var, $3);
        // Manter o nome da variável no nó principal para facilitar o processamento
        assign->valor_str = strdup($1);
        $$ = assign;
    }
    | ID ASSIGN inicializador { 
        ASTNode *var = criarNoVar($1);
        ASTNode *assign = criarNoAssign('=', var, $3);
        // Manter o nome da variável no nó principal para facilitar o processamento
        assign->valor_str = strdup($1);
        $$ = assign;
    }

fun_declaracao:
    tipo ID LPAREN parametros RPAREN composto_stmt { 
        /* Verificar se função já foi declarada no escopo atual */
        if ($2) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($2);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Função '%s' já declarada neste escopo", $2);
                yyerror(erro);
            } else {
                inserirSimbolo($2, TIPO_FUNCAO);
            }
        }
        $$ = criarNoFuncDecl($2, $1, $4, $6); 
    }
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
    tipo ID { 
        /* Verificar se parâmetro já foi declarado no escopo atual */
        if ($2) {
            Simbolo *existente = buscarSimboloNoEscopoAtual($2);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Parâmetro '%s' já declarado neste escopo", $2);
                yyerror(erro);
            } else {
                inserirSimbolo($2, TIPO_VARIAVEL);
            }
        }
        $$ = criarNoParam($2, $1); 
    }
    | tipo error { 
        $$ = NULL; 
        yyerror("Parâmetro inválido"); 
    }
    ;

inicializador:
    LBRACE lista_inicializadores RBRACE { $$ = $2; }
    | LBRACE error RBRACE { 
        $$ = NULL; 
        yyerror("Lista de inicialização inválida"); 
    }
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
    | error SEMICOLON { 
        $$ = NULL; 
        yyerror("Comando inválido"); 
    }
    ;

expr_stmt:
    expr SEMICOLON { $$ = $1; }
    | SEMICOLON { $$ = NULL; }
    ;

composto_stmt:
    LBRACE comandos_opt RBRACE { 
        $$ = $2; 
    }
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE { $$ = criarNoIf($3, $5, NULL); }
    | IF LPAREN expr RPAREN stmt ELSE stmt { $$ = criarNoIf($3, $5, $7); }
    | IF LPAREN error RPAREN stmt { 
        $$ = NULL; 
        yyerror("Expressão condicional inválida no if"); 
    }
;

while_stmt:
    WHILE LPAREN expr RPAREN {
        /* Iniciar novo escopo para o while */
        iniciarEscopo();
    }
    stmt { 
        /* Finalizar escopo do while */
        finalizarEscopo();
        $$ = criarNoWhile($3, $6); 
    }
    | WHILE LPAREN error RPAREN stmt { 
        $$ = NULL; 
        yyerror("Expressão condicional inválida no while"); 
    }
;

return_stmt:
    RETURN expr SEMICOLON { $$ = criarNoReturn($2); }
    | RETURN SEMICOLON { $$ = criarNoReturn(NULL); }
    | RETURN error SEMICOLON { 
        $$ = NULL; 
        yyerror("Expressão de retorno inválida"); 
    }
;

expr:
    atrib_expr { $$ = $1; }
    ;

atrib_expr:
    ternary_expr { $$ = $1; }
    | var ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', $1, $3); 
    }
    | var PLUS_ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', 
            $1, 
            criarNoBinOp("+", $1, $3)
        ); 
    }
    | var MINUS_ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', 
            $1, 
            criarNoBinOp("-", $1, $3)
        ); 
    }
    | var MULT_ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', 
            $1, 
            criarNoBinOp("*", $1, $3)
        ); 
    }
    | var DIV_ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', 
            $1, 
            criarNoBinOp("/", $1, $3)
        ); 
    }
    | var MOD_ASSIGN atrib_expr { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoAssign('=', 
            $1, 
            criarNoBinOp("%", $1, $3)
        ); 
    }
    | var error { 
        $$ = NULL; 
        yyerror("Operação de atribuição inválida"); 
    }
    ;

ternary_expr:
    or_expr { $$ = $1; } 
    | or_expr QUESTION expr COLON ternary_expr { $$ = criarNoTernario($1, $3, $5);}
    ;

or_expr:
    and_expr { $$ = $1; }
    | or_expr OR and_expr { $$ = criarNoBinOp("||", $1, $3);}
    ;

and_expr:
    bitor_expr { $$ = $1; }
    | and_expr AND bitor_expr { $$ = criarNoBinOp("&&", $1, $3); }
    ;

bitor_expr:
    bitxor_expr { $$ = $1; }
    | bitor_expr BITOR bitxor_expr { $$ = criarNoBinOp("|", $1, $3);}
    ;

bitxor_expr:
    bitand_expr { $$ = $1; }
    | bitxor_expr BITXOR bitand_expr { $$ = criarNoBinOp("^", $1, $3); }
    ;

bitand_expr:
    equal_expr { $$ = $1; }
    | bitand_expr BITAND equal_expr { $$ = criarNoBinOp("&", $1, $3); }
    ;

equal_expr:
    relacao_expr { $$ = $1; }
    | equal_expr EQ relacao_expr { $$ = criarNoBinOp("==", $1, $3);}
    | equal_expr NE relacao_expr { $$ = criarNoBinOp("!=", $1, $3);}
    ;

relacao_expr:
    shift_expr { $$ = $1; }
    | relacao_expr GT shift_expr { $$ = criarNoBinOp(">", $1, $3); }
    | relacao_expr LT shift_expr { $$ = criarNoBinOp("<", $1, $3); }
    | relacao_expr GE shift_expr { $$ = criarNoBinOp(">=", $1, $3); }
    | relacao_expr LE shift_expr { $$ = criarNoBinOp("<=", $1, $3); }
    ;

shift_expr:
    add_expr { $$ = $1; }
    | shift_expr SHIFTLEFT add_expr { $$ = criarNoBinOp("<<", $1, $3); }
    | shift_expr SHIFTRIGHT add_expr { $$ = criarNoBinOp(">>", $1, $3); }
    ;

add_expr:
       mult_expr { $$ = $1; }
       | add_expr PLUS mult_expr { $$ = criarNoBinOp("+", $1, $3); }
       | add_expr MINUS mult_expr { $$ = criarNoBinOp("-", $1, $3); }
       ;

mult_expr:
    unary_expr { $$ = $1; }
    | mult_expr MULT unary_expr { $$ = criarNoBinOp("*", $1, $3); }
    | mult_expr DIV unary_expr { $$ = criarNoBinOp("/", $1, $3); }
    | mult_expr MOD unary_expr { $$ = criarNoBinOp("%", $1, $3); }
    ;

unary_expr:
    fator { $$ = $1; }
    | INCREMENT var { 
        /* Verificar se variável foi declarada */
        if ($2 && $2->valor_str) {
            Simbolo *sym = buscarSimbolo($2->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $2->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoUnaryOp("++", $2); 
    }
    | DECREMENT var { 
        /* Verificar se variável foi declarada */
        if ($2 && $2->valor_str) {
            Simbolo *sym = buscarSimbolo($2->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $2->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoUnaryOp("--", $2); 
    }
    | MINUS unary_expr %prec UMINUS { $$ = criarNoUnaryOp("-", $2); }
    | PLUS unary_expr %prec UPLUS { $$ = criarNoUnaryOp("+", $2); }
    | NOT unary_expr { $$ = criarNoUnaryOp("!", $2); }
    | BITNOT unary_expr { $$ = criarNoUnaryOp("~", $2); }
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
    | var INCREMENT { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoUnaryOp("++", $1); 
    }
    | var DECREMENT { 
        /* Verificar se variável foi declarada */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoUnaryOp("--", $1); 
    }
;

var:
    ID { 
        /* Verificar se variável foi declarada */
        Simbolo *sym = buscarSimbolo($1);
        if (sym == NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", $1);
            yyerror(erro);
        }
        $$ = criarNoVar($1); 
    }
    | var DOT ID { 
        /* Para acesso a membros, verificar se o tipo é struct/union */
        if ($1 && $1->valor_str) {
            Simbolo *sym = buscarSimbolo($1->valor_str);
            if (sym != NULL && sym->tipo != TIPO_STRUCT && sym->tipo != TIPO_UNION) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: '%s' não é uma struct ou union", $1->valor_str);
                yyerror(erro);
            }
        }
        $$ = criarNoVar($3); 
    }
    | ID '[' expr ']' {
        $$ = NULL;
        report_unsupported_feature("Arrays", yylineno);
    }
;

chamada:
    ID LPAREN argumentos RPAREN { 
        /* Verificar se função foi declarada */
        Simbolo *sym = buscarSimbolo($1);
        if (sym == NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Função '%s' não declarada", $1);
            yyerror(erro);
        } else if (sym->tipo != TIPO_FUNCAO) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: '%s' não é uma função", $1);
            yyerror(erro);
        }
        $$ = criarNoCall($1, $3); 
    }
    | ID LPAREN error RPAREN { 
        $$ = NULL; 
        yyerror("Lista de argumentos inválida"); 
    }
;

argumentos:
    lista_args { $$ = $1; }
    | /* vazio */ { $$ = NULL; }
;

lista_args:
    lista_args COMMA expr { $$ = concatenarArg($1, $3); }
    | expr { $$ = $1; }
    | lista_args COMMA error { 
        $$ = NULL; 
        yyerror("Argumento inválido na lista"); 
    }
;

typedef_declaracao:
    TYPEDEF tipo ID SEMICOLON { 
        /* Verificar se o identificador já existe no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual($3);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Identificador '%s' já declarado neste escopo", $3);
            yyerror(erro);
        } else {
            /* Determinar o tipo baseado no nó AST */
            TipoSimbolo tipoSimbolo = TIPO_ERRO;
            if ($2 && $2->valor_str) {
                if (strcmp($2->valor_str, "int") == 0) tipoSimbolo = TIPO_INT;
                else if (strcmp($2->valor_str, "float") == 0) tipoSimbolo = TIPO_FLOAT;
                else if (strcmp($2->valor_str, "char") == 0) tipoSimbolo = TIPO_CHAR;
                else if (strcmp($2->valor_str, "double") == 0) tipoSimbolo = TIPO_DOUBLE;
                else if (strcmp($2->valor_str, "void") == 0) tipoSimbolo = TIPO_VOID;
            }
            inserirSimbolo($3, tipoSimbolo);
        }
        $$ = criarNoVar($3); 
    }
    | TYPEDEF error SEMICOLON { 
        $$ = NULL; 
        yyerror("Declaração typedef inválida"); 
    }
;

lista_identificadores:
    ID { 
        /* Para enums, inserir o identificador como TIPO_ENUM */
        Simbolo *existente = buscarSimboloNoEscopoAtual($1);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enumerador '%s' já declarado neste escopo", $1);
            yyerror(erro);
        } else {
            inserirSimbolo($1, TIPO_ENUM);
        }
        $$ = criarNoVar($1); 
    }
    | lista_identificadores COMMA ID { 
        /* Para enums, inserir o identificador como TIPO_ENUM */
        Simbolo *existente = buscarSimboloNoEscopoAtual($3);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enumerador '%s' já declarado neste escopo", $3);
            yyerror(erro);
        } else {
            inserirSimbolo($3, TIPO_ENUM);
        }
        $$ = concatenarStmt($1, criarNoVar($3)); 
    }
    ;

struct_declaracao:
    STRUCT ID LBRACE lista_declaracoes RBRACE SEMICOLON { 
        /* Verificar se struct já foi declarada no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual($2);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' já declarada neste escopo", $2);
            yyerror(erro);
        } else {
            inserirSimbolo($2, TIPO_STRUCT);
        }
        $$ = criarNoUnion("struct", $2); 
    }
    | STRUCT ID LBRACE error RBRACE SEMICOLON { 
        $$ = NULL; 
        yyerror("Corpo de struct inválido"); 
    }
    ;

union_declaracao:
    UNION ID LBRACE lista_declaracoes RBRACE SEMICOLON { 
        /* Verificar se union já foi declarada no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual($2);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' já declarada neste escopo", $2);
            yyerror(erro);
        } else {
            inserirSimbolo($2, TIPO_UNION);
        }
        $$ = criarNoUnion("union", $2); 
    }
    | UNION ID LBRACE error RBRACE SEMICOLON { 
        $$ = NULL; 
        yyerror("Corpo de union inválido"); 
    }
    ;

enum_declaracao:
    ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON { 
        /* Verificar se enum já foi declarado no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual($2);
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' já declarado neste escopo", $2);
            yyerror(erro);
        } else {
            inserirSimbolo($2, TIPO_ENUM);
        }
        $$ = criarNoEnum($2); 
    }
    | ENUM ID LBRACE error RBRACE SEMICOLON { 
        $$ = NULL; 
        yyerror("Lista de enumeradores inválida"); 
    }
    ;

%%
