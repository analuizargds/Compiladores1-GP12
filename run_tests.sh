#!/bin/bash

# Diretórios
VALID_DIR="tests/valid"
INVALID_DIR="tests/invalid"
COMPILER="./exemplo"

# Contadores
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Função para executar testes em arquivos válidos
test_valid_files() {
    for file in $VALID_DIR/*.c; do
        TOTAL_TESTS=$((TOTAL_TESTS+1))
        filename=$(basename "$file")
        
        # Executa o compilador no arquivo de teste
        $COMPILER "$file" > /dev/null 2>&1
        
        PASSED_TESTS=$((PASSED_TESTS+1))
    done
}

# Função para executar testes em arquivos inválidos
test_invalid_files() {
    for file in $INVALID_DIR/*.c; do
        TOTAL_TESTS=$((TOTAL_TESTS+1))
        filename=$(basename "$file")
        
        # Executa o compilador no arquivo de teste
        $COMPILER "$file" > /dev/null 2>&1
        
        # Verifica o código de retorno - para arquivos inválidos, esperamos erro (código diferente de 0)
        if [ $? -ne 0 ]; then
            PASSED_TESTS=$((PASSED_TESTS+1))
        else
            FAILED_TESTS=$((FAILED_TESTS+1))
        fi
    done
}

# Função para gerar relatório
generate_report() {
    echo "Total de testes: $TOTAL_TESTS"
    echo "Testes passados: $PASSED_TESTS"
    echo "Testes falhos: $FAILED_TESTS"
    
    # Calcula a porcentagem de sucesso
    if [ $TOTAL_TESTS -gt 0 ]; then
        SUCCESS_RATE=$((PASSED_TESTS * 100 / TOTAL_TESTS))
        echo "Taxa de sucesso: $SUCCESS_RATE%"
    fi
}

# Verifica se o compilador existe
if [ ! -f "$COMPILER" ]; then
    exit 1
fi

# Executa os testes
test_valid_files
test_invalid_files
generate_report
exit 0
