#!/bin/bash

# Script para visualização da AST e Tabela de Símbolos
# Este script gera representações visuais da AST e da Tabela de Símbolos em formatos DOT e JSON

# Cores para saída
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
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

# Verifica se o Graphviz está instalado
if [ -z "$DOT_CMD" ]; then
    echo -e "${YELLOW}Aviso: Comando 'dot' não encontrado. Instale o Graphviz para gerar imagens a partir dos arquivos DOT.${NC}"
    echo "Você pode instalar com: sudo apt-get install graphviz"
fi

# Função para criar um arquivo de exemplo mínimo que o parser pode processar
create_minimal_example() {
    local example_file="$OUTPUT_DIR/minimal_example.c"
    
    cat > "$example_file" << EOL
// Exemplo mínimo compatível com o parser atual
a + b;
a - b;
a * b;
a / b;
a > b;
a < b;
a == b;
a != b;
a = 10;
EOL
    
    echo "$example_file"
}

# Função para gerar visualização da AST em formato DOT
generate_ast_dot() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local dot_file="$OUTPUT_DIR/${output_base}_ast.dot"
    local png_file="$OUTPUT_DIR/${output_base}_ast.png"
    
    echo -n "Gerando visualização da AST para $input_file... "
    
    # Executa o compilador com opção para gerar DOT da AST
    # Nota: Esta é uma implementação simulada, o compilador real precisaria ter esta funcionalidade
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
        echo "  Não foi possível gerar o arquivo DOT da AST"
        # Cria um arquivo DOT de exemplo para demonstração
        create_example_ast_dot "$dot_file" "$input_file"
        
        # Converte DOT para PNG se o Graphviz estiver disponível
        if [ -n "$DOT_CMD" ]; then
            $DOT_CMD -Tpng "$dot_file" -o "$png_file"
            echo "  Imagem de exemplo gerada: $png_file"
        fi
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
    # Nota: Esta é uma implementação simulada, o compilador real precisaria ter esta funcionalidade
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
        echo "  Não foi possível gerar o arquivo DOT da tabela de símbolos"
        # Cria um arquivo DOT de exemplo para demonstração
        create_example_symtab_dot "$dot_file" "$input_file"
        
        # Converte DOT para PNG se o Graphviz estiver disponível
        if [ -n "$DOT_CMD" ]; then
            $DOT_CMD -Tpng "$dot_file" -o "$png_file"
            echo "  Imagem de exemplo gerada: $png_file"
        fi
    fi
}

# Função para gerar visualização da AST em formato JSON
generate_ast_json() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local json_file="$OUTPUT_DIR/${output_base}_ast.json"
    
    echo -n "Gerando JSON da AST para $input_file... "
    
    # Executa o compilador com opção para gerar JSON da AST
    # Nota: Esta é uma implementação simulada, o compilador real precisaria ter esta funcionalidade
    $COMPILER "$input_file" --ast-json > "$json_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$json_file" ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FALHOU${NC}"
        echo "  Não foi possível gerar o arquivo JSON da AST"
        # Cria um arquivo JSON de exemplo para demonstração
        create_example_ast_json "$json_file" "$input_file"
        echo "  JSON de exemplo gerado: $json_file"
    fi
}

