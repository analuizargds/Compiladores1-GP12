#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


ASTNode *noSwitch(ASTNode *expr, ASTNode *cases) {
    ASTNode *no = criarNo(AST_SWITCH, NULL);
    no->filho1 = expr;
    no->filho2 = cases;
    return no;
}

ASTNode *noCase(ASTNode *expr, ASTNode *stmts) {
    ASTNode *no = criarNo(expr ? AST_CASE : AST_DEFAULT, NULL);
    no->filho1 = expr;
    no->filho2 = stmts;
    return no;
}

ASTNode *noInit(ASTNode *expr, ASTNode *lista) {
    ASTNode *no = criarNo(AST_INIT, NULL);
    no->filho1 = expr;
    no->prox = lista;
    return no;
}

ASTNode *noUnion(const char *tipo, const char *id) {
    ASTNode *no = criarNo(AST_UNION, id);
    no->valor_str = strdup(tipo);  // "struct" ou "union"
    return no;
}

ASTNode *noEnum(const char *id) {
    return criarNo(AST_ENUM, id);
}
