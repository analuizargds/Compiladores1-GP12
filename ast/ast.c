#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Variável global para contar os nós do CFG e gerar IDs únicos
static int cfg_node_counter = 0;

// Lista global de todos os nós CFG criados para facilitar a liberação de memória
static CFGNode *cfg_nodes_head = NULL;

// Função auxiliar para adicionar um nó à lista global de nós CFG
static void add_cfg_node_to_list(CFGNode *node)
{
    node->list_next = cfg_nodes_head;
    cfg_nodes_head = node;
}

// Funções para criar nós da AST
ASTNode *criarNo(ASTNodeType tipo, const char *valor_str)
{
    ASTNode *novoNo = (ASTNode *)malloc(sizeof(ASTNode));
    if (novoNo == NULL)
    {
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

ASTNode *criarNoInt(int valor)
{
    ASTNode *novoNo = criarNo(AST_LITERAL_INT, NULL);
    novoNo->valor_int = valor;
    return novoNo;
}

ASTNode *criarNoFloat(float valor)
{
    ASTNode *novoNo = criarNo(AST_LITERAL_FLOAT, NULL);
    novoNo->valor_float = valor;
    return novoNo;
}

ASTNode *criarNoString(const char *str)
{
    return criarNo(AST_LITERAL_STRING, str);
}

ASTNode *criarNoChar(char c)
{
    ASTNode *novoNo = criarNo(AST_LITERAL_CHAR, NULL);
    novoNo->valor_char = c;
    return novoNo;
}

ASTNode *criarNoHex(const char *str)
{
    return criarNo(AST_LITERAL_HEX, str);
}

ASTNode *criarNoVar(const char *id)
{
    return criarNo(AST_VAR, id);
}

ASTNode *criarNoType(const char *tipo)
{
    return criarNo(AST_TYPE, tipo);
}

ASTNode *criarNoBinOp(const char *op, ASTNode *esq, ASTNode *dir)
{
    ASTNode *novoNo = criarNo(AST_BINARY_OP, op);
    novoNo->filho1 = esq;
    novoNo->filho2 = dir;
    return novoNo;
}

ASTNode *criarNoUnaryOp(char *op, ASTNode *expr)
{
    ASTNode *novoNo = criarNo(AST_UNARY_OP, op);
    novoNo->filho1 = expr;
    return novoNo;
}

ASTNode *criarNoAssign(char op, ASTNode *var, ASTNode *expr)
{
    ASTNodeType tipo;
    switch (op)
    {
    case '=':
        tipo = AST_ASSIGN;
        break;
    case '+':
        tipo = AST_PLUS_ASSIGN;
        break;
    case '-':
        tipo = AST_MINUS_ASSIGN;
        break;
    case '*':
        tipo = AST_MULT_ASSIGN;
        break;
    case '/':
        tipo = AST_DIV_ASSIGN;
        break;
    case '%':
        tipo = AST_MOD_ASSIGN;
        break;
    default:
        tipo = AST_ASSIGN;
    }
    ASTNode *no = criarNo(tipo, NULL);
    no->filho1 = var;
    no->filho2 = expr;
    return no;
}

ASTNode *criarNoTernario(ASTNode *cond, ASTNode *expr_true, ASTNode *expr_false)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->tipo = AST_TERNARY;
    node->filho1 = cond;
    node->filho2 = expr_true;
    node->filho3 = expr_false;
    node->valor_str = NULL;
    return node;
}

ASTNode *criarNoIf(ASTNode *cond, ASTNode *thenBranch, ASTNode *elseBranch)
{
    ASTNode *no = criarNo(elseBranch ? AST_IF_ELSE : AST_IF, NULL);
    no->filho1 = cond;
    no->filho2 = thenBranch;
    no->filho3 = elseBranch;
    return no;
}

ASTNode *criarNoWhile(ASTNode *cond, ASTNode *body)
{
    ASTNode *novoNo = criarNo(AST_WHILE, NULL);
    novoNo->filho1 = cond;
    novoNo->filho2 = body;
    return novoNo;
}

ASTNode *criarNoDoWhile(ASTNode *cond, ASTNode *body)
{
    ASTNode *novoNo = criarNo(AST_DO_WHILE, NULL);
    novoNo->filho1 = cond;
    novoNo->filho2 = body;
    return novoNo;
}

ASTNode *criarNoFor(ASTNode *init, ASTNode *cond, ASTNode *increment, ASTNode *body)
{
    ASTNode *novoNo = criarNo(AST_FOR, NULL);
    novoNo->filho1 = init;
    novoNo->filho2 = cond;
    novoNo->filho3 = increment;
    novoNo->filho4 = body;
    return novoNo;
}

ASTNode *criarNoReturn(ASTNode *expr)
{
    ASTNode *novoNo = criarNo(AST_RETURN, NULL);
    novoNo->filho1 = expr;
    return novoNo;
}

ASTNode *criarNoBreak(void)
{
    return criarNo(AST_BREAK, NULL);
}

ASTNode *criarNoContinue(void)
{
    return criarNo(AST_CONTINUE, NULL);
}

ASTNode *criarNoVarDecl(const char *id, ASTNode *tipo)
{
    ASTNode *novoNo = criarNo(AST_VAR_DECL, id);
    novoNo->filho1 = tipo;
    return novoNo;
}

ASTNode *criarNoFuncDecl(const char *id, ASTNode *tipo, ASTNode *params, ASTNode *body)
{
    ASTNode *novoNo = criarNo(AST_FUNC_DECL, id);
    novoNo->filho1 = tipo;
    novoNo->filho2 = params;
    novoNo->filho3 = body;
    return novoNo;
}

ASTNode *criarNoParam(const char *id, ASTNode *tipo)
{
    ASTNode *novoNo = criarNo(AST_PARAM, id);
    novoNo->filho1 = tipo;
    return novoNo;
}

ASTNode *criarNoBlock(ASTNode *stmtList)
{
    ASTNode *novoNo = criarNo(AST_BLOCK, NULL);
    novoNo->filho1 = stmtList;
    return novoNo;
}

ASTNode *criarNoCall(const char *id, ASTNode *args)
{
    ASTNode *novoNo = criarNo(AST_CALL, id);
    novoNo->filho1 = args;
    return novoNo;
}

ASTNode *criarNoSwitch(ASTNode *expr, ASTNode *cases)
{
    ASTNode *novoNo = criarNo(AST_SWITCH, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = cases;
    return novoNo;
}

ASTNode *criarNoCase(ASTNode *expr, ASTNode *stmts)
{
    ASTNode *novoNo = criarNo(AST_CASE, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = stmts;
    return novoNo;
}

ASTNode *criarNoInit(ASTNode *expr, ASTNode *lista)
{
    ASTNode *novoNo = criarNo(AST_INIT, NULL);
    novoNo->filho1 = expr;
    novoNo->filho2 = lista;
    return novoNo;
}

ASTNode *criarNoUnion(const char *tipo, const char *id)
{
    ASTNode *novoNo = criarNo(AST_UNION, id);
    novoNo->valor_str2 = strdup(tipo);
    return novoNo;
}

ASTNode *criarNoEnum(const char *id)
{
    return criarNo(AST_ENUM, id);
}

// Funções para manipular a AST
ASTNode *concatenarStmt(ASTNode *lista, ASTNode *no)
{
    if (lista == NULL)
    {
        return no;
    }
    else
    {
        ASTNode *temp = lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

ASTNode *concatenarParam(ASTNode *lista, ASTNode *no)
{
    if (lista == NULL)
    {
        return no;
    }
    else
    {
        ASTNode *temp = lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

ASTNode *concatenarArg(ASTNode *lista, ASTNode *no)
{
    if (lista == NULL)
    {
        return no;
    }
    else
    {
        ASTNode *temp = lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = no;
        return lista;
    }
}

void liberarAST(ASTNode *no)
{
    if (no == NULL)
    {
        return;
    }
    liberarAST(no->filho1);
    liberarAST(no->filho2);
    liberarAST(no->filho3);
    liberarAST(no->filho4);
    liberarAST(no->prox);

    if (no->valor_str != NULL)
    {
        free(no->valor_str);
    }
    if (no->valor_str2 != NULL)
    {
        free(no->valor_str2);
    }
    free(no);
}

// Função auxiliar para gerar uma string descritiva de um nó da AST
// Retorna uma string alocada dinamicamente que deve ser liberada pelo chamador
char *ast_node_to_string(AST *node)
{
    if (node == NULL)
    {
        return strdup("NULL");
    }

    char buffer[256];

    switch (node->tipo)
    {
    case AST_LITERAL_INT:
        snprintf(buffer, sizeof(buffer), "%d", node->valor_int);
        break;
    case AST_LITERAL_FLOAT:
        snprintf(buffer, sizeof(buffer), "%f", node->valor_float);
        break;
    case AST_LITERAL_STRING:
        snprintf(buffer, sizeof(buffer), "\"%s\"", node->valor_str ? node->valor_str : "");
        break;
    case AST_LITERAL_CHAR:
        snprintf(buffer, sizeof(buffer), "\'%c\'", node->valor_char);
        break;
    case AST_LITERAL_HEX:
        snprintf(buffer, sizeof(buffer), "%s", node->valor_str ? node->valor_str : "");
        break;
    case AST_VAR:
        snprintf(buffer, sizeof(buffer), "%s", node->valor_str ? node->valor_str : "UNKNOWN_VAR");
        break;
    case AST_BINARY_OP:
    {
        char *left_str = ast_node_to_string(node->filho1);
        char *right_str = ast_node_to_string(node->filho2);
        char *op = node->valor_str ? node->valor_str : "OP";

        // Para operadores de comparação, mostrar de forma mais clara
        if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
            strcmp(op, ">") == 0 || strcmp(op, "<") == 0 ||
            strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0 ||
            strcmp(op, "&&") == 0 || strcmp(op, "||") == 0)
        {
            snprintf(buffer, sizeof(buffer), "%s %s %s", left_str, op, right_str);
        }
        else
        {
            snprintf(buffer, sizeof(buffer), "%s %s %s", left_str, op, right_str);
        }
        free(left_str);
        free(right_str);
        break;
    }
    case AST_UNARY_OP:
    {
        char *expr_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "%s%s", node->valor_str ? node->valor_str : "OP", expr_str);
        free(expr_str);
        break;
    }
    case AST_ASSIGN:
    {
        char *var_str = ast_node_to_string(node->filho1);
        char *expr_str = ast_node_to_string(node->filho2);
        snprintf(buffer, sizeof(buffer), "%s = %s", var_str, expr_str);
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_PLUS_ASSIGN:
    {
        char *var_str = ast_node_to_string(node->filho1);
        char *expr_str = ast_node_to_string(node->filho2);
        snprintf(buffer, sizeof(buffer), "%s += %s", var_str, expr_str);
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_MINUS_ASSIGN:
    {
        char *var_str = ast_node_to_string(node->filho1);
        char *expr_str = ast_node_to_string(node->filho2);
        snprintf(buffer, sizeof(buffer), "%s -= %s", var_str, expr_str);
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_MULT_ASSIGN:
    {
        char *var_str = ast_node_to_string(node->filho1);
        char *expr_str = ast_node_to_string(node->filho2);
        snprintf(buffer, sizeof(buffer), "%s *= %s", var_str, expr_str);
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_DIV_ASSIGN:
    {
        char *var_str = ast_node_to_string(node->filho1);
        char *expr_str = ast_node_to_string(node->filho2);
        snprintf(buffer, sizeof(buffer), "%s /= %s", var_str, expr_str);
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_IF:
        snprintf(buffer, sizeof(buffer), "IF");
        break;
    case AST_IF_ELSE:
        snprintf(buffer, sizeof(buffer), "IF_ELSE");
        break;
    case AST_WHILE:
        snprintf(buffer, sizeof(buffer), "WHILE");
        break;
    case AST_FOR:
        snprintf(buffer, sizeof(buffer), "FOR");
        break;
    case AST_DO_WHILE:
        snprintf(buffer, sizeof(buffer), "DO_WHILE");
        break;
    case AST_SWITCH:
        snprintf(buffer, sizeof(buffer), "SWITCH");
        break;
    case AST_RETURN:
    {
        char *expr_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "RETURN %s", expr_str);
        free(expr_str);
        break;
    }
    case AST_BREAK:
        snprintf(buffer, sizeof(buffer), "BREAK");
        break;
    case AST_CONTINUE:
        snprintf(buffer, sizeof(buffer), "CONTINUE");
        break;
    case AST_VAR_DECL:
    {
        char *type_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "VAR_DECL: %s %s", type_str, node->valor_str ? node->valor_str : "UNKNOWN");
        free(type_str);
        break;
    }
    case AST_FUNC_DECL:
        snprintf(buffer, sizeof(buffer), "FUNC_DECL: %s", node->valor_str ? node->valor_str : "UNKNOWN");
        break;
    case AST_PARAM:
    {
        char *type_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "PARAM: %s %s", type_str, node->valor_str ? node->valor_str : "UNKNOWN");
        free(type_str);
        break;
    }
    case AST_TYPE:
        snprintf(buffer, sizeof(buffer), "TYPE: %s", node->valor_str ? node->valor_str : "UNKNOWN");
        break;
    case AST_BLOCK:
        snprintf(buffer, sizeof(buffer), "BLOCK");
        break;
    case AST_CALL:
    {
        char *call_name = node->valor_str ? node->valor_str : "UNKNOWN";
        // For Mermaid, we'll put arguments in separate nodes, so just the call name here
        snprintf(buffer, sizeof(buffer), "CALL: %s", call_name);
        break;
    }
    case AST_ARG_LIST:
    {
        snprintf(buffer, sizeof(buffer), "ARG_LIST");
        break;
    }
    case AST_CASE:
    {
        char *expr_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "CASE %s", expr_str);
        free(expr_str);
        break;
    }
    case AST_DEFAULT:
        snprintf(buffer, sizeof(buffer), "DEFAULT");
        break;
    case AST_INIT:
    {
        char *expr_str = ast_node_to_string(node->filho1);
        snprintf(buffer, sizeof(buffer), "= %s", expr_str);
        free(expr_str);
        break;
    }
    case AST_TERNARY:
    {
        char *cond_str = ast_node_to_string(node->filho1);
        char *true_str = ast_node_to_string(node->filho2);
        char *false_str = ast_node_to_string(node->filho3);
        snprintf(buffer, sizeof(buffer), "%s ? %s : %s", cond_str, true_str, false_str);
        free(cond_str);
        free(true_str);
        free(false_str);
        break;
    }
    case AST_STRUCT:
        snprintf(buffer, sizeof(buffer), "STRUCT: %s", node->valor_str ? node->valor_str : "UNKNOWN");
        break;
    case AST_UNION:
        snprintf(buffer, sizeof(buffer), "UNION: %s (%s)", node->valor_str ? node->valor_str : "UNKNOWN", node->valor_str2 ? node->valor_str2 : "UNKNOWN");
        break;
    case AST_ENUM:
        snprintf(buffer, sizeof(buffer), "ENUM: %s", node->valor_str ? node->valor_str : "UNKNOWN");
        break;
    case AST_TYPEDEF:
        snprintf(buffer, sizeof(buffer), "TYPEDEF: %s", node->valor_str ? node->valor_str : "UNKNOWN");
        break;
    case AST_MEMBER_ACCESS:
        snprintf(buffer, sizeof(buffer), "MEMBER_ACCESS");
        break;
    case AST_EMPTY:
        snprintf(buffer, sizeof(buffer), "EMPTY");
        break;
    case AST_PROGRAM:
        snprintf(buffer, sizeof(buffer), "PROGRAM");
        break;
    case AST_LAST_NODE_TYPE:
        snprintf(buffer, sizeof(buffer), "LAST_NODE_TYPE");
        break;
    default:
        snprintf(buffer, sizeof(buffer), "UNKNOWN_NODE_TYPE (%d)", node->tipo);
        break;
    }
    return strdup(buffer);
}

// Funções para o Control Flow Graph (CFG)
CFGNode *criarCFGNode(CFGNodeType type, const char *label, AST *ast_node_ref)
{
    CFGNode *newNode = (CFGNode *)malloc(sizeof(CFGNode));
    if (newNode == NULL)
    {
        perror("Erro ao alocar memória para CFGNode");
        exit(EXIT_FAILURE);
    }
    newNode->id = cfg_node_counter++;
    newNode->type = type;
    newNode->label = (label != NULL) ? strdup(label) : NULL;
    newNode->edges = NULL;
    newNode->ast_node_ref = ast_node_ref;
    newNode->list_next = NULL; // Inicializa como NULL, será adicionado à lista global
    newNode->visited = 0;      // Para travessias de grafo
    add_cfg_node_to_list(newNode);
    return newNode;
}

void add_cfg_edge(CFGNode *from, CFGNode *to, const char *label)
{
    if (from == NULL || to == NULL)
        return;

    CFGEdge *newEdge = (CFGEdge *)malloc(sizeof(CFGEdge));
    if (newEdge == NULL)
    {
        perror("Erro ao alocar memória para CFGEdge");
        exit(EXIT_FAILURE);
    }
    newEdge->to = to;
    newEdge->label = (label != NULL) ? strdup(label) : NULL;
    newEdge->next = from->edges;
    from->edges = newEdge;
}

void liberarCFG(void)
{
    CFGNode *current_node = cfg_nodes_head;
    while (current_node != NULL)
    {
        CFGNode *next_node = current_node->list_next;
        if (current_node->label)
        {
            free(current_node->label);
        }
        CFGEdge *current_edge = current_node->edges;
        while (current_edge != NULL)
        {
            CFGEdge *next_edge = current_edge->next;
            if (current_edge->label)
            {
                free(current_edge->label);
            }
            free(current_edge);
            current_edge = next_edge;
        }
        free(current_node);
        current_node = next_node;
    }
    cfg_nodes_head = NULL;
    cfg_node_counter = 0;
}

CFGFragment build_cfg_for_program(AST *program_node)
{
    CFGFragment program_fragment = {NULL, NULL};
    CFGNode *last_exit = NULL;

    if (program_node == NULL)
    {
        return program_fragment;
    }

    // Se for um nó PROGRAM, processe seus filhos
    AST *current_decl = NULL;
    if (program_node->tipo == AST_PROGRAM)
    {
        current_decl = program_node->filho1;
    }
    else
    {
        // Se não houver nó PROGRAM explícito, trate o nó atual como primeira declaração
        current_decl = program_node;
    }

    // Processe todas as declarações (funções, variáveis globais, etc.)
    while (current_decl != NULL)
    {
        if (current_decl->tipo == AST_FUNC_DECL)
        {
            CFGFragment func_fragment = build_cfg_from_ast_recursive(current_decl, NULL, NULL);

            if (func_fragment.entry && func_fragment.exit)
            {
                if (program_fragment.entry == NULL)
                {
                    program_fragment.entry = func_fragment.entry;
                }
                if (last_exit != NULL)
                {
                    // Não conecte funções entre si - cada função é independente
                    // add_cfg_edge(last_exit, func_fragment.entry, NULL);
                }
                last_exit = func_fragment.exit;
                program_fragment.exit = func_fragment.exit;
            }
        }
        current_decl = current_decl->prox;
    }

    return program_fragment;
}

// Função principal para construir o CFG a partir da AST
CFGFragment build_cfg_from_ast_recursive(AST *node, CFGNode *entry_node, CFGNode *exit_node)
{
    CFGFragment fragment = {NULL, NULL};

    if (node == NULL)
    {
        fragment.entry = entry_node;
        fragment.exit = exit_node;
        return fragment;
    }

    switch (node->tipo)
    {
    case AST_FUNC_DECL:
    {
        // Create start and end nodes for the function
        char func_label[256];
        snprintf(func_label, sizeof(func_label), "Start: %s", node->valor_str ? node->valor_str : "function");
        CFGNode *start_node = criarCFGNode(CFG_NODE_ENTRY, func_label, node);
        CFGNode *end_node = criarCFGNode(CFG_NODE_EXIT, "End", NULL);
        fragment.entry = start_node;
        fragment.exit = end_node;

        // Process function body (typically a block)
        if (node->filho3)
        { // Function body
            CFGFragment body_frag = build_cfg_from_ast_recursive(node->filho3, start_node, end_node);
            if (body_frag.entry && body_frag.exit)
            {
                add_cfg_edge(start_node, body_frag.entry, NULL);
                add_cfg_edge(body_frag.exit, end_node, NULL);
            }
            else
            {
                add_cfg_edge(start_node, end_node, NULL);
            }
        }
        else
        {
            add_cfg_edge(start_node, end_node, NULL);
        }
        break;
    }
    case AST_BLOCK:
    {
        // For blocks, we don't create separate entry/exit nodes
        // Instead, we process statements sequentially
        CFGNode *current_entry = NULL;
        CFGNode *current_exit = NULL;

        AST *current_stmt = node->filho1;
        while (current_stmt != NULL)
        {
            CFGFragment stmt_frag = build_cfg_from_ast_recursive(current_stmt, NULL, NULL);
            if (stmt_frag.entry && stmt_frag.exit)
            {
                if (current_entry == NULL)
                {
                    current_entry = stmt_frag.entry;
                }
                if (current_exit != NULL)
                {
                    add_cfg_edge(current_exit, stmt_frag.entry, NULL);
                }
                current_exit = stmt_frag.exit;
            }
            current_stmt = current_stmt->prox;
        }

        fragment.entry = current_entry;
        fragment.exit = current_exit;
        break;
    }
    case AST_VAR_DECL:
    {
        // Verificar se é uma declaração com inicialização (nó AST_ASSIGN)
        if (node->tipo == AST_VAR_DECL && node->prox && node->prox->tipo == AST_ASSIGN)
        {
            // Criar nó de declaração
            char *decl_label = ast_node_to_string_with_values(node);
            CFGNode *decl_node = criarCFGNode(CFG_NODE_STATEMENT, decl_label, node);
            
            // Criar nó de atribuição
            char *assign_label = ast_node_to_string_with_values(node->prox);
            CFGNode *assign_node = criarCFGNode(CFG_NODE_STATEMENT, assign_label, node->prox);
            
            // Conectar com linha pontilhada
            add_cfg_edge(decl_node, assign_node, "");
            
            fragment.entry = decl_node;
            fragment.exit = assign_node;
            
            free(decl_label);
            free(assign_label);
            
            // Pular o próximo nó (AST_ASSIGN) já processado
            if (node->prox && node->prox->prox)
            {
                CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox->prox, NULL, NULL);
                if (sibling_frag.entry && sibling_frag.exit)
                {
                    add_cfg_edge(fragment.exit, sibling_frag.entry, NULL);
                    fragment.exit = sibling_frag.exit;
                }
            }
        }
        else
        {
            // Declaração simples sem inicialização
            char *node_label = ast_node_to_string_with_values(node);
            CFGNode *stmt_node = criarCFGNode(CFG_NODE_STATEMENT, node_label, node);
            fragment.entry = stmt_node;
            fragment.exit = stmt_node;
            free(node_label);

            // Se há inicialização (AST_INIT), criar nó de atribuição separado
            if (node->filho2 && node->filho2->tipo == AST_INIT)
            {
                // Criar rótulo de atribuição mostrando var = valor
                char assign_label[256];
                char *var_name = node->valor_str ? node->valor_str : "var";
                char *init_value = ast_node_to_string_with_values(node->filho2->filho1);
                snprintf(assign_label, sizeof(assign_label), "%s = %s", var_name, init_value);
                
                CFGNode *assign_node = criarCFGNode(CFG_NODE_STATEMENT, assign_label, node->filho2);
                add_cfg_edge(stmt_node, assign_node, "");  // Linha pontilhada vazia
                fragment.exit = assign_node;
                free(init_value);
            }
            // Se há inicialização direta (AST_ASSIGN), criar nó de atribuição separado
            else if (node->filho2 && node->filho2->tipo == AST_ASSIGN)
            {
                char *assign_label = ast_node_to_string_with_values(node->filho2);
                CFGNode *assign_node = criarCFGNode(CFG_NODE_STATEMENT, assign_label, node->filho2);
                add_cfg_edge(stmt_node, assign_node, "");  // Linha pontilhada vazia
                fragment.exit = assign_node;
                free(assign_label);
            }

            // Check if there are sibling nodes
            if (node->prox)
            {
                CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
                if (sibling_frag.entry && sibling_frag.exit)
                {
                    add_cfg_edge(fragment.exit, sibling_frag.entry, NULL);
                    fragment.exit = sibling_frag.exit;
                }
            }
        }
        break;
    }
    case AST_ASSIGN:
    case AST_PLUS_ASSIGN:
    case AST_MINUS_ASSIGN:
    case AST_MULT_ASSIGN:
    case AST_DIV_ASSIGN:
    case AST_MOD_ASSIGN:
    {
        char *node_label = ast_node_to_string_with_values(node);
        CFGNode *stmt_node = criarCFGNode(CFG_NODE_STATEMENT, node_label, node);
        fragment.entry = stmt_node;
        fragment.exit = stmt_node;
        free(node_label);

        // Check if there are sibling nodes
        if (node->prox)
        {
            CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
            if (sibling_frag.entry && sibling_frag.exit)
            {
                add_cfg_edge(stmt_node, sibling_frag.entry, NULL);
                fragment.exit = sibling_frag.exit;
            }
        }
        break;
    }
    case AST_UNARY_OP:
    {
        char *node_label = ast_node_to_string(node);
        CFGNode *stmt_node = criarCFGNode(CFG_NODE_STATEMENT, node_label, node);
        fragment.entry = stmt_node;
        fragment.exit = stmt_node;
        free(node_label);

        // Check if there are sibling nodes
        if (node->prox)
        {
            CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
            if (sibling_frag.entry && sibling_frag.exit)
            {
                add_cfg_edge(stmt_node, sibling_frag.entry, NULL);
                fragment.exit = sibling_frag.exit;
            }
        }
        break;
    }
    case AST_BINARY_OP:
    case AST_TERNARY:
    {
        // Tratar expressões como statements quando não fazem parte de uma atribuição
        char *node_label = ast_node_to_string(node);
        CFGNode *stmt_node = criarCFGNode(CFG_NODE_STATEMENT, node_label, node);
        fragment.entry = stmt_node;
        fragment.exit = stmt_node;
        free(node_label);

        // Check if there are sibling nodes
        if (node->prox)
        {
            CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
            if (sibling_frag.entry && sibling_frag.exit)
            {
                add_cfg_edge(stmt_node, sibling_frag.entry, NULL);
                fragment.exit = sibling_frag.exit;
            }
        }
        break;
    }
    case AST_RETURN:
    {
        char *node_label = ast_node_to_string(node);
        CFGNode *stmt_node = criarCFGNode(CFG_NODE_RETURN, node_label, node);
        fragment.entry = stmt_node;
        fragment.exit = stmt_node;
        free(node_label);

        // Check if there are sibling nodes
        if (node->prox)
        {
            CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
            if (sibling_frag.entry && sibling_frag.exit)
            {
                add_cfg_edge(stmt_node, sibling_frag.entry, NULL);
                fragment.exit = sibling_frag.exit;
            }
        }
        break;
    }
    case AST_CALL:
    {
        char *node_label = ast_node_to_string(node);
        CFGNode *call_node = criarCFGNode(CFG_NODE_FUNCTION_CALL, node_label, node);
        fragment.entry = call_node;
        fragment.exit = call_node;
        free(node_label);
        break;
    }
    case AST_IF:
    case AST_IF_ELSE:
    {
        // Create condition node
        char *cond_label = ast_node_to_string(node->filho1);
        CFGNode *cond_node = criarCFGNode(CFG_NODE_CONDITION, cond_label, node->filho1);
        CFGNode *join_node = criarCFGNode(CFG_NODE_JOIN, "", NULL);
        fragment.entry = cond_node;
        fragment.exit = join_node;
        free(cond_label);

        // Process THEN branch
        if (node->filho2)
        {
            CFGFragment then_frag = build_cfg_from_ast_recursive(node->filho2, NULL, NULL);
            if (then_frag.entry && then_frag.exit)
            {
                add_cfg_edge(cond_node, then_frag.entry, "True");
                add_cfg_edge(then_frag.exit, join_node, NULL);
            }
            else
            {
                add_cfg_edge(cond_node, join_node, "True");
            }
        }
        else
        {
            add_cfg_edge(cond_node, join_node, "True");
        }

        // Process ELSE branch if it exists
        if (node->filho3)
        {
            CFGFragment else_frag = build_cfg_from_ast_recursive(node->filho3, NULL, NULL);
            if (else_frag.entry && else_frag.exit)
            {
                add_cfg_edge(cond_node, else_frag.entry, "False");
                add_cfg_edge(else_frag.exit, join_node, NULL);
            }
            else
            {
                add_cfg_edge(cond_node, join_node, "False");
            }
        }
        else
        {
            // No ELSE branch, False goes directly to join
            add_cfg_edge(cond_node, join_node, "False");
        }

        // Check if there are sibling nodes after the IF
        if (node->prox)
        {
            CFGFragment sibling_frag = build_cfg_from_ast_recursive(node->prox, NULL, NULL);
            if (sibling_frag.entry && sibling_frag.exit)
            {
                add_cfg_edge(join_node, sibling_frag.entry, NULL);
                fragment.exit = sibling_frag.exit;
            }
        }
        break;
    }
    case AST_WHILE:
    {
        char *cond_label = ast_node_to_string(node->filho1);
        CFGNode *loop_cond_node = criarCFGNode(CFG_NODE_CONDITION, cond_label, node->filho1);
        CFGNode *loop_exit_node = criarCFGNode(CFG_NODE_JOIN, "", NULL);
        fragment.entry = loop_cond_node;
        fragment.exit = loop_exit_node;
        free(cond_label);

        // Loop body
        if (node->filho2)
        {
            CFGFragment body_frag = build_cfg_from_ast_recursive(node->filho2, NULL, NULL);
            if (body_frag.entry && body_frag.exit)
            {
                add_cfg_edge(loop_cond_node, body_frag.entry, "True");
                add_cfg_edge(body_frag.exit, loop_cond_node, NULL); // Loop back to condition
            }
            else
            {
                add_cfg_edge(loop_cond_node, loop_cond_node, "True");
            }
        }
        else
        {
            add_cfg_edge(loop_cond_node, loop_cond_node, "True");
        }

        add_cfg_edge(loop_cond_node, loop_exit_node, "False");
        break;
    }
    case AST_FOR:
    {
        // For loops: init -> condition -> body -> increment -> condition
        CFGNode *init_node = NULL;
        CFGNode *cond_node = NULL;
        CFGNode *incr_node = NULL;
        CFGNode *exit_node = criarCFGNode(CFG_NODE_JOIN, "", NULL);

        // Process initialization
        if (node->filho1)
        {
            char *init_label = ast_node_to_string(node->filho1);
            init_node = criarCFGNode(CFG_NODE_STATEMENT, init_label, node->filho1);
            free(init_label);
        }

        // Process condition
        if (node->filho2)
        {
            char *cond_label = ast_node_to_string(node->filho2);
            cond_node = criarCFGNode(CFG_NODE_CONDITION, cond_label, node->filho2);
            free(cond_label);
        }

        // Process increment
        if (node->filho4)
        {
            char *incr_label = ast_node_to_string(node->filho4);
            incr_node = criarCFGNode(CFG_NODE_STATEMENT, incr_label, node->filho4);
            free(incr_label);
        }

        fragment.entry = init_node ? init_node : (cond_node ? cond_node : exit_node);
        fragment.exit = exit_node;

        // Connect nodes
        if (init_node && cond_node)
        {
            add_cfg_edge(init_node, cond_node, NULL);
        }

        if (cond_node)
        {
            add_cfg_edge(cond_node, exit_node, "False");

            // Process body
            if (node->filho3)
            {
                CFGFragment body_frag = build_cfg_from_ast_recursive(node->filho3, NULL, NULL);
                if (body_frag.entry && body_frag.exit)
                {
                    add_cfg_edge(cond_node, body_frag.entry, "True");
                    if (incr_node)
                    {
                        add_cfg_edge(body_frag.exit, incr_node, NULL);
                        add_cfg_edge(incr_node, cond_node, NULL);
                    }
                    else
                    {
                        add_cfg_edge(body_frag.exit, cond_node, NULL);
                    }
                }
                else
                {
                    if (incr_node)
                    {
                        add_cfg_edge(cond_node, incr_node, "True");
                        add_cfg_edge(incr_node, cond_node, NULL);
                    }
                    else
                    {
                        add_cfg_edge(cond_node, cond_node, "True");
                    }
                }
            }
        }
        break;
    }
    default:
    {
        // For unhandled AST nodes, try to process children
        if (node->filho1)
        {
            return build_cfg_from_ast_recursive(node->filho1, entry_node, exit_node);
        }
        else
        {
            // Create a simple statement node as fallback
            char *node_label = ast_node_to_string(node);
            CFGNode *stmt_node = criarCFGNode(CFG_NODE_STATEMENT, node_label, node);
            fragment.entry = stmt_node;
            fragment.exit = stmt_node;
            free(node_label);
        }
        break;
    }
    }

    return fragment;
}

// Função para gerar o arquivo Mermaid a partir do CFG
void cfg_to_mermaid(AST *root_ast)
{
    FILE *fp = fopen("cfg.mmd", "w");
    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo cfg.mmd");
        return;
    }

    fprintf(fp, "graph TD\n");

    // Reset visited flags for all nodes
    CFGNode *current_reset = cfg_nodes_head;
    while (current_reset != NULL)
    {
        current_reset->visited = 0;
        current_reset = current_reset->list_next;
    }

    // Find all entry nodes (Start nodes) from the global list
    CFGNode *entry_nodes[100]; // Array to store multiple entry points
    int entry_count = 0;

    CFGNode *current_find_entry = cfg_nodes_head;
    while (current_find_entry != NULL && entry_count < 100)
    {
        if (current_find_entry->type == CFG_NODE_ENTRY)
        {
            entry_nodes[entry_count++] = current_find_entry;
        }
        current_find_entry = current_find_entry->list_next;
    }

    // Use a queue for BFS to ensure proper ordering in Mermaid
    CFGNode *queue[1000]; // Max possible nodes
    int head = 0, tail = 0;

    // Add all entry nodes to queue
    for (int i = 0; i < entry_count; i++)
    {
        if (entry_nodes[i] && !entry_nodes[i]->visited)
        {
            queue[tail++] = entry_nodes[i];
            entry_nodes[i]->visited = 1;
        }
    }

    // First pass: define all nodes with their shapes and styles
    while (head < tail)
    {
        CFGNode *current = queue[head++];

        // Define node based on type for Flowgorithm-like shapes
        char *node_shape_start = "["; // Default for statement
        char *node_shape_end = "]";
        char *node_class = "process"; // Default class

        // Escape special characters for Mermaid
        char *node_label_escaped = current->label ? strdup(current->label) : strdup("");
        char *p = node_label_escaped;
        while (*p)
        {
            if (*p == '"' || *p == '\\')
            {
                memmove(p + 1, p, strlen(p) + 1);
                *p = '\\';
                p++;
            }
            p++;
        }

        switch (current->type)
        {
        case CFG_NODE_ENTRY:
            node_shape_start = "([";
            node_shape_end = "])";
            node_class = "startEnd";
            break;
        case CFG_NODE_EXIT:
            node_shape_start = "([";
            node_shape_end = "])";
            node_class = "startEnd";
            break;
        case CFG_NODE_CONDITION:
            node_shape_start = "{";
            node_shape_end = "}";
            node_class = "decision";
            break;
        case CFG_NODE_JOIN:
            node_shape_start = "[";
            node_shape_end = "]";
            node_class = "join";
            break;
        case CFG_NODE_RETURN:
            node_shape_start = "[";
            node_shape_end = "]";
            node_class = "return";
            break;
        case CFG_NODE_FUNCTION_CALL:
            node_shape_start = "[[";
            node_shape_end = "]]";
            node_class = "function";
            break;
        case CFG_NODE_STATEMENT:
        default:
            node_shape_start = "[";
            node_shape_end = "]";
            node_class = "process";
            break;
        }

        // Define node without inline style
        if (current->type == CFG_NODE_JOIN && strlen(node_label_escaped) == 0)
        {
            fprintf(fp, "    %d%s %s\n", current->id, node_shape_start, node_shape_end);
        }
        else
        {
            fprintf(fp, "    %d%s%s%s\n", current->id, node_shape_start, node_label_escaped, node_shape_end);
        }

        free(node_label_escaped);

        // Add edges to queue for processing
        CFGEdge *current_edge = current->edges;
        while (current_edge != NULL)
        {
            if (!current_edge->to->visited)
            {
                current_edge->to->visited = 1;
                queue[tail++] = current_edge->to;
            }
            current_edge = current_edge->next;
        }
    }

    // Reset visited flags for edge processing
    current_reset = cfg_nodes_head;
    while (current_reset != NULL)
    {
        current_reset->visited = 0;
        current_reset = current_reset->list_next;
    }

    // Second pass: define all edges
    head = 0;
    tail = 0;

    // Add all entry nodes to queue again
    for (int i = 0; i < entry_count; i++)
    {
        if (entry_nodes[i] && !entry_nodes[i]->visited)
        {
            queue[tail++] = entry_nodes[i];
            entry_nodes[i]->visited = 1;
        }
    }

    while (head < tail)
    {
        CFGNode *current = queue[head++];

        CFGEdge *current_edge = current->edges;
        while (current_edge != NULL)
        {
            fprintf(fp, "    %d ", current->id);
            
            // Se o rótulo está vazio, usar linha pontilhada
            if (current_edge->label && strlen(current_edge->label) == 0)
            {
                fprintf(fp, "-.->"); // Linha pontilhada
            }
            else
            {
                fprintf(fp, "-->"); // Linha normal
            }
            
            if (current_edge->label && strlen(current_edge->label) > 0)
            {
                fprintf(fp, "|%s|", current_edge->label);
            }
            fprintf(fp, " %d\n", current_edge->to->id);

            if (!current_edge->to->visited)
            {
                current_edge->to->visited = 1;
                queue[tail++] = current_edge->to;
            }
            current_edge = current_edge->next;
        }
    }

    // Add style definitions for Flowgorithm-like appearance
    fprintf(fp, "\n");
    fprintf(fp, "    classDef startEnd fill:#90EE90,stroke:#333,stroke-width:2px,color:#000\n");
    fprintf(fp, "    classDef decision fill:#FFD700,stroke:#333,stroke-width:2px,color:#000\n");
    fprintf(fp, "    classDef process fill:#87CEEB,stroke:#333,stroke-width:2px,color:#000\n");
    fprintf(fp, "    classDef function fill:#DDA0DD,stroke:#333,stroke-width:2px,color:#000\n");
    fprintf(fp, "    classDef return fill:#FFA07A,stroke:#333,stroke-width:2px,color:#000\n");
    fprintf(fp, "    classDef join fill:#D3D3D3,stroke:#333,stroke-width:2px,color:#000\n");

    // Reset visited flags for style application
    current_reset = cfg_nodes_head;
    while (current_reset != NULL)
    {
        current_reset->visited = 0;
        current_reset = current_reset->list_next;
    }

    // Third pass: apply styles to nodes
    head = 0;
    tail = 0;

    // Add all entry nodes to queue again
    for (int i = 0; i < entry_count; i++)
    {
        if (entry_nodes[i] && !entry_nodes[i]->visited)
        {
            queue[tail++] = entry_nodes[i];
            entry_nodes[i]->visited = 1;
        }
    }

    while (head < tail)
    {
        CFGNode *current = queue[head++];

        // Apply class based on node type
        char *node_class = "process"; // Default class
        switch (current->type)
        {
        case CFG_NODE_ENTRY:
        case CFG_NODE_EXIT:
            node_class = "startEnd";
            break;
        case CFG_NODE_CONDITION:
            node_class = "decision";
            break;
        case CFG_NODE_JOIN:
            node_class = "join";
            break;
        case CFG_NODE_RETURN:
            node_class = "return";
            break;
        case CFG_NODE_FUNCTION_CALL:
            node_class = "function";
            break;
        case CFG_NODE_STATEMENT:
        default:
            node_class = "process";
            break;
        }

        fprintf(fp, "    class %d %s\n", current->id, node_class);

        // Add edges to queue for processing
        CFGEdge *current_edge = current->edges;
        while (current_edge != NULL)
        {
            if (!current_edge->to->visited)
            {
                current_edge->to->visited = 1;
                queue[tail++] = current_edge->to;
            }
            current_edge = current_edge->next;
        }
    }

    fclose(fp);
}

// Helper function to build CFG and then generate Mermaid
void build_and_generate_cfg_mermaid(AST *root_ast)
{
    liberarCFG();          // Clear any previous CFG
    cfg_node_counter = 0;  // Reset counter
    cfg_nodes_head = NULL; // Reset head

    // Build the CFG - use the new function for program-level processing
    CFGFragment main_cfg = build_cfg_for_program(root_ast);

    // Generate Mermaid from the built CFG
    cfg_to_mermaid(root_ast);
}

// Função auxiliar para avaliar expressões simples e incluir valores conhecidos
char *ast_node_to_string_with_values(AST *node)
{
    if (node == NULL)
    {
        return strdup("NULL");
    }

    char buffer[256];

    switch (node->tipo)
    {
    case AST_LITERAL_INT:
        snprintf(buffer, sizeof(buffer), "%d", node->valor_int);
        break;
    case AST_LITERAL_FLOAT:
        snprintf(buffer, sizeof(buffer), "%.2f", node->valor_float);
        break;
    case AST_LITERAL_STRING:
        snprintf(buffer, sizeof(buffer), "\"%s\"", node->valor_str ? node->valor_str : "");
        break;
    case AST_LITERAL_CHAR:
        snprintf(buffer, sizeof(buffer), "\'%c\'", node->valor_char);
        break;
    case AST_LITERAL_HEX:
        snprintf(buffer, sizeof(buffer), "%s", node->valor_str ? node->valor_str : "");
        break;
    case AST_VAR:
        snprintf(buffer, sizeof(buffer), "%s", node->valor_str ? node->valor_str : "UNKNOWN_VAR");
        break;
    case AST_BINARY_OP:
    {
        char *left_str = ast_node_to_string_with_values(node->filho1);
        char *right_str = ast_node_to_string_with_values(node->filho2);
        char *op = node->valor_str ? node->valor_str : "OP";

        // Tentar avaliar operações simples com literais
        if (node->filho1 && node->filho2 && 
            node->filho1->tipo == AST_LITERAL_INT && node->filho2->tipo == AST_LITERAL_INT)
        {
            int left_val = node->filho1->valor_int;
            int right_val = node->filho2->valor_int;
            int result = 0;
            int can_evaluate = 1;

            if (strcmp(op, "+") == 0) result = left_val + right_val;
            else if (strcmp(op, "-") == 0) result = left_val - right_val;
            else if (strcmp(op, "*") == 0) result = left_val * right_val;
            else if (strcmp(op, "/") == 0 && right_val != 0) result = left_val / right_val;
            else if (strcmp(op, "%") == 0 && right_val != 0) result = left_val % right_val;
            else can_evaluate = 0;

            if (can_evaluate && strcmp(op, "/") != 0 && strcmp(op, "%") != 0)
            {
                snprintf(buffer, sizeof(buffer), "%d", result);
            }
            else if (can_evaluate)
            {
                snprintf(buffer, sizeof(buffer), "%d", result);
            }
            else
            {
                snprintf(buffer, sizeof(buffer), "%s %s %s", left_str, op, right_str);
            }
        }
        else
        {
            // Para operadores de comparação, mostrar de forma mais clara
            if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
                strcmp(op, ">") == 0 || strcmp(op, "<") == 0 ||
                strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0 ||
                strcmp(op, "&&") == 0 || strcmp(op, "||") == 0)
            {
                snprintf(buffer, sizeof(buffer), "%s %s %s", left_str, op, right_str);
            }
            else
            {
                snprintf(buffer, sizeof(buffer), "%s %s %s", left_str, op, right_str);
            }
        }
        free(left_str);
        free(right_str);
        break;
    }
    case AST_ASSIGN:
    {
        char *var_str = ast_node_to_string_with_values(node->filho1);
        char *expr_str = ast_node_to_string_with_values(node->filho2);
        
        // Se a expressão é um literal simples, mostrar o valor
        if (node->filho2 && node->filho2->tipo == AST_LITERAL_INT)
        {
            snprintf(buffer, sizeof(buffer), "%s = %d", var_str, node->filho2->valor_int);
        }
        else if (node->filho2 && node->filho2->tipo == AST_LITERAL_FLOAT)
        {
            snprintf(buffer, sizeof(buffer), "%s = %.2f", var_str, node->filho2->valor_float);
        }
        else if (node->filho2 && node->filho2->tipo == AST_LITERAL_CHAR)
        {
            snprintf(buffer, sizeof(buffer), "%s = '%c'", var_str, node->filho2->valor_char);
        }
        else
        {
            snprintf(buffer, sizeof(buffer), "%s = %s", var_str, expr_str);
        }
        free(var_str);
        free(expr_str);
        break;
    }
    case AST_VAR_DECL:
    {
        char *type_str = ast_node_to_string_with_values(node->filho1);
        
        // Se há inicialização, incluir o valor
        if (node->filho2)
        {
            char *init_str = ast_node_to_string_with_values(node->filho2);
            if (node->filho2->tipo == AST_LITERAL_INT)
            {
                snprintf(buffer, sizeof(buffer), "VAR_DECL: %s %s = %d", type_str, 
                        node->valor_str ? node->valor_str : "UNKNOWN", node->filho2->valor_int);
            }
            else if (node->filho2->tipo == AST_LITERAL_FLOAT)
            {
                snprintf(buffer, sizeof(buffer), "VAR_DECL: %s %s = %.2f", type_str, 
                        node->valor_str ? node->valor_str : "UNKNOWN", node->filho2->valor_float);
            }
            else
            {
                snprintf(buffer, sizeof(buffer), "VAR_DECL: %s %s = %s", type_str, 
                        node->valor_str ? node->valor_str : "UNKNOWN", init_str);
            }
            free(init_str);
        }
        else
        {
            snprintf(buffer, sizeof(buffer), "VAR_DECL: %s %s", type_str, 
                    node->valor_str ? node->valor_str : "UNKNOWN");
        }
        free(type_str);
        break;
    }
    default:
        // Para outros tipos, usar a função original
        return ast_node_to_string(node);
    }

    return strdup(buffer);
}