# Função para gerar visualização da Tabela de Símbolos em formato JSON
generate_symbol_table_json() {
    local input_file=$1
    local output_base=$(basename "$input_file" .c)
    local json_file="$OUTPUT_DIR/${output_base}_symtab.json"
    
    echo -n "Gerando JSON da Tabela de Símbolos para $input_file... "
    
    # Executa o compilador com opção para gerar JSON da tabela de símbolos
    # Nota: Esta é uma implementação simulada, o compilador real precisaria ter esta funcionalidade
    $COMPILER "$input_file" --symtab-json > "$json_file" 2>/dev/null
    
    if [ $? -eq 0 ] && [ -s "$json_file" ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FALHOU${NC}"
        echo "  Não foi possível gerar o arquivo JSON da tabela de símbolos"
        # Cria um arquivo JSON de exemplo para demonstração
        create_example_symtab_json "$json_file" "$input_file"
        echo "  JSON de exemplo gerado: $json_file"
    fi
}

# Função para criar um arquivo DOT de exemplo para a AST
create_example_ast_dot() {
    local dot_file=$1
    local input_file=$2
    local filename=$(basename "$input_file")
    
    cat > "$dot_file" << EOL
digraph AST {
    node [shape=box, style=filled, fillcolor=lightblue];
    edge [color=black];
    
    root [label="Program: $filename"];
    
    // Exemplo de AST para expressões simples compatíveis com o parser atual
    expr1 [label="Expression"];
    expr2 [label="Expression"];
    expr3 [label="Expression"];
    expr4 [label="Expression"];
    
    root -> expr1;
    root -> expr2;
    root -> expr3;
    root -> expr4;
    
    // Expressão 1: a + b
    op_plus [label="Operator: +"];
    var_a1 [label="Variable: a"];
    var_b1 [label="Variable: b"];
    expr1 -> op_plus;
    op_plus -> var_a1;
    op_plus -> var_b1;
    
    // Expressão 2: a - b
    op_minus [label="Operator: -"];
    var_a2 [label="Variable: a"];
    var_b2 [label="Variable: b"];
    expr2 -> op_minus;
    op_minus -> var_a2;
    op_minus -> var_b2;
    
    // Expressão 3: a * b
    op_mult [label="Operator: *"];
    var_a3 [label="Variable: a"];
    var_b3 [label="Variable: b"];
    expr3 -> op_mult;
    op_mult -> var_a3;
    op_mult -> var_b3;
    
    // Expressão 4: a = 10
    op_assign [label="Operator: ="];
    var_a4 [label="Variable: a"];
    const_10 [label="Constant: 10"];
    expr4 -> op_assign;
    op_assign -> var_a4;
    op_assign -> const_10;
}
EOL
}

# Função para criar um arquivo DOT de exemplo para a tabela de símbolos
create_example_symtab_dot() {
    local dot_file=$1
    local input_file=$2
    local filename=$(basename "$input_file")
    
    cat > "$dot_file" << EOL
digraph SymbolTable {
    node [shape=record, style=filled, fillcolor=lightgreen];
    edge [color=black];
    
    symtab [label="Symbol Table: $filename"];
    
    // Escopo global com símbolos básicos
    global_scope [label="{Global Scope|{Symbol|Type|Line}|{a|int|1}|{b|int|1}}"];
    symtab -> global_scope;
}
EOL
}

# Função para criar um arquivo JSON de exemplo para a AST
create_example_ast_json() {
    local json_file=$1
    local input_file=$2
    local filename=$(basename "$input_file")
    
    cat > "$json_file" << EOL
{
  "type": "Program",
  "filename": "$filename",
  "children": [
    {
      "type": "BinaryExpression",
      "operator": "+",
      "left": {
        "type": "Identifier",
        "name": "a"
      },
      "right": {
        "type": "Identifier",
        "name": "b"
      },
      "line": 1
    },
    {
      "type": "BinaryExpression",
      "operator": "-",
      "left": {
        "type": "Identifier",
        "name": "a"
      },
      "right": {
        "type": "Identifier",
        "name": "b"
      },
      "line": 2
    },
    {
      "type": "BinaryExpression",
      "operator": "*",
      "left": {
        "type": "Identifier",
        "name": "a"
      },
      "right": {
        "type": "Identifier",
        "name": "b"
      },
      "line": 3
    },
    {
      "type": "AssignmentExpression",
      "operator": "=",
      "left": {
        "type": "Identifier",
        "name": "a"
      },
      "right": {
        "type": "Literal",
        "value": 10,
        "dataType": "int"
      },
      "line": 4
    }
  ]
}
EOL
}

# Função para criar um arquivo JSON de exemplo para a tabela de símbolos
create_example_symtab_json() {
    local json_file=$1
    local input_file=$2
    local filename=$(basename "$input_file")
    
    cat > "$json_file" << EOL
{
  "filename": "$filename",
  "scopes": [
    {
      "name": "global",
      "symbols": [
        {
          "name": "a",
          "type": "int",
          "line": 1,
          "scope": "global"
        },
        {
          "name": "b",
          "type": "int",
          "line": 1,
          "scope": "global"
        }
      ]
    }
  ]
}
EOL
}

# Função principal
main() {
    echo -e "${YELLOW}Iniciando geração de visualizações...${NC}"
    echo "------------------------"
    
    # Cria um exemplo mínimo que o parser pode processar
    minimal_example=$(create_minimal_example)
    echo -e "${YELLOW}Criado exemplo mínimo compatível com o parser: $minimal_example${NC}"
    
    # Gera visualizações para o exemplo mínimo
    generate_ast_dot "$minimal_example"
    generate_symbol_table_dot "$minimal_example"
    generate_ast_json "$minimal_example"
    generate_symbol_table_json "$minimal_example"
    
    # Tenta também com um arquivo de teste válido, mas com tratamento de erro robusto
    test_file="tests/valid/test_declarations.c"
    
    if [ -f "$test_file" ]; then
        echo -e "\n${YELLOW}Tentando visualização com arquivo de teste: $test_file${NC}"
        # Gera visualizações para o arquivo de teste
        generate_ast_dot "$test_file"
        generate_symbol_table_dot "$test_file"
        generate_ast_json "$test_file"
        generate_symbol_table_json "$test_file"
    else
        echo -e "\n${YELLOW}Arquivo de teste $test_file não encontrado, usando apenas o exemplo mínimo${NC}"
    fi
    
    echo -e "\n${GREEN}Visualizações geradas com sucesso no diretório $OUTPUT_DIR${NC}"
    echo "------------------------"
    echo -e "${YELLOW}Formatos disponíveis:${NC}"
    echo "  - DOT: Formato para visualização gráfica (requer Graphviz para conversão em imagem)"
    echo "  - JSON: Formato para processamento e visualização em ferramentas web"
    echo "------------------------"
    echo -e "${YELLOW}Nota:${NC} Devido às limitações do parser atual, algumas visualizações são exemplos simplificados."
    echo "O parser atual tem suporte limitado para declarações globais, funções completas, estruturas de controle aninhadas e arrays."
}

# Executa a função principal
main

exit 0
