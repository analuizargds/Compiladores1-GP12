/*
 * Arquivo de teste: Erros de sintaxe
 * Este arquivo contém erros de sintaxe para testar o compilador
 */

int main() {
    // Erro: Ponto e vírgula ausente
    int a = 10
    
    // Erro: Parêntese não fechado
    if (a > 5 {
        a = 20;
    }
    
    // Erro: Chave não fechada
    while (a > 0) {
        a--;
    
    // Erro: Operador inválido
    int b = a @@ 5;
    
    // Erro: Parêntese extra
    int c = (a + 5));
    
    // Erro: Palavra-chave incompleta
    fr (int i = 0; i < 10; i++) {
        a += i;
    }
    
    // Erro: Aspas não fechadas
    char str[] = "texto incompleto;
    
    // Erro: Uso de vírgula em vez de ponto e vírgula
    int x = 10,
    int y = 20;
    
    return 0;
}
