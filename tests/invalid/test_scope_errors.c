/*
 * Arquivo de teste: Erros de escopo
 * Este arquivo contém erros de escopo para testar o compilador
 */

// Variável global
int globalVar = 10;

int main() {
    // Erro: Acesso a variável fora de escopo
    {
        int localVar = 5;
    }
    int result = localVar + 10; // localVar está fora de escopo aqui
    
    // Erro: Uso de variável antes da declaração
    int sum = a + b;
    int a = 5;
    int b = 10;
    
    // Erro: Acesso a variável de função em outra função
    int otherResult = funcVar; // funcVar não está visível aqui
    
    return 0;
}

void anotherFunction() {
    // Declaração de variável local à função
    int funcVar = 20;
    
    // Erro: Redeclaração de variável global com mesmo nome
    int globalVar = 30;
    
    // Erro: Acesso a variável de loop fora do loop
    for (int i = 0; i < 10; i++) {
        // i está visível aqui
    }
    int j = i + 5; // i não está visível aqui
}
