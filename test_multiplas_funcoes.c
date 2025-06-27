// Arquivo de teste para verificar processamento de múltiplas funções

int funcao1(int x) {
    if (x > 0) {
        return x + 1;
    } else {
        return x - 1;
    }
}

int funcao2(int a, int b) {
    int resultado = a + b;
    return resultado;
}

void funcao3() {
    int i;
    for (i = 0; i < 5; i++) {
        // loop simples
    }
}

int main() {
    int x = 10;
    int y = 5;
    int resultado;
    
    resultado = funcao1(x);
    resultado = funcao2(x, y);
    funcao3();
    
    return 0;
}

