#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode *criarNo(ASTNodeType tipo, const char *valor_str) {
    ASTNode *no = (ASTNode *)malloc(sizeof(ASTNode));
    no->tipo = tipo;
    no->valor_str = valor_str ? strdup(valor_str) : NULL;
    no->valor_int = 0;
    no->valor_float = 0;
    no->valor_char = 0;
    no->filho1 = no->filho2 = no->filho3 = no->filho4 = NULL;
    no->prox = NULL;
    return no;
}

ASTNode *criarNoInt(int valor) {
    ASTNode *no = criarNo(AST_LITERAL_INT, NULL);
    no->valor_int = valor;
    return no;
}

ASTNode *criarNoFloat(float valor) {
    ASTNode *no = criarNo(AST_LITERAL_FLOAT, NULL);
    no->valor_float = valor;
    return no;
}

ASTNode *criarNoString(const char *str) {
    return criarNo(AST_LITERAL_STRING, str);
}

ASTNode *criarNoChar(char c) {
    ASTNode *no = criarNo(AST_LITERAL_CHAR, NULL);
    no->valor_char = c;
    return no;
}

ASTNode *criarNoHex(const char *str) {
    return criarNo(AST_LITERAL_HEX, str);
}

ASTNode *criarNoVar(const char *id) {
    return criarNo(AST_VAR, id);
}

ASTNode *criarNoType(const char *tipo) {
    return criarNo(AST_TYPE, tipo);
}

ASTNode *criarNoBinOp(char op, ASTNode *esq, ASTNode *dir) {
    ASTNode *no = criarNo(AST_BINARY_OP, NULL);
    no->valor_char = op;
    no->filho1 = esq;
    no->filho2 = dir;
    return no;
}

ASTNode *criarNoUnaryOp(char op, ASTNode *expr) {
    ASTNode *no = criarNo(AST_UNARY_OP, NULL);
    no->valor_char = op;
    no->filho1 = expr;
    return no;
}

ASTNode *criarNoAssign(char op, ASTNode *var, ASTNode *expr) {
    ASTNodeType tipo;
    switch (op) {
        case '=': tipo = AST_ASSIGN; break;
        case '+': tipo = AST_PLUS_ASSIGN; break;
        case '-': tipo = AST_MINUS_ASSIGN; break;
        case '*': tipo = AST_MULT_ASSIGN; break;
        case '/': tipo = AST_DIV_ASSIGN; break;
        default: tipo = AST_ASSIGN;
    }
    ASTNode *no = criarNo(tipo, NULL);
    no->filho1 = var;
    no->filho2 = expr;
    return no;
}

ASTNode *criarNoIf(ASTNode *cond, ASTNode *thenBranch, ASTNode *elseBranch) {
    ASTNode *no = criarNo(elseBranch ? AST_IF_ELSE : AST_IF, NULL);
    no->filho1 = cond;
    no->filho2 = thenBranch;
    no->filho3 = elseBranch;
    return no;
}

ASTNode *criarNoWhile(ASTNode *cond, ASTNode *body) {
    ASTNode *no = criarNo(AST_WHILE, NULL);
    no->filho1 = cond;
    no->filho2 = body;
    return no;
}

ASTNode *criarNoDoWhile(ASTNode *cond, ASTNode *body) {
    ASTNode *no = criarNo(AST_DO_WHILE, NULL);
    no->filho1 = body;
    no->filho2 = cond;
    return no;
}

ASTNode *criarNoFor(ASTNode *init, ASTNode *cond, ASTNode *increment, ASTNode *body) {
    ASTNode *no = criarNo(AST_FOR, NULL);
    no->filho1 = init;
    no->filho2 = cond;
    no->filho3 = increment;
    no->filho4 = body;
    return no;
}

ASTNode *criarNoReturn(ASTNode *expr) {
    ASTNode *no = criarNo(AST_RETURN, NULL);
    no->filho1 = expr;
    return no;
}

ASTNode *criarNoBreak(void) {
    return criarNo(AST_BREAK, NULL);
}

ASTNode *criarNoContinue(void) {
    return criarNo(AST_CONTINUE, NULL);
}

ASTNode *criarNoVarDecl(const char *id, ASTNode *tipo) {
    ASTNode *no = criarNo(AST_VAR_DECL, id);
    no->filho1 = tipo;
    return no;
}

ASTNode *criarNoFuncDecl(const char *id, ASTNode *tipo, ASTNode *params, ASTNode *body) {
    ASTNode *no = criarNo(AST_FUNC_DECL, id);
    no->filho1 = tipo;
    no->filho2 = params;
    no->filho3 = body;
    return no;
}

ASTNode *criarNoParam(const char *id, ASTNode *tipo) {
    ASTNode *no = criarNo(AST_PARAM, id);
    no->filho1 = tipo;
    return no;
}

ASTNode *criarNoBlock(ASTNode *stmtList) {
    ASTNode *no = criarNo(AST_BLOCK, NULL);
    no->filho1 = stmtList;
    return no;
}

ASTNode *criarNoCall(const char *id, ASTNode *args) {
    ASTNode *no = criarNo(AST_CALL, id);
    no->filho1 = args;
    return no;
}

ASTNode *concatenarStmt(ASTNode *lista, ASTNode *no) {
    if (!lista) return no;
    ASTNode *tmp = lista;
    while (tmp->prox) tmp = tmp->prox;
    tmp->prox = no;
    return lista;
}

ASTNode *concatenarParam(ASTNode *lista, ASTNode *no) {
    return concatenarStmt(lista, no);
}

ASTNode *concatenarArg(ASTNode *lista, ASTNode *no) {
    return concatenarStmt(lista, no);
}

void imprimirAST(ASTNode *no) {
    if (!no) return;
    printf("(%d", no->tipo);
    if (no->valor_str) printf(" \"%s\"", no->valor_str);
    if (no->valor_int) printf(" %d", no->valor_int);
    if (no->valor_float) printf(" %.2f", no->valor_float);
    if (no->valor_char) printf(" '%c'", no->valor_char);
    if (no->filho1) { printf(" "); imprimirAST(no->filho1); }
    if (no->filho2) { printf(" "); imprimirAST(no->filho2); }
    if (no->filho3) { printf(" "); imprimirAST(no->filho3); }
    if (no->filho4) { printf(" "); imprimirAST(no->filho4); }
    printf(")");
    if (no->prox) {
        printf("\n");
        imprimirAST(no->prox);
    }
}

void liberarAST(ASTNode *no) {
    if (!no) return;
    liberarAST(no->filho1);
    liberarAST(no->filho2);
    liberarAST(no->filho3);
    liberarAST(no->filho4);
    liberarAST(no->prox);
    if (no->valor_str) free(no->valor_str);
    free(no);
}
