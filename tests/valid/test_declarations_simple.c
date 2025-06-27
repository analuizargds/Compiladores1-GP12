/*
 * Arquivo de teste: Declarações válidas (versão simplificada)
 * Este arquivo testa declarações básicas suportadas pelo compilador
 */

// Declarações de variáveis simples
int a;
float b;
char c;
double d;

// Declarações com inicialização
int x = 10;
float y = 3.14;
char z = 'A';
double w = 2.71828;

// Declarações múltiplas
int i, j, k;
float m = 1.0, n = 2.0;

// Declaração de funções
int soma(int a, int b) {
    return a + b;
}

float media(float a, float b) {
    return (a + b) / 2;
}

// Função principal
int main() {
    int resultado = 0;
    float valor = 0.0;
    
    // Atribuições
    a = 5;
    b = 2.5;
    c = 'X';
    
    // Chamadas de função
    resultado = soma(a, x);
    valor = media(b, y);
    
    // Operações aritméticas
    resultado = a + x * 2;
    valor = b / 2 + y;
    
    // Estruturas de controle
    if (resultado > 20) {
        resultado = 20;
    } else {
        resultado = resultado + 1;
    }
    
    // Loop for simples
    for (i = 0; i < 10; i = i + 1) {
        k = i * 2;
    }
    
    // Loop while
    j = 0;
    while (j < 5) {
        j = j + 1;
    }
    
    return 0;
}

