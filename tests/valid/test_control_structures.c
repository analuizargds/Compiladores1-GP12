/*
 * Arquivo de teste: Estruturas de controle válidas
 * Este arquivo testa diferentes tipos de estruturas de controle válidas em C
 */

int main() {
    int a = 10, b = 5, i, j;
    
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
    
    // Estrutura switch-case
    switch (a) {
        case 5:
            b = 1;
            break;
        case 10:
            b = 2;
            break;
        case 15:
            b = 3;
            break;
        default:
            b = 0;
            break;
    }
    
    // Loop for
    for (i = 0; i < 10; i++) {
        a = a + i;
    }
    
    // Loop for com múltiplas variáveis
    for (i = 0, j = 10; i < j; i++, j--) {
        a = a + i - j;
    }
    
    // Loop while
    i = 0;
    while (i < 10) {
        a = a + 1;
        i++;
    }
    
    // Loop do-while
    i = 0;
    do {
        b = b + 1;
        i++;
    } while (i < 5);
    
    // Estruturas de controle aninhadas
    for (i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < 3; j++) {
                a = a + j;
            }
        } else {
            while (j > 0) {
                b = b + j;
                j--;
            }
        }
    }
    
    // Uso de break
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        a = a + i;
    }
    
    // Uso de continue
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        b = b + i;
    }
    
    return 0;
}
