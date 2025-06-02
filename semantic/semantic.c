#include "semantic.h"
#include <stdarg.h>

// Variável global para armazenar erros
ErrorInfo *errors = NULL;
int error_count = 0;
int max_errors = 100;

// Função para inicializar o sistema de análise semântica
void init_semantic_analysis() {
    errors = (ErrorInfo *)malloc(max_errors * sizeof(ErrorInfo));
    error_count = 0;
}

// Função para liberar recursos da análise semântica
void cleanup_semantic_analysis() {
    if (errors) {
        for (int i = 0; i < error_count; i++) {
            if (errors[i].message) {
                free(errors[i].message);
            }
        }
        free(errors);
        errors = NULL;
    }
    error_count = 0;
}

// Função para registrar um erro semântico
void semantic_error(const char *format, int line, ...) {
    if (error_count >= max_errors) {
        return; // Limite de erros atingido
    }
    
    va_list args;
    va_start(args, line);
    
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    
    errors[error_count].message = strdup(buffer);
    errors[error_count].line = line;
    errors[error_count].column = 0; // Coluna não implementada ainda
    
    error_count++;
    
    // Imprimir o erro no console
    fprintf(stderr, "Erro na linha %d: %s\n", line, buffer);
    
    va_end(args);
}

// Função para registrar um aviso semântico
void semantic_warning(const char *format, int line, ...) {
    va_list args;
    va_start(args, line);
    
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    
    // Imprimir o aviso no console
    fprintf(stderr, "Aviso na linha %d: %s\n", line, buffer);
    
    va_end(args);
}

// Função para converter enum DataType para string
const char *data_type_to_string(DataType type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_CHAR: return "char";
        case TYPE_VOID: return "void";
        case TYPE_DOUBLE: return "double";
        case TYPE_STRUCT: return "struct";
        case TYPE_UNION: return "union";
        case TYPE_ENUM: return "enum";
        case TYPE_ERROR: return "error";
        case TYPE_UNKNOWN: return "unknown";
        default: return "undefined";
    }
}

// Função para obter o nome de um tipo
const char *get_type_name(TypeInfo type) {
    if (type.custom_type_name) {
        return type.custom_type_name;
    }
    return data_type_to_string(type.type);
}

// Função para verificar se uma conversão implícita é permitida
int is_implicit_conversion_allowed(TypeInfo from_type, TypeInfo to_type) {
    // Se os tipos são iguais, não há conversão
    if (from_type.type == to_type.type) {
        return 1;
    }
    
    // Conversões permitidas com aviso
    switch (to_type.type) {
        case TYPE_INT:
            // float para int (perda de precisão)
            if (from_type.type == TYPE_FLOAT || from_type.type == TYPE_DOUBLE) {
                return 2; // Permitido com aviso
            }
            // char para int (ok)
            if (from_type.type == TYPE_CHAR) {
                return 1; // Permitido sem aviso
            }
            break;
            
        case TYPE_FLOAT:
            // int para float (ok)
            if (from_type.type == TYPE_INT) {
                return 1; // Permitido sem aviso
            }
            // double para float (perda de precisão)
            if (from_type.type == TYPE_DOUBLE) {
                return 2; // Permitido com aviso
            }
            break;
            
        case TYPE_DOUBLE:
            // int ou float para double (ok)
            if (from_type.type == TYPE_INT || from_type.type == TYPE_FLOAT) {
                return 1; // Permitido sem aviso
            }
            break;
            
        case TYPE_CHAR:
            // int para char (possível truncamento)
            if (from_type.type == TYPE_INT) {
                return 2; // Permitido com aviso
            }
            break;
            
        default:
            break;
    }
    
    // Conversão não permitida
    return 0;
}

// Função para verificar compatibilidade de tipos
int are_types_compatible(TypeInfo type1, TypeInfo type2) {
    // Se os tipos são iguais, são compatíveis
    if (type1.type == type2.type) {
        // Para tipos personalizados, verificar o nome
        if ((type1.type == TYPE_STRUCT || type1.type == TYPE_UNION || type1.type == TYPE_ENUM) &&
            type1.custom_type_name && type2.custom_type_name) {
            return strcmp(type1.custom_type_name, type2.custom_type_name) == 0;
        }
        return 1;
    }
    
    // Verificar se a conversão implícita é permitida
    return is_implicit_conversion_allowed(type1, type2) > 0;
}

