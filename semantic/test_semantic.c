#include "semantic.h"

// Função para testar a análise semântica
void test_semantic_analysis() {
    // Inicializar o sistema de análise semântica
    init_semantic_analysis();
    
    printf("=== Teste de Análise Semântica ===\n\n");
    
    // Teste 1: Verificação de tipos em expressões aritméticas
    printf("Teste 1: Verificação de tipos em expressões aritméticas\n");
    printf("- Divisão por zero: ");
    ASTNode num_zero = {AST_NUM, NULL, NULL, NULL, NULL, NULL, 0, 0.0, 0, NULL, NULL, 10};
    num_zero.valor_int = 0;
    
    ASTNode num_five = {AST_NUM, NULL, NULL, NULL, NULL, NULL, 5, 0.0, 0, NULL, NULL, 10};
    num_five.valor_int = 5;
    
    ASTNode div_op = {AST_BINOP, &num_five, &num_zero, NULL, NULL, NULL, 0, 0.0, 0, "/", NULL, 10};
    
    TypeInfo result = check_arithmetic_expr(&div_op, 10);
    printf("Tipo resultante: %s\n", data_type_to_string(result.type));
    
    // Teste 2: Verificação de tipos em expressões lógicas
    printf("\nTeste 2: Verificação de tipos em expressões lógicas\n");
    
    ASTNode var_x = {AST_VAR, NULL, NULL, NULL, NULL, NULL, 0, 0.0, 0, "x", NULL, 15};
    ASTNode var_y = {AST_VAR, NULL, NULL, NULL, NULL, NULL, 0, 0.0, 0, "y", NULL, 15};
    
    ASTNode and_op = {AST_BINOP, &var_x, &var_y, NULL, NULL, NULL, 0, 0.0, 0, "&&", NULL, 15};
    
    printf("- Operação lógica AND: ");
    result = check_logical_expr(&and_op, 15);
    printf("Tipo resultante: %s\n", data_type_to_string(result.type));
    
    // Teste 3: Verificação de tipos em atribuições
    printf("\nTeste 3: Verificação de tipos em atribuições\n");
    
    ASTNode float_val = {AST_FLOAT, NULL, NULL, NULL, NULL, NULL, 0, 3.14, 0, NULL, NULL, 20};
    ASTNode assign_op = {AST_ASSIGN, &var_x, &float_val, NULL, NULL, NULL, 0, 0.0, 0, NULL, NULL, 20};
    
    printf("- Atribuição de float para int: ");
    result = check_assignment(&assign_op, 20);
    printf("Tipo resultante: %s\n", data_type_to_string(result.type));
    
    // Teste 4: Verificação de tipos em comparações
    printf("\nTeste 4: Verificação de tipos em comparações\n");
    
    ASTNode char_val = {AST_CHAR, NULL, NULL, NULL, NULL, NULL, 0, 0.0, 'A', NULL, NULL, 25};
    
    ASTNode gt_op = {AST_BINOP, &var_x, &char_val, NULL, NULL, NULL, 0, 0.0, 0, ">", NULL, 25};
    
    printf("- Comparação de int com char: ");
    result = check_comparison(&gt_op, 25);
    printf("Tipo resultante: %s\n", data_type_to_string(result.type));
    
    // Limpar recursos
    cleanup_semantic_analysis();
    
    printf("\n=== Fim dos Testes ===\n");
}

int main() {
    test_semantic_analysis();
    return 0;
}
