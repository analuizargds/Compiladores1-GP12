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

    AST_EMPTY,
} ASTNodeType;

typedef struct ASTNode
{
    ASTNodeType tipo;
    char *valor_str;
    int valor_int;
    float valor_float;
    char valor_char;
    struct ASTNode *filho1;
    struct ASTNode *filho2;
    struct ASTNode *filho3;
    struct ASTNode *filho4;
    struct ASTNode *prox;
} ASTNode;

ASTNode *criarNo(ASTNodeType tipo, const char *valor_str);
ASTNode *criarNoInt(int valor);
ASTNode *criarNoFloat(float valor);
ASTNode *criarNoString(const char *str);
ASTNode *criarNoChar(char c);
ASTNode *criarNoHex(const char *str);
ASTNode *criarNoVar(const char *id);
ASTNode *criarNoType(const char *tipo);
ASTNode *criarNoBinOp(char op, ASTNode *esq, ASTNode *dir);
ASTNode *criarNoUnaryOp(char op, ASTNode *expr);
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

ASTNode *concatenarStmt(ASTNode *lista, ASTNode *no);
ASTNode *concatenarParam(ASTNode *lista, ASTNode *no);
ASTNode *concatenarArg(ASTNode *lista, ASTNode *no);

void imprimirAST(ASTNode *no);
void liberarAST(ASTNode *no);

#endif
