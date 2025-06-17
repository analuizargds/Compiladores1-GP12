#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Variável global para contar os nós e gerar IDs únicos no DOT
static int node_counter = 0;

// Função auxiliar para gerar o código DOT de um nó da AST
void ast_to_dot_node(AST *node, FILE *outfile) {
    if (node == NULL) {
        return;
    }

    int current_node_id = node_counter++;

    fprintf(outfile, "  node%d [label=\"%s\"];\n", current_node_id, "Nó AST"); // Placeholder label

    // Recursivamente gerar DOT para os filhos
    if (node->filho1 != NULL) {
        fprintf(outfile, "  node%d -> node%d;\n", current_node_id, node_counter);
        ast_to_dot_node(node->filho1, outfile);
    }
    if (node->filho2 != NULL) {
        fprintf(outfile, "  node%d -> node%d;\n", current_node_id, node_counter);
        ast_to_dot_node(node->filho2, outfile);
    }
    if (node->filho3 != NULL) {
        fprintf(outfile, "  node%d -> node%d;\n", current_node_id, node_counter);
        ast_to_dot_node(node->filho3, outfile);
    }
    if (node->filho4 != NULL) {
        fprintf(outfile, "  node%d -> node%d;\n", current_node_id, node_counter);
        ast_to_dot_node(node->filho4, outfile);
    }
    if (node->prox != NULL) {
        fprintf(outfile, "  node%d -> node%d [style=dotted];\n", current_node_id, node_counter);
        ast_to_dot_node(node->prox, outfile);
    }
}

// Funções para criar nós da AST
ASTNode *criarNo(ASTNodeType tipo, const char *valor_str) {
    ASTNode *novoNo = (ASTNode *)malloc(sizeof(ASTNode));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para ASTNode");
        exit(EXIT_FAILURE);
    }
    novoNo->tipo = tipo;
    novoNo->filho1 = NULL;
    novoNo->filho2 = NULL;
    novoNo->filho3 = NULL;
    novoNo->filho4 = NULL;
    novoNo->prox = NULL;
    novoNo->valor_int = 0;
    novoNo->valor_float = 0.0f;
    novoNo->valor_char = '\0';
    novoNo->valor_str = (valor_str != NULL) ? strdup(valor_str) : NULL;
    novoNo->valor_str2 = NULL;
    novoNo->linha = 0; // Será preenchido pelo parser
    return novoNo;
}

ASTNode *criarNoInt(int valor) {
    ASTNode *novoNo = criarNo(AST_LITERAL_INT, NULL);
    novoNo->valor_int = valor;
    return novoNo;
}

ASTNode *criarNoFloat(float valor) {
    ASTNode *novoNo = criarNo(AST_LITERAL_FLOAT, NULL);
    novoNo->valor_float = valor;
    return novoNo;
}

ASTNode *criarNoString(const char *str) {
    return criarNo(AST_LITERAL_STRING, str);
}