// Função para verificar tipos em expressões aritméticas
TypeInfo check_arithmetic_expr(ASTNode *node, int line) {
    TypeInfo result = {TYPE_ERROR, NULL, 0, 0};
    
    if (!node) {
        return result;
    }
    
    // Verificar o tipo de nó
    switch (node->tipo) {
        case AST_LITERAL_INT:
            result.type = TYPE_INT;
            break;
            
        case AST_LITERAL_FLOAT:
            result.type = TYPE_FLOAT;
            break;
            
        case AST_LITERAL_CHAR:
            result.type = TYPE_CHAR;
            break;
            
        case AST_VAR:
            // Aqui precisaríamos consultar a tabela de símbolos
            // Por enquanto, assumimos que variáveis são int
            result.type = TYPE_INT;
            break;
            
        case AST_BINARY_OP: {
            // Operações binárias: +, -, *, /, %
            TypeInfo left = check_arithmetic_expr(node->filho1, line);
            TypeInfo right = check_arithmetic_expr(node->filho2, line);
            
            // Verificar se ambos os operandos são tipos numéricos
            if (left.type == TYPE_ERROR || right.type == TYPE_ERROR) {
                result.type = TYPE_ERROR;
                return result;
            }
            
            if (left.type == TYPE_VOID || right.type == TYPE_VOID) {
                semantic_error("Operação aritmética não pode ser aplicada ao tipo void", line);
                result.type = TYPE_ERROR;
                return result;
            }
            
            // Verificar operação de módulo (%) - apenas para inteiros
            if (strcmp(node->valor_str, "%") == 0) {
                if (left.type != TYPE_INT || right.type != TYPE_INT) {
                    semantic_error("Operador '%%' só pode ser aplicado a operandos inteiros", line);
                    result.type = TYPE_ERROR;
                    return result;
                }
                result.type = TYPE_INT;
                return result;
            }
            
            // Para outras operações aritméticas
            if (left.type == TYPE_DOUBLE || right.type == TYPE_DOUBLE) {
                result.type = TYPE_DOUBLE;
            } else if (left.type == TYPE_FLOAT || right.type == TYPE_FLOAT) {
                result.type = TYPE_FLOAT;
            } else {
                result.type = TYPE_INT;
            }
            
            // Verificar divisão por zero para constantes
            if (strcmp(node->valor_str, "/") == 0 && node->filho2->tipo == AST_LITERAL_INT && 
                node->filho2->valor_int == 0) {
                semantic_error("Divisão por zero", line);
            }
            
            break;
        }
        
        case AST_UNARY_OP: {
            // Operadores unários: +, -, ++, --
            TypeInfo operand = check_arithmetic_expr(node->filho1, line);
            
            if (operand.type == TYPE_ERROR) {
                result.type = TYPE_ERROR;
                return result;
            }
            
            if (operand.type == TYPE_VOID) {
                semantic_error("Operador unário não pode ser aplicado ao tipo void", line);
                result.type = TYPE_ERROR;
                return result;
            }
            
            // Operadores ++ e -- só podem ser aplicados a variáveis
            if ((strcmp(node->valor_str, "++") == 0 || strcmp(node->valor_str, "--") == 0) && 
                node->filho1->tipo != AST_VAR) {
                semantic_error("Operadores de incremento/decremento só podem ser aplicados a variáveis", line);
                result.type = TYPE_ERROR;
                return result;
            }
            
            result.type = operand.type;
            break;
        }
        
        // Adicionando casos para outros tipos de nós que podem aparecer em expressões aritméticas
        case AST_CALL:
            // Assumindo que chamadas de função retornam int por enquanto
            // Em uma implementação completa, consultaríamos a tabela de símbolos
            result.type = TYPE_INT;
            break;
            
        case AST_MEMBER_ACCESS:
            // Assumindo que acesso a membros retorna int por enquanto
            result.type = TYPE_INT;
            break;
            
        default:
            semantic_error("Expressão aritmética inválida", line);
            result.type = TYPE_ERROR;
    }
    
    return result;
}

