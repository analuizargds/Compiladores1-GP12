#ifndef AST_H
#define AST_H

#include <stdio.h>

// Forward declarations
typedef struct ASTNode AST;
typedef struct CFGNode CFGNode;

// Enum para tipos de nós da AST
typedef enum {
    AST_PROGRAM,
    AST_VAR_DECL,
    AST_FUNC_DECL,
    AST_PARAM,
    AST_BLOCK,
    AST_IF,
    AST_IF_ELSE,
    AST_WHILE,
    AST_DO_WHILE,
    AST_FOR,
    AST_RETURN,
    AST_BREAK,
    AST_CONTINUE,
    AST_ASSIGN,
    AST_PLUS_ASSIGN, // Added
    AST_MINUS_ASSIGN, // Added
    AST_MULT_ASSIGN, // Added
    AST_DIV_ASSIGN, // Added
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_LITERAL_INT,
    AST_LITERAL_FLOAT,
    AST_LITERAL_STRING,
    AST_LITERAL_CHAR,
    AST_LITERAL_HEX,
    AST_VAR,
    AST_TYPE,
    AST_CALL,
    AST_ARG_LIST,
    AST_SWITCH,
    AST_CASE,
    AST_DEFAULT,
    AST_INIT,
    AST_STRUCT,
    AST_UNION,
    AST_ENUM,
    AST_TYPEDEF,
    AST_MEMBER_ACCESS,
    AST_EMPTY,
    AST_LAST_NODE_TYPE // Should always be the last enum member
} ASTNodeType;

// Estrutura para um nó da AST
typedef struct ASTNode {
    ASTNodeType tipo;
    struct ASTNode *filho1, *filho2, *filho3, *filho4;
    struct ASTNode *prox; // Para listas de statements, parâmetros, etc.
    int valor_int;
    float valor_float;
    char valor_char;
    char *valor_str;
    char *valor_str2; // Para casos específicos como UNION
    int linha; // Número da linha no código fonte
} ASTNode;

// Funções para criar nós da AST
ASTNode *criarNo(ASTNodeType tipo, const char *valor_str);
ASTNode *criarNoInt(int valor);
ASTNode *criarNoFloat(float valor);
ASTNode *criarNoString(const char *str);
ASTNode *criarNoChar(char c);
ASTNode *criarNoHex(const char *str);
ASTNode *criarNoVar(const char *id);
ASTNode *criarNoType(const char *tipo);
ASTNode *criarNoBinOp(const char *op, ASTNode *esq, ASTNode *dir);
ASTNode *criarNoUnaryOp(char *op, ASTNode *expr);
ASTNode *criarNoAssign(char op, ASTNode *var, ASTNode *expr);
ASTNode* criarNoTernario(ASTNode* cond, ASTNode* expr_true, ASTNode* expr_false);
ASTNode *criarNoIf(ASTNode *cond, ASTNode *thenBranch, ASTNode *elseBranch);
ASTNode *criarNoWhile(ASTNode *cond, ASTNode *body);
ASTNode *criarNoDoWhile(ASTNode *cond, ASTNode *body);
ASTNode *criarNoFor(ASTNode *init, ASTNode *cond, ASTNode *increment, ASTNode *body);
ASTNode *criarNoReturn(ASTNode *expr);
ASTNode *criarNoBreak(void);
ASTNode *criarNoContinue(void);
ASTNode *criarNoVarDecl(const char *id, ASTNode *tipo);
ASTNode *criarNoFuncDecl(const char *id, ASTNode *tipo, ASTNode *params, ASTNode *body);
ASTNode *criarNoParam(const char *id, ASTNode *tipo);
ASTNode *criarNoBlock(ASTNode *stmtList);
ASTNode *criarNoCall(const char *id, ASTNode *args);
ASTNode *criarNoSwitch(ASTNode *expr, ASTNode *cases);
ASTNode *criarNoCase(ASTNode *expr, ASTNode *stmts);
ASTNode *criarNoInit(ASTNode *expr, ASTNode *lista);
ASTNode *criarNoUnion(const char *tipo, const char *id);
ASTNode *criarNoEnum(const char *id);

// Funções para manipular a AST
ASTNode *concatenarStmt(ASTNode *lista, ASTNode *no);
ASTNode *concatenarParam(ASTNode *lista, ASTNode *no);
ASTNode *concatenarArg(ASTNode *lista, ASTNode *no);
void liberarAST(ASTNode *no);
char *ast_node_to_string(AST *node);
void imprimirAST(ASTNode *no);

// Tipos de nós para o Control Flow Graph (CFG)
typedef enum {
    CFG_NODE_ENTRY,
    CFG_NODE_EXIT,
    CFG_NODE_STATEMENT,
    CFG_NODE_CONDITION,
    CFG_NODE_JOIN,
    CFG_NODE_LOOP_ENTRY,
    CFG_NODE_FUNCTION_CALL,
    CFG_NODE_FUNCTION_ARGS,
    CFG_NODE_RETURN,
    CFG_NODE_LAST_TYPE // Should always be the last enum member
} CFGNodeType;

// Estrutura para uma aresta no CFG
typedef struct CFGEdge {
    CFGNode *to; // Nó de destino
    char *label; // Rótulo da aresta (e.g., "True", "False")
    struct CFGEdge *next; // Próxima aresta na lista de adjacência
} CFGEdge;

// Estrutura para um nó no CFG
typedef struct CFGNode {
    int id;
    CFGNodeType type;
    char *label; // Rótulo para o nó (e.g., código, condição)
    CFGEdge *edges; // Lista de arestas de saída
    AST *ast_node_ref; // Referência ao nó da AST que gerou este CFGNode
    struct CFGNode *list_next; // Próximo nó na lista global de todos os nós CFG
    int visited; // Para travessia do grafo (e.g., BFS/DFS)
} CFGNode;

// Estrutura para representar um fragmento do CFG (entrada e saída)
typedef struct {
    CFGNode *entry;
    CFGNode *exit;
} CFGFragment;

// Funções para o Control Flow Graph (CFG)
CFGNode *criarCFGNode(CFGNodeType type, const char *label, AST *ast_node_ref);
void add_cfg_edge(CFGNode *from, CFGNode *to, const char *label);
void liberarCFG(void);
void cfg_to_mermaid(AST *root_ast);
CFGFragment build_cfg_from_ast_recursive(AST *node, CFGNode *entry_node, CFGNode *exit_node);
void build_and_generate_cfg_mermaid(AST *root);

#endif // AST_H


