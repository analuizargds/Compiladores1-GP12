#ifndef AST_H
#define AST_H

// Definição dos tipos de nós da AST
typedef enum {
    AST_NUM,
    AST_FLOAT,
    AST_CHAR,
    AST_STRING,
    AST_VAR,
    AST_BINOP,
    AST_PREFIX,
    AST_POSTFIX,
    AST_ASSIGN,
    AST_IF,
    AST_WHILE,
    AST_FOR,
    AST_DO_WHILE,
    AST_SWITCH,
    AST_CASE,
    AST_DEFAULT,
    AST_BREAK,
    AST_CONTINUE,
    AST_RETURN,
    AST_FUNC_DECL,
    AST_VAR_DECL,
    AST_TYPE,
    AST_PARAM,
    AST_CALL,
    AST_INIT,
    AST_STRUCT,
    AST_UNION,
    AST_ENUM,
    AST_TYPEDEF,
    AST_MEMBER_ACCESS
} ASTNodeType;

// Estrutura do nó da AST
typedef struct ASTNode {
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
ASTNode *criarNo(ASTNodeType tipo, const char *valor);
ASTNode *criarNoNum(int valor);
ASTNode *criarNoFloat(float valor);
ASTNode *criarNoChar(char valor);
ASTNode *criarNoString(const char *valor);
ASTNode *criarNoVar(const char *nome);
ASTNode *criarNoBinOp(const char *op, ASTNode *esq, ASTNode *dir);
ASTNode *criarNoPrefix(const char *op, ASTNode *expr);
ASTNode *criarNoPostfix(ASTNode *expr, const char *op);
ASTNode *criarNoAssign(const char *var, ASTNode *expr);
ASTNode *criarNoAssign(ASTNode *var, ASTNode *expr);
ASTNode *criarNoIf(ASTNode *cond, ASTNode *then_stmt, ASTNode *else_stmt);
ASTNode *criarNoWhile(ASTNode *cond, ASTNode *body);
ASTNode *criarNoFor(ASTNode *init, ASTNode *cond, ASTNode *incr, ASTNode *body);
ASTNode *criarNoDoWhile(ASTNode *cond, ASTNode *body);
ASTNode *criarNoSwitch(ASTNode *expr, ASTNode *cases);
ASTNode *criarNoCase(ASTNode *expr, ASTNode *stmts);
ASTNode *criarNoBreak();
ASTNode *criarNoContinue();
ASTNode *criarNoReturn(ASTNode *expr);
ASTNode *criarNoFuncDecl(const char *nome, ASTNode *tipo, ASTNode *params, ASTNode *body);
ASTNode *criarNoVarDecl(ASTNode *tipo, ASTNode *vars);
ASTNode *criarNoType(const char *nome);
ASTNode *criarNoParam(const char *nome, ASTNode *tipo);
ASTNode *criarNoChamada(const char *nome, ASTNode *args);
ASTNode *criarNoInit(ASTNode *expr, ASTNode *lista);
ASTNode *criarNoStruct(const char *nome, ASTNode *decls);
ASTNode *criarNoUnion(const char *nome, ASTNode *decls);
ASTNode *criarNoEnum(const char *nome, ASTNode *valores);
ASTNode *criarNoTypedef(ASTNode *tipo, const char *nome);
ASTNode *criarNoMemberAccess(ASTNode *expr, const char *membro);
ASTNode *criarNoIdent(const char *nome);

// Funções para manipular a AST
ASTNode *concatenarStmt(ASTNode *lista, ASTNode *novo);
void liberarAST(ASTNode *no);

#endif // AST_H
