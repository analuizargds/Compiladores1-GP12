int soma(int a, int b) {
    return a + b;
}

int multiplicacao(int x, int y) {
    int resultado;
    resultado = x * y;
    return resultado;
}

int main() {
    int a = 5;
    int b = 3;
    int resultado1;
    int resultado2;
    
    resultado1 = soma(a, b);
    resultado2 = multiplicacao(a, b);
    
    return 0;
}