ASTNode *criarNoChar(char c) {
    ASTNode *novoNo = criarNo(AST_LITERAL_CHAR, NULL);
    novoNo->valor_char = c;
    return novoNo;
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

ASTNode *criarNoBinOp(const char *op, ASTNode *esq, ASTNode *dir) {
    ASTNode *novoNo = criarNo(AST_BINARY_OP, op);
    novoNo->filho1 = esq;
    novoNo->filho2 = dir;
    return novoNo;
}

ASTNode *criarNoUnaryOp(char *op, ASTNode *expr) {
    ASTNode *novoNo = criarNo(AST_UNARY_OP, op);
    novoNo->filho1 = expr;
    return novoNo;
}

ASTNode *criarNoAssign(char op, ASTNode *var, ASTNode *expr) {
    ASTNode *novoNo = criarNo(AST_ASSIGN, NULL);
    novoNo->valor_char = op;
    novoNo->filho1 = var;
    novoNo->filho2 = expr;
    return novoNo;
}

ASTNode *criarNoIf(ASTNode *cond, ASTNode *thenBranch, ASTNode *elseBranch) {
    ASTNode *novoNo = criarNo(AST_IF, NULL);
    novoNo->filho1 = cond;
    novoNo->filho2 = thenBranch;
    novoNo->filho3 = elseBranch;
    return novoNo;
}

ASTNode *criarNoWhile(ASTNode *cond, ASTNode *body) {
    ASTNode *novoNo = criarNo(AST_WHILE, NULL);
    novoNo->filho1 = cond;
    novoNo->filho2 = body;
    return novoNo;
}

ASTNode *criarNoDoWhile(ASTNode *cond, ASTNode *body) {
    ASTNode *novoNo = criarNo(AST_DO_WHILE, NULL);
    novoNo->filho1 = cond;
    novoNo->filho2 = body;
    return novoNo;
}

ASTNode *criarNoFor(ASTNode *init, ASTNode *cond, ASTNode *increment, ASTNode *body) {
    ASTNode *novoNo = criarNo(AST_FOR, NULL);
    novoNo->filho1 = init;
    novoNo->filho2 = cond;
    novoNo->filho3 = increment;
    novoNo->filho4 = body;
    return novoNo;
}

ASTNode *criarNoReturn(ASTNode *expr) {
    ASTNode *novoNo = criarNo(AST_RETURN, NULL);
    novoNo->filho1 = expr;
    return novoNo;
}

ASTNode *criarNoBreak(void) {
    return criarNo(AST_BREAK, NULL);
}

ASTNode *criarNoContinue(void) {
    return criarNo(AST_CONTINUE, NULL);
}

ASTNode *criarNoVarDecl(const char *id, ASTNode *tipo) {
    ASTNode *novoNo = criarNo(AST_VAR_DECL, id);
    novoNo->filho1 = tipo;
    return novoNo;
}

ASTNode *criarNoFuncDecl(const char *id, ASTNode *tipo, ASTNode *params, ASTNode *body) {
    ASTNode *novoNo = criarNo(AST_FUNC_DECL, id);
    novoNo->filho1 = tipo;
    novoNo->filho2 = params;
    novoNo->filho3 = body;
    return novoNo;
}

ASTNode *criarNoParam(const char *id, ASTNode *tipo) {
    ASTNode *novoNo = criarNo(AST_PARAM, id);
    novoNo->filho1 = tipo;
    return novoNo;
}

ASTNode *criarNoBlock(ASTNode *stmtList) {
    ASTNode *novoNo = criarNo(AST_BLOCK, NULL);
    novoNo->filho1 = stmtList;
    return novoNo;
}

ASTNode *criarNoCall(const char *id, ASTNode *args) {
    ASTNode *novoNo = criarNo(AST_CALL, id);
    novoNo->filho1 = args;
    return novoNo;
}

ASTNode *criarNoSwitch(ASTNode *expr, ASTNode *cases) {
    ASTNode *novoNo = criarNo(AST_SWITCH, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = cases;
    return novoNo;
}

ASTNode *criarNoCase(ASTNode *expr, ASTNode *stmts) {
    ASTNode *novoNo = criarNo(AST_CASE, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = stmts;
    return novoNo;
}

ASTNode *criarNoInit(ASTNode *expr, ASTNode *lista) {
    ASTNode *novoNo = criarNo(AST_INIT, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = lista;
    return novoNo;
}

ASTNode *criarNoUnion(const char *tipo, const char *id) {
    ASTNode *novoNo = criarNo(AST_UNION, id);
    novoNo->valor_str2 = strdup(tipo);
    return novoNo;
}

ASTNode *criarNoEnum(const char *id) {
    return criarNo(AST_ENUM, id);
}

// Funções para manipular a AST
ASTNode *concatenarStmt(ASTNode *lista, ASTNode *no) {
    if (lista == NULL) {
        return no;
    } else {
        ASTNode *temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

ASTNode *concatenarParam(ASTNode *lista, ASTNode *no) {
    if (lista == NULL) {
        return no;
    } else {
        ASTNode *temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

ASTNode *concatenarArg(ASTNode *lista, ASTNode *no) {
    if (lista == NULL) {
        return no;
    } else {
        ASTNode *temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

void liberarAST(ASTNode *no) {
    if (no == NULL) {
        return;
    }
    liberarAST(no->filho1);
    liberarAST(no->filho2);
    liberarAST(no->filho3);
    liberarAST(no->filho4);
    liberarAST(no->prox);

    if (no->valor_str != NULL) {
        free(no->valor_str);
    }
    if (no->valor_str2 != NULL) {
        free(no->valor_str2);
    }
    free(no);
}

// Função auxiliar para imprimir nós da AST (para depuração)
void imprimirAST(ASTNode *no) {
    if (no == NULL) {
        return;
    }
    switch (no->tipo) {
        case AST_LITERAL_INT:
            printf("INT: %d\n", no->valor_int);
            break;
        case AST_LITERAL_FLOAT:
            printf("FLOAT: %f\n", no->valor_float);
            break;
        case AST_LITERAL_STRING:
            printf("STRING: %s\n", no->valor_str);
            break;
        case AST_LITERAL_CHAR:
            printf("CHAR: %c\n", no->valor_char);
            break;
        case AST_LITERAL_HEX:
            printf("HEX: %s\n", no->valor_str);
            break;
        case AST_VAR:
            printf("VAR: %s\n", no->valor_str);
            break;
        case AST_BINARY_OP:
            printf("BIN_OP: %s\n", no->valor_str);
            break;
        case AST_UNARY_OP:
            printf("UNARY_OP: %s\n", no->valor_str);
            break;
        case AST_ASSIGN:
            printf("ASSIGN: %c\n", no->valor_char);
            break;
        case AST_IF:
            printf("IF\n");
            break;
        case AST_IF_ELSE:
            printf("IF_ELSE\n");
            break;
        case AST_WHILE:
            printf("WHILE\n");
            break;
        case AST_FOR:
            printf("FOR\n");
            break;
        case AST_DO_WHILE:
            printf("DO_WHILE\n");
            break;
        case AST_SWITCH:
            printf("SWITCH\n");
            break;
        case AST_RETURN:
            printf("RETURN\n");
            break;
        case AST_BREAK:
            printf("BREAK\n");
            break;
        case AST_CONTINUE:
            printf("CONTINUE\n");
            break;
        case AST_VAR_DECL:
            printf("VAR_DECL: %s\n", no->valor_str);
            break;
        case AST_FUNC_DECL:
            printf("FUNC_DECL: %s\n", no->valor_str);
            break;
        case AST_PARAM:
            printf("PARAM: %s\n", no->valor_str);
            break;
        case AST_TYPE:
            printf("TYPE: %s\n", no->valor_str);
            break;
        case AST_BLOCK:
            printf("BLOCK\n");
            break;
        case AST_CALL:
            printf("CALL: %s\n", no->valor_str);
            break;
        case AST_ARG_LIST:
            printf("ARG_LIST\n");
            break;
        case AST_CASE:
            printf("CASE\n");
            break;
        case AST_DEFAULT:
            printf("DEFAULT\n");
            break;
        case AST_INIT:
            printf("INIT\n");
            break;
        case AST_STRUCT:
            printf("STRUCT: %s\n", no->valor_str);
            break;
        case AST_UNION:
            printf("UNION: %s\n", no->valor_str);
            break;
        case AST_ENUM:
            printf("ENUM: %s\n", no->valor_str);
            break;
        case AST_TYPEDEF:
            printf("TYPEDEF: %s\n", no->valor_str);
            break;
        case AST_MEMBER_ACCESS:
            printf("MEMBER_ACCESS\n");
            break;
        case AST_EMPTY:
            printf("EMPTY\n");
            break;
        default:
            printf("UNKNOWN_NODE_TYPE\n");
            break;
    }
    imprimirAST(no->filho1);
    imprimirAST(no->filho2);
    imprimirAST(no->filho3);
    imprimirAST(no->filho4);
    imprimirAST(no->prox);
}

void ast_to_dot(AST *node) {
    FILE *outfile = fopen("ast.dot", "w");
    if (outfile == NULL) {
        perror("Erro ao criar ast.dot");
        return;
    }

    fprintf(outfile, "digraph AST {\n");
    fprintf(outfile, "  node [shape=box];\n");

    node_counter = 0; // Resetar contador para cada nova geração de DOT
    ast_to_dot_node(node, outfile);

    fprintf(outfile, "}\n");
    fclose(outfile);
}


