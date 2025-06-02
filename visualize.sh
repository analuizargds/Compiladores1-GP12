#!/bin/bash

# Script para visualização da AST e Tabela de Símbolos
# Este script gera representações visuais da AST e da Tabela de Símbolos em formatos DOT e JSON

# Cores para saída
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Diretórios e arquivos
OUTPUT_DIR="visualization"
COMPILER="./exemplo"
DOT_CMD=$(which dot 2>/dev/null)

# Verifica se o diretório de saída existe
mkdir -p "$OUTPUT_DIR"

# Verifica se o compilador existe
if [ ! -f "$COMPILER" ]; then
    echo -e "${RED}Erro: Compilador não encontrado em $COMPILER${NC}"
    echo "Execute 'make' para compilar o projeto antes de executar a visualização."
    exit 1
fi

# Função para gerar visualização da AST em formato DOT
generate_ast_dot() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local dot_file="$OUTPUT_DIR/${output_base}_ast.dot"
    local png_file="$OUTPUT_DIR/${output_base}_ast.png"
    
    echo -n "Gerando visualização da AST para $input_file... "
    
    # Executa o compilador com opção para gerar DOT da AST
    $COMPILER "$input_file" --ast-dot > "$dot_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$dot_file" ]; then
        echo -e "${GREEN}OK${NC}"
        
        # Converte DOT para PNG se o Graphviz estiver disponível
        if [ -n "$DOT_CMD" ]; then
            $DOT_CMD -Tpng "$dot_file" -o "$png_file"
            echo "  Imagem gerada: $png_file"
        fi
    else
        echo -e "${RED}FALHOU${NC}"
    fi
}

# Função para gerar visualização da Tabela de Símbolos em formato DOT
generate_symbol_table_dot() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local dot_file="$OUTPUT_DIR/${output_base}_symtab.dot"
    local png_file="$OUTPUT_DIR/${output_base}_symtab.png"
    
    echo -n "Gerando visualização da Tabela de Símbolos para $input_file... "
    
    # Executa o compilador com opção para gerar DOT da tabela de símbolos
    $COMPILER "$input_file" --symtab-dot > "$dot_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$dot_file" ]; then
        echo -e "${GREEN}OK${NC}"
        
        # Converte DOT para PNG se o Graphviz estiver disponível
        if [ -n "$DOT_CMD" ]; then
            $DOT_CMD -Tpng "$dot_file" -o "$png_file"
            echo "  Imagem gerada: $png_file"
        fi
    else
        echo -e "${RED}FALHOU${NC}"
    fi
}

# Função para gerar visualização da AST em formato JSON
generate_ast_json() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local json_file="$OUTPUT_DIR/${output_base}_ast.json"
    
    echo -n "Gerando JSON da AST para $input_file... "
    
    # Executa o compilador com opção para gerar JSON da AST
    $COMPILER "$input_file" --ast-json > "$json_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$json_file" ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FALHOU${NC}"
    fi
}

# Função para gerar visualização da Tabela de Símbolos em formato JSON
generate_symbol_table_json() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local json_file="$OUTPUT_DIR/${output_base}_symtab.json"
    
    echo -n "Gerando JSON da Tabela de Símbolos para $input_file... "
    
    # Executa o compilador com opção para gerar JSON da tabela de símbolos
    $COMPILER "$input_file" --symtab-json > "$json_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$json_file" ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FALHOU${NC}"
    fi
}

# Função principal
main() {
    echo "Gerando visualizações..."
    
    # Tenta com um arquivo de teste válido
    test_file="tests/valid/test_declarations.c"
    
    if [ -f "$test_file" ]; then
        # Gera visualizações para o arquivo de teste
        generate_ast_dot "$test_file"
        generate_symbol_table_dot "$test_file"
        generate_ast_json "$test_file"
        generate_symbol_table_json "$test_file"
    else
        echo "Arquivo de teste $test_file não encontrado"
        exit 1
    fi
}

# Executa a função principal
main

exit 0
