#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição dos tipos suportados
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_DOUBLE,
    TYPE_STRUCT,
    TYPE_UNION,
    TYPE_ENUM,
    TYPE_ERROR,  // Tipo para representar erros
    TYPE_UNKNOWN // Tipo desconhecido
} DataType;

// Estrutura para armazenar informações de tipo
typedef struct {
    DataType type;
    char *custom_type_name; // Para struct, union, enum
    int is_array;
    int array_size;
} TypeInfo;

// Estrutura para mensagens de erro
typedef struct {
    char *message;
    int line;
    int column;
} ErrorInfo;

// Funções para análise semântica
// Verificação de tipos em expressões aritméticas
TypeInfo check_arithmetic_expr(ASTNode *node);

// Verificação de tipos em expressões lógicas
TypeInfo check_logical_expr(ASTNode *node);

// Verificação de tipos em atribuições
TypeInfo check_assignment(ASTNode *node);

// Verificação de tipos em comparações
TypeInfo check_comparison(ASTNode *node);

// Função para verificar compatibilidade de tipos
int are_types_compatible(TypeInfo type1, TypeInfo type2);

// Função para verificar se uma conversão implícita é permitida
int is_implicit_conversion_allowed(TypeInfo from_type, TypeInfo to_type);

// Função para gerar mensagens de erro com linha
void semantic_error(const char *format, int line, ...);

// Função para gerar avisos de conversão implícita
void semantic_warning(const char *format, int line, ...);

// Função principal para realizar análise semântica
void perform_semantic_analysis(ASTNode *root);

// Função para obter o nome de um tipo
const char *get_type_name(TypeInfo type);

// Função para converter enum DataType para string
const char *data_type_to_string(DataType type);

#endif // SEMANTIC_H