// Função para verificar tipos em expressões lógicas
TypeInfo check_logical_expr(ASTNode *node, int line) {
    TypeInfo result = {TYPE_ERROR, NULL, 0, 0};
    
    if (!node) {
        return result;
    }
    
    // Verificar o tipo de nó
    switch (node->tipo) {
        case AST_BINARY_OP: {
            // Operações lógicas: &&, ||
            if (strcmp(node->valor_str, "&&") == 0 || strcmp(node->valor_str, "||") == 0) {
                TypeInfo left = check_logical_expr(node->filho1, line);
                TypeInfo right = check_logical_expr(node->filho2, line);
                
                // Verificar se ambos os operandos são válidos
                if (left.type == TYPE_ERROR || right.type == TYPE_ERROR) {
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                // Em C, qualquer valor não-zero é considerado verdadeiro
                // Então, qualquer tipo numérico pode ser usado em expressões lógicas
                if (left.type == TYPE_VOID || right.type == TYPE_VOID) {
                    semantic_error("Operação lógica não pode ser aplicada ao tipo void", line);
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                // O resultado de uma operação lógica é sempre int (0 ou 1)
                result.type = TYPE_INT;
            }
            // Operações de comparação: ==, !=, <, >, <=, >=
            else if (strcmp(node->valor_str, "==") == 0 || strcmp(node->valor_str, "!=") == 0 ||
                     strcmp(node->valor_str, "<") == 0 || strcmp(node->valor_str, ">") == 0 ||
                     strcmp(node->valor_str, "<=") == 0 || strcmp(node->valor_str, ">=") == 0) {
                TypeInfo left = check_arithmetic_expr(node->filho1, line);
                TypeInfo right = check_arithmetic_expr(node->filho2, line);
                
                // Verificar se ambos os operandos são válidos
                if (left.type == TYPE_ERROR || right.type == TYPE_ERROR) {
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                // Verificar compatibilidade de tipos
                if (!are_types_compatible(left, right)) {
                    semantic_error("Tipos incompatíveis em operação de comparação: %s e %s", 
                                  line, get_type_name(left), get_type_name(right));
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                // O resultado de uma operação de comparação é sempre int (0 ou 1)
                result.type = TYPE_INT;
            }
            else {
                // Outras operações binárias - delegar para verificação aritmética
                return check_arithmetic_expr(node, line);
            }
            break;
        }
        
        case AST_UNARY_OP: {
            // Operador lógico unário: !
            if (strcmp(node->valor_str, "!") == 0) {
                TypeInfo operand = check_logical_expr(node->filho1, line);
                
                if (operand.type == TYPE_ERROR) {
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                if (operand.type == TYPE_VOID) {
                    semantic_error("Operador lógico '!' não pode ser aplicado ao tipo void", line);
                    result.type = TYPE_ERROR;
                    return result;
                }
                
                // O resultado de uma operação lógica NOT é sempre int (0 ou 1)
                result.type = TYPE_INT;
            }
            else {
                // Outros operadores unários - delegar para verificação aritmética
                return check_arithmetic_expr(node, line);
            }
            break;
        }
        
        default:
            // Para outros tipos de nós, verificar como expressão aritmética
            return check_arithmetic_expr(node, line);
    }
    
    return result;
}

// Função para verificar tipos em atribuições
TypeInfo check_assignment(ASTNode *node, int line) {
    TypeInfo result = {TYPE_ERROR, NULL, 0, 0};
    
    if (!node) {
        return result;
    }
    
    // Verificar se é um nó de atribuição
    if (node->tipo == AST_ASSIGN) {
        // Verificar o lado esquerdo (deve ser uma variável)
        if (node->filho1->tipo != AST_VAR) {
            semantic_error("Lado esquerdo da atribuição deve ser uma variável", line);
            return result;
        }
        
        // Obter o tipo da variável (lado esquerdo)
        TypeInfo var_type = {TYPE_INT, NULL, 0, 0}; // Assumindo int por enquanto
        // Na implementação real, consultaríamos a tabela de símbolos
        
        // Verificar o lado direito (expressão)
        TypeInfo expr_type = check_arithmetic_expr(node->filho2, line);
        
        if (expr_type.type == TYPE_ERROR) {
            return result;
        }
        
        // Verificar compatibilidade de tipos
        int conversion = is_implicit_conversion_allowed(expr_type, var_type);
        if (conversion == 0) {
            semantic_error("Tipos incompatíveis em atribuição: não é possível converter %s para %s", 
                          line, get_type_name(expr_type), get_type_name(var_type));
            return result;
        } else if (conversion == 2) {
            // Conversão permitida, mas com aviso
            semantic_warning("Conversão implícita de %s para %s pode causar perda de dados", 
                            line, get_type_name(expr_type), get_type_name(var_type));
        }
        
        // A atribuição retorna o tipo da variável
        result = var_type;
    }
    // Verificar atribuições compostas: +=, -=, *=, /=
    else if (node->tipo == AST_BINARY_OP && 
             (strcmp(node->valor_str, "+=") == 0 || strcmp(node->valor_str, "-=") == 0 ||
              strcmp(node->valor_str, "*=") == 0 || strcmp(node->valor_str, "/=") == 0)) {
        
        // Verificar o lado esquerdo (deve ser uma variável)
        if (node->filho1->tipo != AST_VAR) {
            semantic_error("Lado esquerdo da atribuição composta deve ser uma variável", line);
            return result;
        }
        
        // Obter o tipo da variável (lado esquerdo)
        TypeInfo var_type = {TYPE_INT, NULL, 0, 0}; // Assumindo int por enquanto
        
        // Verificar o lado direito (expressão)
        TypeInfo expr_type = check_arithmetic_expr(node->filho2, line);
        
        if (expr_type.type == TYPE_ERROR) {
            return result;
        }
        
        // Verificar compatibilidade de tipos para a operação
        if (var_type.type == TYPE_VOID || expr_type.type == TYPE_VOID) {
            semantic_error("Operação aritmética não pode ser aplicada ao tipo void", line);
            return result;
        }
        
        // Verificar operação de módulo (%) - apenas para inteiros
        if (strcmp(node->valor_str, "%=") == 0 && 
            (var_type.type != TYPE_INT || expr_type.type != TYPE_INT)) {
            semantic_error("Operador '%%=' só pode ser aplicado a operandos inteiros", line);
            return result;
        }
        
        // A atribuição composta retorna o tipo da variável
        result = var_type;
    }
    // Verificar atribuições específicas: PLUS_ASSIGN, MINUS_ASSIGN, etc.
    else if (node->tipo == AST_PLUS_ASSIGN || node->tipo == AST_MINUS_ASSIGN ||
             node->tipo == AST_MULT_ASSIGN || node->tipo == AST_DIV_ASSIGN) {
        
        // Verificar o lado esquerdo (deve ser uma variável)
        if (node->filho1->tipo != AST_VAR) {
            semantic_error("Lado esquerdo da atribuição composta deve ser uma variável", line);
            return result;
        }
        
        // Obter o tipo da variável (lado esquerdo)
        TypeInfo var_type = {TYPE_INT, NULL, 0, 0}; // Assumindo int por enquanto
        
        // Verificar o lado direito (expressão)
        TypeInfo expr_type = check_arithmetic_expr(node->filho2, line);
        
        if (expr_type.type == TYPE_ERROR) {
            return result;
        }
        
        // Verificar compatibilidade de tipos para a operação
        if (var_type.type == TYPE_VOID || expr_type.type == TYPE_VOID) {
            semantic_error("Operação aritmética não pode ser aplicada ao tipo void", line);
            return result;
        }
        
        // A atribuição composta retorna o tipo da variável
        result = var_type;
    }
    else {
        semantic_error("Expressão de atribuição inválida", line);
    }
    
    return result;
}

// Função para verificar declarações de variáveis
void check_var_declaration(ASTNode *node) {
    if (!node || node->tipo != AST_VAR_DECL) {
        return;
    }
    
    // Verificar se o tipo é válido
    ASTNode *type_node = node->filho1;
    if (!type_node || type_node->tipo != AST_TYPE) {
        semantic_error("Tipo inválido na declaração de variável", get_node_line(node));
        return;
    }
    
    // Verificar inicialização, se houver
    if (node->filho2) {
        int line = get_node_line(node);
        
        // Obter o tipo da variável
        TypeInfo var_type = {TYPE_INT, NULL, 0, 0}; // Assumindo int por enquanto
        // Na implementação real, consultaríamos o tipo real baseado em type_node
        
        // Verificar o tipo da expressão de inicialização
        TypeInfo init_type = check_arithmetic_expr(node->filho2, line);
        
        if (init_type.type == TYPE_ERROR) {
            return;
        }
        
        // Verificar compatibilidade de tipos
        int conversion = is_implicit_conversion_allowed(init_type, var_type);
        if (conversion == 0) {
            semantic_error("Tipos incompatíveis na inicialização: não é possível converter %s para %s", 
                          line, get_type_name(init_type), get_type_name(var_type));
        } else if (conversion == 2) {
            // Conversão permitida, mas com aviso
            semantic_warning("Conversão implícita de %s para %s pode causar perda de dados", 
                            line, get_type_name(init_type), get_type_name(var_type));
        }
    }
}

// Função auxiliar para obter a linha de um nó
int get_node_line(ASTNode *node) {
    if (!node) {
        return 0;
    }
    return node->linha;
}

// Função para verificar declarações de funções
void check_func_declaration(ASTNode *node) {
    if (!node || node->tipo != AST_FUNC_DECL) {
        return;
    }
    
    // Verificar se o tipo de retorno é válido
    ASTNode *type_node = node->filho1;
    if (!type_node || type_node->tipo != AST_TYPE) {
        semantic_error("Tipo de retorno inválido na declaração de função", get_node_line(node));
        return;
    }
    
    // Verificar parâmetros
    ASTNode *params = node->filho2;
    while (params) {
        if (params->tipo == AST_PARAM) {
            // Verificar se o tipo do parâmetro é válido
            ASTNode *param_type = params->filho1;
            if (!param_type || param_type->tipo != AST_TYPE) {
                semantic_error("Tipo inválido no parâmetro de função", get_node_line(params));
            }
        }
        params = params->prox;
    }
    
    // Verificar corpo da função
    ASTNode *body = node->filho3;
    if (body) {
        check_statement(body);
    }
}

// Função para verificar statements
void check_statement(ASTNode *node) {
    if (!node) {
        return;
    }
    
    int line = get_node_line(node);
    
    switch (node->tipo) {
        case AST_IF: {
            // Verificar a expressão de condição
            ASTNode *cond = node->filho1;
            TypeInfo cond_type = check_logical_expr(cond, line);
            
            if (cond_type.type == TYPE_VOID) {
                semantic_error("Expressão de condição não pode ser do tipo void", line);
            }
            
            // Verificar os blocos then e else
            check_statement(node->filho2); // then
            if (node->filho3) {
                check_statement(node->filho3); // else
            }
            break;
        }
        
        case AST_IF_ELSE: {
            // Verificar a expressão de condição
            ASTNode *cond = node->filho1;
            TypeInfo cond_type = check_logical_expr(cond, line);
            
            if (cond_type.type == TYPE_VOID) {
                semantic_error("Expressão de condição não pode ser do tipo void", line);
            }
            
            // Verificar os blocos then e else
            check_statement(node->filho2); // then
            check_statement(node->filho3); // else
            break;
        }
        
        case AST_WHILE: {
            // Verificar a expressão de condição
            ASTNode *cond = node->filho1;
            TypeInfo cond_type = check_logical_expr(cond, line);
            
            if (cond_type.type == TYPE_VOID) {
                semantic_error("Expressão de condição não pode ser do tipo void", line);
            }
            
            // Verificar o corpo do loop
            check_statement(node->filho2);
            break;
        }
        
        case AST_FOR: {
            // Verificar a inicialização
            if (node->filho1) {
                if (node->filho1->tipo == AST_VAR_DECL) {
                    check_var_declaration(node->filho1);
                } else {
                    check_assignment(node->filho1, get_node_line(node->filho1));
                }
            }
            
            // Verificar a condição
            if (node->filho2) {
                TypeInfo cond_type = check_logical_expr(node->filho2, get_node_line(node->filho2));
                
                if (cond_type.type == TYPE_VOID) {
                    semantic_error("Expressão de condição não pode ser do tipo void", get_node_line(node->filho2));
                }
            }
            
            // Verificar o incremento
            if (node->filho3) {
                check_assignment(node->filho3, get_node_line(node->filho3));
            }
            
            // Verificar o corpo do loop
            check_statement(node->filho4);
            break;
        }
        
        case AST_DO_WHILE: {
            // Verificar o corpo do loop
            check_statement(node->filho1);
            
            // Verificar a expressão de condição
            ASTNode *cond = node->filho2;
            TypeInfo cond_type = check_logical_expr(cond, get_node_line(cond));
            
            if (cond_type.type == TYPE_VOID) {
                semantic_error("Expressão de condição não pode ser do tipo void", get_node_line(cond));
            }
            break;
        }
        
        case AST_SWITCH: {
            // Verificar a expressão do switch
            ASTNode *expr = node->filho1;
            TypeInfo expr_type = check_arithmetic_expr(expr, line);
            
            if (expr_type.type != TYPE_INT && expr_type.type != TYPE_CHAR) {
                semantic_error("Expressão do switch deve ser do tipo int ou char", line);
            }
            
            // Verificar os casos
            ASTNode *cases = node->filho2;
            while (cases) {
                if (cases->tipo == AST_CASE) {
                    // Verificar a expressão do case
                    ASTNode *case_expr = cases->filho1;
                    TypeInfo case_type = check_arithmetic_expr(case_expr, get_node_line(case_expr));
                    
                    if (!are_types_compatible(case_type, expr_type)) {
                        semantic_error("Tipo incompatível em case: %s não é compatível com %s", 
                                      get_node_line(case_expr), get_type_name(case_type), get_type_name(expr_type));
                    }
                    
                    // Verificar os statements do case
                    check_statement(cases->filho2);
                } else if (cases->tipo == AST_DEFAULT) {
                    // Verificar os statements do default
                    check_statement(cases->filho1);
                }
                cases = cases->prox;
            }
            break;
        }
        
        case AST_RETURN: {
            // Verificar a expressão de retorno, se houver
            if (node->filho1) {
                // Aqui precisaríamos verificar se o tipo de retorno é compatível com o tipo da função
                // Por enquanto, apenas verificamos se a expressão é válida
                check_arithmetic_expr(node->filho1, line);
            }
            break;
        }
        
        case AST_BREAK:
        case AST_CONTINUE:
            // Nada a verificar para break e continue
            break;
        
        case AST_BLOCK: {
            // Verificar cada statement no bloco
            ASTNode *stmt = node->filho1;
            while (stmt) {
                check_statement(stmt);
                stmt = stmt->prox;
            }
            break;
        }
        
        case AST_VAR_DECL:
            check_var_declaration(node);
            break;
        
        case AST_FUNC_DECL:
            check_func_declaration(node);
            break;
        
        case AST_ASSIGN:
        case AST_PLUS_ASSIGN:
        case AST_MINUS_ASSIGN:
        case AST_MULT_ASSIGN:
        case AST_DIV_ASSIGN:
            check_assignment(node, line);
            break;
        
        case AST_CALL: {
            // Verificar a chamada de função
            // Aqui precisaríamos verificar se a função existe e se os argumentos são compatíveis
            // Por enquanto, apenas verificamos se os argumentos são válidos
            ASTNode *args = node->filho1;
            while (args) {
                if (args->tipo == AST_ARG_LIST) {
                    check_arithmetic_expr(args->filho1, get_node_line(args));
                }
                args = args->prox;
            }
            break;
        }
        
        case AST_EMPTY:
            // Nada a verificar para statements vazios
            break;
        
        // Adicionando casos para outros tipos de nós que podem aparecer como statements
        case AST_STRUCT:
        case AST_UNION:
        case AST_ENUM:
        case AST_TYPEDEF:
            // Implementação básica para evitar erros de compilação
            // Em uma implementação completa, verificaríamos a validade desses tipos
            break;
        
        case AST_INIT:
            // Verificar inicializações de arrays ou structs
            // Por enquanto, apenas uma implementação básica
            if (node->filho1) {
                check_arithmetic_expr(node->filho1, line);
            }
            break;
        
        case AST_LITERAL_INT:
        case AST_LITERAL_FLOAT:
        case AST_LITERAL_STRING:
        case AST_LITERAL_CHAR:
        case AST_LITERAL_HEX:
        case AST_VAR:
        case AST_BINARY_OP:
        case AST_UNARY_OP:
        case AST_MEMBER_ACCESS:
        case AST_TYPE:
        case AST_PARAM:
        case AST_CASE:
        case AST_DEFAULT:
            // Estes nós normalmente não aparecem como statements independentes,
            // mas como parte de expressões ou outras construções
            // Não há verificação específica a ser feita aqui
            break;
        
        default:
            semantic_error("Tipo de statement desconhecido", line);
    }
}

// Função principal para realizar a análise semântica
void perform_semantic_analysis(ASTNode *root) {
    // Inicializar o sistema de análise semântica
    init_semantic_analysis();
    
    // Verificar a árvore AST
    check_statement(root);
    
    // Imprimir resumo dos erros
    if (error_count > 0) {
        fprintf(stderr, "\nAnálise semântica concluída com %d erro(s).\n", error_count);
    } else {
        fprintf(stderr, "\nAnálise semântica concluída sem erros.\n");
    }
    
    // Liberar recursos
    cleanup_semantic_analysis();
}
