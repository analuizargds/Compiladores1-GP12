#ifndef AST_H
#define AST_H

typedef enum
{
    AST_LITERAL_INT,
    AST_LITERAL_FLOAT,
    AST_LITERAL_STRING,
    AST_LITERAL_CHAR,
    AST_LITERAL_HEX,

    AST_VAR,
    AST_BINARY_OP,
    AST_UNARY_OP,

    AST_ASSIGN,
    AST_PLUS_ASSIGN,
    AST_MINUS_ASSIGN,
    AST_MULT_ASSIGN,
    AST_DIV_ASSIGN,

    AST_IF,
    AST_IF_ELSE,
    AST_WHILE,
    AST_FOR,
    AST_DO_WHILE,
    AST_SWITCH,
    AST_RETURN,
    AST_BREAK,
    AST_CONTINUE,

    AST_VAR_DECL,
    AST_FUNC_DECL,
    AST_PARAM,
    AST_TYPE,
    AST_BLOCK,
    AST_CALL,
    AST_ARG_LIST,

    AST_CASE,
    AST_DEFAULT,

    AST_INIT,
    AST_STRUCT,
    AST_UNION,
    AST_ENUM,
    AST_TYPEDEF,
    AST_MEMBER_ACCESS,

    AST_EMPTY,
} ASTNodeType;

typedef struct ASTNode AST;
typedef struct ASTNode
{
    ASTNodeType tipo;
    struct ASTNode *filho1;
    struct ASTNode *filho2;
    struct ASTNode *filho3;
    struct ASTNode *filho4;
    struct ASTNode *prox;

    // Valores possíveis
    int valor_int;
    float valor_float;
    char valor_char;
    char *valor_str;
    char *valor_str2; // Para nomes adicionais (ex: nome de tipo personalizado)

    // Informação de linha para mensagens de erro
    int linha;
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
void imprimirAST(ASTNode *no);
void liberarAST(ASTNode *no);

void ast_to_dot(AST *node);
char *ast_node_to_string(AST *node); // New function declaration

// Forward declarations para as estruturas do CFG
typedef struct CFGNode CFGNode;
typedef struct CFGEdge CFGEdge;

// Tipos de nós para o Control Flow Graph (CFG)
typedef enum {
    CFG_NODE_ENTRY,
    CFG_NODE_EXIT,
    CFG_NODE_STATEMENT,
    CFG_NODE_CONDITION,
    CFG_NODE_JOIN,
    CFG_NODE_LOOP_ENTRY,
    CFG_NODE_LOOP_EXIT,
    CFG_NODE_FUNCTION_CALL,
    CFG_NODE_RETURN,
    CFG_NODE_BREAK,
    CFG_NODE_CONTINUE,
    CFG_NODE_BLOCK_ENTRY,
} CFGNodeType;

// Estrutura para um nó do Control Flow Graph (CFG)
typedef struct CFGNode {
    int id; // ID único para o nó DOT
    CFGNodeType type;
    char *label; // Rótulo para o nó (e.g., código, condição)
    CFGEdge *edges; // Lista de arestas de saída
    AST *ast_node_ref; // Referência ao nó da AST que gerou este CFGNode
    struct CFGNode *list_next; // Próximo nó na lista global de todos os nós CFG
} CFGNode;

// Estrutura para uma aresta no CFG
typedef struct CFGEdge {
    CFGNode *to; // Nó de destino
    char *label; // Rótulo da aresta (e.g., "True", "False")
    CFGEdge *next; // Próxima aresta na lista de adjacência
} CFGEdge;

// Estrutura para representar um fragmento do CFG (entrada e saída)
typedef struct {
    CFGNode *entry;
    CFGNode *exit;
} CFGFragment;

// Funções para criar nós do CFG
CFGNode *criarCFGNode(CFGNodeType type, const char *label, AST *ast_node_ref);
void add_cfg_edge(CFGNode *from, CFGNode *to, const char *label);
void liberarCFG(void);
void cfg_to_dot(AST *node);
CFGFragment build_cfg_from_ast(AST *node);

#endif // AST_H


