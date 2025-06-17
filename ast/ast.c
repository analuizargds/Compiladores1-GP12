#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Variável global para contar os nós e gerar IDs únicos no DOT (para AST)
static int ast_node_counter = 0;

// Variável global para contar os nós do CFG e gerar IDs únicos no DOT
static int cfg_node_counter = 0;

// Lista global de todos os nós CFG criados para facilitar a liberação de memória
static CFGNode *cfg_nodes_head = NULL;

// Função auxiliar para adicionar um nó à lista global de nós CFG
static void add_cfg_node_to_list(CFGNode *node) {
    node->list_next = cfg_nodes_head;
    cfg_nodes_head = node;
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
    printf("  Node ID: %p, Type: %d, Value: %s\n", (void*)no, no->tipo, no->valor_str ? no->valor_str : "");
    if (no->filho1) printf("    Filho1: %p\n", (void*)no->filho1);
    if (no->filho2) printf("    Filho2: %p\n", (void*)no->filho2);
    if (no->filho3) printf("    Filho3: %p\n", (void*)no->filho3);
    if (no->filho4) printf("    Filho4: %p\n", (void*)no->filho4);
    if (no->prox) printf("    Prox: %p\n", (void*)no->prox);

    imprimirAST(no->filho1);
    imprimirAST(no->filho2);
    imprimirAST(no->filho3);
    imprimirAST(no->filho4);
    imprimirAST(no->prox);
}

