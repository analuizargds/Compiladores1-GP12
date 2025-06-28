/*
 * Arquivo de teste: Expressões válidas (versão simplificada)
 * Este arquivo testa expressões básicas suportadas pelo compilador
 */

// Funções auxiliares
int calcSquare(int n) {
    return n * n;
}

float calcCircleArea(float radius) {
    return 3.14159 * radius * radius;
}

int main() {
    // Declarações de variáveis para teste
    int a = 10;
    int b = 5;
    int c = 2;
    float x = 3.14;
    float y = 2.71;
    char ch = 'A';

    // Expressões aritméticas
    int result1 = a + b;       // Adição
    int result2 = a - b;       // Subtração
    int result3 = a * b;       // Multiplicação
    int result4 = a / b;       // Divisão
    int result5 = a % b;       // Módulo
    int result6 = a + b * c;   // Precedência de operadores
    int result7 = (a + b) * c; // Agrupamento com parênteses

    // Expressões com atribuição simples
    int i = 0;
    int j = 5;
    j = j + 2; // j = j + 2
    j = j - 1; // j = j - 1
    j = j * 3; // j = j * 3
    j = j / 2; // j = j / 2
    j = j % 3; // j = j % 3

    // Expressões relacionais
    int isEqual = (a == b);        // Igualdade
    int isNotEqual = (a != b);     // Desigualdade
    int isGreater = (a > b);       // Maior que
    int isLess = (a < b);          // Menor que
    int isGreaterEqual = (a >= b); // Maior ou igual
    int isLessEqual = (a <= b);    // Menor ou igual

    // Expressões lógicas
    int logicalAnd = (a > b) && (b > c); // AND lógico
    int logicalOr = (a > b) || (b < c);  // OR lógico
    int logicalNot = !(a == b);          // NOT lógico

    // Expressões com operador ternário
    int max = (a > b) ? a : b; // Operador ternário

    // Expressões com chamadas de função
    int square = calcSquare(a);
    float area = calcCircleArea(x);

    return 0;
}

