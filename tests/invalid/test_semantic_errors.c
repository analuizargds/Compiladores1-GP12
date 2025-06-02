/*
 * Arquivo de teste: Erros semânticos
 * Este arquivo contém erros semânticos para testar o compilador
 */

int main() {
    // Erro: Variável não declarada
    a = 10;
    
    // Erro: Tipo incompatível em atribuição
    int b = "string";
    
    // Erro: Operação com tipos incompatíveis
    int c = 5;
    float d = 3.14;
    int result = c * "texto";
    
    // Erro: Chamada de função não declarada
    int e = funcaoInexistente(10);
    
    // Erro: Número incorreto de argumentos
    int soma(int x, int y) {
        return x + y;
    }
    int f = soma(1, 2, 3);
    
    // Erro: Retorno de tipo incompatível
    float calcularMedia() {
        return "média";
    }
    
    // Erro: Redeclaração de variável
    int g = 10;
    float g = 20.5;
    
    // Erro: Divisão por zero (em constante)
    int h = 10 / 0;
    
    // Erro: Uso de array com índice de tipo errado
    int array[10];
    array["índice"] = 5;
    
    // Erro: Condição não booleana em if
    if ("condição") {
        int i = 10;
    }
    
    return 0;
}
