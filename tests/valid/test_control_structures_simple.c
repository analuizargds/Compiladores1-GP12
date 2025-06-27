/*
 * Arquivo de teste: Estruturas de controle válidas (versão simplificada)
 * Este arquivo testa estruturas de controle básicas suportadas pelo compilador
 */

int main() {
    int a = 10;
    int b = 5;
    int i = 0;
    int j = 0;
    
    // Estrutura if simples
    if (a > b) {
        a = a - b;
    }
    
    // Estrutura if-else
    if (a < b) {
        a = a + 1;
    } else {
        b = b + 1;
    }
    
    // Estrutura if-else if-else
    if (a > 15) {
        a = 15;
    } else if (a > 10) {
        a = 10;
    } else {
        a = 5;
    }
    
    // Loop for simples
    for (i = 0; i < 10; i = i + 1) {
        a = a + i;
    }
    
    // Loop while
    i = 0;
    while (i < 10) {
        a = a + 1;
        i = i + 1;
    }
    
    // Estruturas de controle aninhadas
    for (i = 0; i < 5; i = i + 1) {
        if (i > 2) {
            for (j = 0; j < 3; j = j + 1) {
                a = a + j;
            }
        } else {
            while (j > 0) {
                b = b + j;
                j = j - 1;
            }
        }
    }
    
    return 0;
}