// Função auxiliar para gerar o código DOT de um nó da AST
// Retorna o ID do nó gerado
static int generate_ast_dot_node(AST *node, FILE *outfile) {
    if (node == NULL) {
        return -1; // Invalid ID
    }

    int current_node_id = ast_node_counter++; // Assign unique ID and increment global counter
    char label[256]; // Buffer para o rótulo do nó

    switch (node->tipo) {
        case AST_LITERAL_INT:
            snprintf(label, sizeof(label), "INT: %d", node->valor_int);
            break;
        case AST_LITERAL_FLOAT:
            snprintf(label, sizeof(label), "FLOAT: %f", node->valor_float);
            break;
        case AST_LITERAL_STRING:
            snprintf(label, sizeof(label), "STRING: %s", node->valor_str ? node->valor_str : "");
            break;
        case AST_LITERAL_CHAR:
            snprintf(label, sizeof(label), "CHAR: %c", node->valor_char);
            break;
        case AST_LITERAL_HEX:
            snprintf(label, sizeof(label), "HEX: %s", node->valor_str ? node->valor_str : "");
            break;
        case AST_VAR:
            snprintf(label, sizeof(label), "VAR: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_BINARY_OP:
            snprintf(label, sizeof(label), "BIN_OP: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_UNARY_OP:
            snprintf(label, sizeof(label), "UNARY_OP: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_ASSIGN:
            snprintf(label, sizeof(label), "ASSIGN: %c", node->valor_char);
            break;
        case AST_IF:
            snprintf(label, sizeof(label), "IF");
            break;
        case AST_IF_ELSE:
            snprintf(label, sizeof(label), "IF_ELSE");
            break;
        case AST_WHILE:
            snprintf(label, sizeof(label), "WHILE");
            break;
        case AST_FOR:
            snprintf(label, sizeof(label), "FOR");
            break;
        case AST_DO_WHILE:
            snprintf(label, sizeof(label), "DO_WHILE");
            break;
        case AST_SWITCH:
            snprintf(label, sizeof(label), "SWITCH");
            break;
        case AST_RETURN:
            snprintf(label, sizeof(label), "RETURN");
            break;
        case AST_BREAK:
            snprintf(label, sizeof(label), "BREAK");
            break;
        case AST_CONTINUE:
            snprintf(label, sizeof(label), "CONTINUE");
            break;
        case AST_VAR_DECL:
            snprintf(label, sizeof(label), "VAR_DECL: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_FUNC_DECL:
            snprintf(label, sizeof(label), "FUNC_DECL: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_PARAM:
            snprintf(label, sizeof(label), "PARAM: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_TYPE:
            snprintf(label, sizeof(label), "TYPE: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_BLOCK:
            snprintf(label, sizeof(label), "BLOCK");
            break;
        case AST_CALL:
            snprintf(label, sizeof(label), "CALL: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_ARG_LIST:
            snprintf(label, sizeof(label), "ARG_LIST");
            break;
        case AST_CASE:
            snprintf(label, sizeof(label), "CASE");
            break;
        case AST_DEFAULT:
            snprintf(label, sizeof(label), "DEFAULT");
            break;
        case AST_INIT:
            snprintf(label, sizeof(label), "INIT");
            break;
        case AST_STRUCT:
            snprintf(label, sizeof(label), "STRUCT: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_UNION:
            snprintf(label, sizeof(label), "UNION: %s (%s)", node->valor_str ? node->valor_str : "UNKNOWN", node->valor_str2 ? node->valor_str2 : "UNKNOWN");
            break;
        case AST_ENUM:
            snprintf(label, sizeof(label), "ENUM: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_TYPEDEF:
            snprintf(label, sizeof(label), "TYPEDEF: %s", node->valor_str ? node->valor_str : "UNKNOWN");
            break;
        case AST_MEMBER_ACCESS:
            snprintf(label, sizeof(label), "MEMBER_ACCESS");
            break;
        case AST_EMPTY:
            snprintf(label, sizeof(label), "EMPTY");
            break;
        default:
            snprintf(label, sizeof(label), "UNKNOWN_NODE_TYPE");
            break;
    }

    fprintf(outfile, "  node%d [label=\"%s\"];\n", current_node_id, label);

    // Recursively generate DOT for children and draw edges
    int child_id;

    if (node->filho1 != NULL) {
        child_id = generate_ast_dot_node(node->filho1, outfile);
        if (child_id != -1) {
            fprintf(outfile, "  node%d -> node%d;\n", current_node_id, child_id);
        }
    }
    if (node->filho2 != NULL) {
        child_id = generate_ast_dot_node(node->filho2, outfile);
        if (child_id != -1) {
            fprintf(outfile, "  node%d -> node%d;\n", current_node_id, child_id);
        }
    }
    if (node->filho3 != NULL) {
        child_id = generate_ast_dot_node(node->filho3, outfile);
        if (child_id != -1) {
            fprintf(outfile, "  node%d -> node%d;\n", current_node_id, child_id);
        }
    }
    if (node->filho4 != NULL) {
        child_id = generate_ast_dot_node(node->filho4, outfile);
        if (child_id != -1) {
            fprintf(outfile, "  node%d -> node%d;\n", current_node_id, child_id);
        }
    }
    if (node->prox != NULL) {
        child_id = generate_ast_dot_node(node->prox, outfile);
        if (child_id != -1) {
            fprintf(outfile, "  node%d -> node%d [style=dotted];\n", current_node_id, child_id);
        }
    }
    return current_node_id;
}

void ast_to_dot(AST *node) {
    FILE *outfile = fopen("ast.dot", "w");
    if (!outfile) {
        perror("Erro ao criar ast.dot");
        return;
    }
    fprintf(outfile, "digraph AST {\n");
    fprintf(outfile, "  node [shape=box];\n"); // Optional: make nodes rectangular

    ast_node_counter = 0; // Reset counter for each new graph generation
    generate_ast_dot_node(node, outfile); // Call the helper

    fprintf(outfile, "}\n");
    fclose(outfile);
}


// Funções para criar nós do CFG
CFGNode *criarCFGNode(CFGNodeType type, const char *label, AST *ast_node_ref) {
    CFGNode *novoNo = (CFGNode *)malloc(sizeof(CFGNode));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para CFGNode");
        exit(EXIT_FAILURE);
    }
    novoNo->id = cfg_node_counter++;
    novoNo->type = type;
    novoNo->label = (label != NULL) ? strdup(label) : NULL;
    novoNo->edges = NULL;
    novoNo->ast_node_ref = ast_node_ref;
    novoNo->list_next = NULL;
    add_cfg_node_to_list(novoNo);
    return novoNo;
}

void add_cfg_edge(CFGNode *from, CFGNode *to, const char *label) {
    if (from == NULL || to == NULL) {
        return;
    }
    CFGEdge *novaAresta = (CFGEdge *)malloc(sizeof(CFGEdge));
    if (novaAresta == NULL) {
        perror("Erro ao alocar memória para CFGEdge");
        exit(EXIT_FAILURE);
    }
    novaAresta->to = to;
    novaAresta->label = (label != NULL) ? strdup(label) : NULL;
    novaAresta->next = from->edges;
    from->edges = novaAresta;
}

void liberarCFG(void) {
    CFGNode *current_node = cfg_nodes_head;
    while (current_node != NULL) {
        CFGNode *next_node = current_node->list_next;
        CFGEdge *current_edge = current_node->edges;
        while (current_edge != NULL) {
            CFGEdge *next_edge = current_edge->next;
            if (current_edge->label != NULL) {
                free(current_edge->label);
            }
            free(current_edge);
            current_edge = next_edge;
        }
        if (current_node->label != NULL) {
            free(current_node->label);
        }
        free(current_node);
        current_node = next_node;
    }
    cfg_nodes_head = NULL;
    cfg_node_counter = 0;
}

// Função principal para gerar o DOT do CFG
void cfg_to_dot(AST *node) {
    FILE *outfile = fopen("cfg.dot", "w");
    if (!outfile) {
        perror("Erro ao criar cfg.dot");
        return;
    }
    fprintf(outfile, "digraph CFG {\n");
    fprintf(outfile, "  node [shape=box];\n");

    liberarCFG(); // Limpa qualquer CFG anterior
    cfg_node_counter = 0; // Reinicia o contador de nós do CFG

    CFGFragment main_cfg = build_cfg_from_ast(node);

    // Percorre todos os nós do CFG criados e os escreve no arquivo DOT
    CFGNode *current_node = cfg_nodes_head;
    while (current_node != NULL) {
        char shape[32];
        char color[32];
        switch (current_node->type) {
            case CFG_NODE_ENTRY:
                strcpy(shape, "Mdiamond");
                strcpy(color, "green");
                break;
            case CFG_NODE_EXIT:
                strcpy(shape, "Msquare");
                strcpy(color, "red");
                break;
            case CFG_NODE_CONDITION:
                strcpy(shape, "diamond");
                strcpy(color, "blue");
                break;
            case CFG_NODE_LOOP_ENTRY:
                strcpy(shape, "octagon");
                strcpy(color, "purple");
                break;
            case CFG_NODE_LOOP_EXIT:
                strcpy(shape, "doubleoctagon");
                strcpy(color, "darkred");
                break;
            case CFG_NODE_FUNCTION_CALL:
                strcpy(shape, "parallelogram");
                strcpy(color, "orange");
                break;
            case CFG_NODE_RETURN:
                strcpy(shape, "pentagon");
                strcpy(color, "darkgreen");
                break;
            case CFG_NODE_BREAK:
            case CFG_NODE_CONTINUE:
                strcpy(shape, "triangle");
                strcpy(color, "brown");
                break;
            case CFG_NODE_BLOCK_ENTRY:
                strcpy(shape, "box");
                strcpy(color, "gray");
                break;
            case CFG_NODE_STATEMENT:
            case CFG_NODE_JOIN:
            default:
                strcpy(shape, "box");
                strcpy(color, "black");
                break;
        }
        fprintf(outfile, "  node%d [label=\"%s\", shape=%s, color=%s];\n",
                current_node->id, current_node->label ? current_node->label : "NULL", shape, color);

        CFGEdge *current_edge = current_node->edges;
        while (current_edge != NULL) {
            fprintf(outfile, "  node%d -> node%d [label=\"%s\"];\n",
                    current_node->id, current_edge->to->id, current_edge->label ? current_edge->label : "");
            current_edge = current_edge->next;
        }
        current_node = current_node->list_next;
    }

    fprintf(outfile, "}\n");
    fclose(outfile);
}

// Função para construir o CFG a partir da AST
CFGFragment build_cfg_from_ast(AST *node) {
    CFGFragment fragment = {NULL, NULL};

    if (node == NULL) {
        return fragment;
    }

    CFGNode *entry_node = NULL;
    CFGNode *exit_node = NULL;

    switch (node->tipo) {
        case AST_BLOCK: {
            entry_node = criarCFGNode(CFG_NODE_BLOCK_ENTRY, "Bloco", node);
            exit_node = entry_node; // Por enquanto, se o bloco estiver vazio

            AST *current_stmt = node->filho1; // O filho1 de um BLOCK é a lista de statements
            CFGNode *current_frag_entry = entry_node;

            while (current_stmt != NULL) {
                CFGFragment stmt_frag = build_cfg_from_ast(current_stmt);
                if (stmt_frag.entry != NULL) {
                    if (current_frag_entry == entry_node && entry_node->label == NULL) { // Se o nó de entrada do bloco ainda não tem um rótulo significativo, use o primeiro statement
                        // Isso é um hack para evitar um nó de bloco vazio no início
                        // Uma abordagem melhor seria ter um nó de entrada de bloco real e conectar
                        // o primeiro statement a ele.
                        // Por simplicidade, vamos apenas conectar o nó de entrada do bloco ao primeiro statement
                        add_cfg_edge(current_frag_entry, stmt_frag.entry, NULL);
                    } else {
                        add_cfg_edge(current_frag_entry, stmt_frag.entry, NULL);
                    }
                    current_frag_entry = stmt_frag.exit;
                }
                current_stmt = current_stmt->prox;
            }
            exit_node = current_frag_entry;
            break;
        }
        case AST_VAR_DECL: {
            char decl_label[256];
            snprintf(decl_label, sizeof(decl_label), "Decl: %s %s",
                     node->filho1->valor_str ? node->filho1->valor_str : "UNKNOWN_TYPE",
                     node->valor_str ? node->valor_str : "UNKNOWN_VAR");
            entry_node = criarCFGNode(CFG_NODE_STATEMENT, decl_label, node);
            exit_node = entry_node;
            break;
        }
        case AST_ASSIGN: {
            char assign_label[256];
            snprintf(assign_label, sizeof(assign_label), "Assign: %s %c ...",
                     node->filho1->valor_str ? node->filho1->valor_str : "UNKNOWN_VAR",
                     node->valor_char);
            entry_node = criarCFGNode(CFG_NODE_STATEMENT, assign_label, node);
            exit_node = entry_node;
            break;
        }
        case AST_CALL: {
            char call_label[256];
            snprintf(call_label, sizeof(call_label), "Call: %s(...)",
                     node->valor_str ? node->valor_str : "UNKNOWN_FUNC");
            entry_node = criarCFGNode(CFG_NODE_FUNCTION_CALL, call_label, node);
            exit_node = entry_node;
            break;
        }
        case AST_RETURN: {
            entry_node = criarCFGNode(CFG_NODE_RETURN, "Return", node);
            exit_node = entry_node;
            break;
        }
        case AST_IF: {
            // IF (cond) THEN_BLOCK ELSE_BLOCK
            CFGNode *cond_node = criarCFGNode(CFG_NODE_CONDITION, "IF", node->filho1);
            entry_node = cond_node;

            CFGFragment then_frag = build_cfg_from_ast(node->filho2); // thenBranch
            CFGFragment else_frag = build_cfg_from_ast(node->filho3); // elseBranch

            CFGNode *join_node = criarCFGNode(CFG_NODE_JOIN, "JOIN", NULL);
            exit_node = join_node;

            add_cfg_edge(cond_node, then_frag.entry, "True");
            add_cfg_edge(then_frag.exit, join_node, NULL);

            if (else_frag.entry != NULL) {
                add_cfg_edge(cond_node, else_frag.entry, "False");
                add_cfg_edge(else_frag.exit, join_node, NULL);
            } else {
                // If no else branch, connect False directly to join
                add_cfg_edge(cond_node, join_node, "False");
            }
            break;
        }
        case AST_WHILE: {
            // WHILE (cond) BODY
            CFGNode *loop_entry = criarCFGNode(CFG_NODE_LOOP_ENTRY, "WHILE_ENTRY", node);
            CFGNode *cond_node = criarCFGNode(CFG_NODE_CONDITION, "WHILE_COND", node->filho1);
            CFGNode *loop_exit = criarCFGNode(CFG_NODE_LOOP_EXIT, "WHILE_EXIT", NULL);

            entry_node = loop_entry;
            exit_node = loop_exit;

            add_cfg_edge(loop_entry, cond_node, NULL);

            CFGFragment body_frag = build_cfg_from_ast(node->filho2); // body

            add_cfg_edge(cond_node, body_frag.entry, "True");
            add_cfg_edge(body_frag.exit, loop_entry, NULL); // Loop back
            add_cfg_edge(cond_node, loop_exit, "False");
            break;
        }
        case AST_FOR: {
            // FOR (init; cond; increment) BODY
            CFGNode *for_init = criarCFGNode(CFG_NODE_STATEMENT, "FOR_INIT", node->filho1);
            CFGNode *loop_entry = criarCFGNode(CFG_NODE_LOOP_ENTRY, "FOR_ENTRY", node);
            CFGNode *cond_node = criarCFGNode(CFG_NODE_CONDITION, "FOR_COND", node->filho2);
            CFGNode *loop_exit = criarCFGNode(CFG_NODE_LOOP_EXIT, "FOR_EXIT", NULL);

            entry_node = for_init;
            exit_node = loop_exit;

            add_cfg_edge(for_init, loop_entry, NULL);
            add_cfg_edge(loop_entry, cond_node, NULL);

            CFGFragment body_frag = build_cfg_from_ast(node->filho4); // body
            CFGNode *increment_node = criarCFGNode(CFG_NODE_STATEMENT, "FOR_INCREMENT", node->filho3);

            add_cfg_edge(cond_node, body_frag.entry, "True");
            add_cfg_edge(body_frag.exit, increment_node, NULL);
            add_cfg_edge(increment_node, loop_entry, NULL); // Loop back
            add_cfg_edge(cond_node, loop_exit, "False");
            break;
        }
        case AST_DO_WHILE: {
            // DO BODY WHILE (cond)
            CFGNode *loop_entry = criarCFGNode(CFG_NODE_LOOP_ENTRY, "DO_WHILE_ENTRY", node);
            CFGNode *cond_node = criarCFGNode(CFG_NODE_CONDITION, "DO_WHILE_COND", node->filho1);
            CFGNode *loop_exit = criarCFGNode(CFG_NODE_LOOP_EXIT, "DO_WHILE_EXIT", NULL);

            entry_node = loop_entry;
            exit_node = loop_exit;

            CFGFragment body_frag = build_cfg_from_ast(node->filho2); // body

            add_cfg_edge(loop_entry, body_frag.entry, NULL);
            add_cfg_edge(body_frag.exit, cond_node, NULL);
            add_cfg_edge(cond_node, loop_entry, "True"); // Loop back
            add_cfg_edge(cond_node, loop_exit, "False");
            break;
        }
        case AST_BREAK: {
            entry_node = criarCFGNode(CFG_NODE_BREAK, "BREAK", node);
            exit_node = entry_node;
            // Special handling for break: needs to jump out of loop/switch
            // This will be handled by a later pass or context-aware CFG building
            break;
        }
        case AST_CONTINUE: {
            entry_node = criarCFGNode(CFG_NODE_CONTINUE, "CONTINUE", node);
            exit_node = entry_node;
            // Special handling for continue: needs to jump to next iteration
            // This will be handled by a later pass or context-aware CFG building
            break;
        }
        case AST_EMPTY: {
            // Represent empty statements as a no-op node or just skip
            entry_node = criarCFGNode(CFG_NODE_STATEMENT, "EMPTY_STMT", node);
            exit_node = entry_node;
            break;
        }
        // Para outros tipos de nós que representam statements simples ou expressões
        case AST_LITERAL_INT:
        case AST_LITERAL_FLOAT:
        case AST_LITERAL_STRING:
        case AST_LITERAL_CHAR:
        case AST_LITERAL_HEX:
        case AST_VAR:
        case AST_BINARY_OP:
        case AST_UNARY_OP:
        case AST_TYPE:
        case AST_PARAM:
        case AST_ARG_LIST:
        case AST_CASE:
        case AST_DEFAULT:
        case AST_INIT:
        case AST_STRUCT:
        case AST_UNION:
        case AST_ENUM:
        case AST_TYPEDEF:
        case AST_MEMBER_ACCESS:
            // Estes são nós de expressão ou parte de declarações, não statements de controle de fluxo por si só.
            // Eles geralmente são incorporados nos rótulos de outros nós ou ignorados para o CFG.
            // Para garantir que algo seja gerado, podemos criar um nó de statement genérico.
            {
                char expr_label[256];
                // Tenta obter um rótulo significativo
                if (node->valor_str) {
                    snprintf(expr_label, sizeof(expr_label), "Expr: %s", node->valor_str);
                } else if (node->tipo == AST_LITERAL_INT) {
                    snprintf(expr_label, sizeof(expr_label), "Int: %d", node->valor_int);
                } else if (node->tipo == AST_LITERAL_FLOAT) {
                    snprintf(expr_label, sizeof(expr_label), "Float: %f", node->valor_float);
                } else if (node->tipo == AST_LITERAL_CHAR) {
                    snprintf(expr_label, sizeof(expr_label), "Char: %c", node->valor_char);
                } else {
                    snprintf(expr_label, sizeof(expr_label), "Statement/Expr (Tipo %d)", node->tipo);
                }
                entry_node = criarCFGNode(CFG_NODE_STATEMENT, expr_label, node);
                exit_node = entry_node;
            }
            break;
        case AST_FUNC_DECL: {
            // Para declarações de função, o CFG principal deve ter um nó de entrada para a função
            // e o corpo da função será um sub-CFG.
            char func_label[256];
            snprintf(func_label, sizeof(func_label), "Function: %s", node->valor_str ? node->valor_str : "UNKNOWN_FUNC");
            entry_node = criarCFGNode(CFG_NODE_ENTRY, func_label, node);

            // Construir o CFG para o corpo da função
            CFGFragment body_frag = build_cfg_from_ast(node->filho3); // filho3 é o corpo da função

            if (body_frag.entry != NULL) {
                add_cfg_edge(entry_node, body_frag.entry, NULL);
                exit_node = body_frag.exit;
            } else {
                // Função vazia ou com corpo inválido
                exit_node = criarCFGNode(CFG_NODE_EXIT, "Function Exit (Empty Body)", NULL);
                add_cfg_edge(entry_node, exit_node, NULL);
            }
            break;
        }
        default:
            // Para tipos de nós não tratados explicitamente, crie um nó genérico
            {
                char generic_label[256];
                snprintf(generic_label, sizeof(generic_label), "Nó AST (Tipo %d)", node->tipo);
                entry_node = criarCFGNode(CFG_NODE_STATEMENT, generic_label, node);
                exit_node = entry_node;
            }
            break;
    }

    fragment.entry = entry_node;
    fragment.exit = exit_node;
    return fragment;
}


