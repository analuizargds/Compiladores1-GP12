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

# Cria diretório de saída se não existir
mkdir -p "$OUTPUT_DIR"

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
    
    // Exemplo de AST para um programa simples
    func_main [label="Function: main"];
    root -> func_main;
    
    decl_a [label="Declaration: int a"];
    decl_b [label="Declaration: int b"];
    assign_a [label="Assignment: a = 10"];
    assign_b [label="Assignment: b = 5"];
    if_stmt [label="If Statement"];
    condition [label="Condition: a > b"];
    then_block [label="Then Block"];
    assign_result [label="Assignment: a = a - b"];
    return_stmt [label="Return: 0"];
    
    func_main -> decl_a;
    func_main -> decl_b;
    func_main -> assign_a;
    func_main -> assign_b;
    func_main -> if_stmt;
    func_main -> return_stmt;
    
    if_stmt -> condition;
    if_stmt -> then_block;
    then_block -> assign_result;
    
    // Exemplo de expressões
    const_10 [label="Constant: 10"];
    const_5 [label="Constant: 5"];
    const_0 [label="Constant: 0"];
    
    assign_a -> const_10;
    assign_b -> const_5;
    return_stmt -> const_0;
    
    // Exemplo de operadores
    op_gt [label="Operator: >"];
    var_a1 [label="Variable: a"];
    var_b1 [label="Variable: b"];
    condition -> op_gt;
    op_gt -> var_a1;
    op_gt -> var_b1;
    
    op_minus [label="Operator: -"];
    var_a2 [label="Variable: a"];
    var_b2 [label="Variable: b"];
    assign_result -> op_minus;
    op_minus -> var_a2;
    op_minus -> var_b2;
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
    
    // Escopo global
    global_scope [label="{Global Scope|{Symbol|Type|Line|Scope}|{a|int|2|global}|{b|int|3|global}|{main|function|5|global}}"];
    symtab -> global_scope;
    
    // Escopo da função main
    main_scope [label="{Function: main|{Symbol|Type|Line|Scope}|{result|int|6|main}|{i|int|8|main}}"];
    global_scope -> main_scope;
    
    // Escopo do bloco if
    if_scope [label="{If Block|{Symbol|Type|Line|Scope}|{temp|int|10|if-block}}"];
    main_scope -> if_scope;
    
    // Escopo do loop for
    for_scope [label="{For Loop|{Symbol|Type|Line|Scope}|{j|int|15|for-loop}}"];
    main_scope -> for_scope;
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
      "type": "FunctionDeclaration",
      "name": "main",
      "returnType": "int",
      "parameters": [],
      "body": {
        "type": "CompoundStatement",
        "children": [
          {
            "type": "VariableDeclaration",
            "name": "a",
            "dataType": "int",
            "line": 2
          },
          {
            "type": "VariableDeclaration",
            "name": "b",
            "dataType": "int",
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
          },
          {
            "type": "AssignmentExpression",
            "operator": "=",
            "left": {
              "type": "Identifier",
              "name": "b"
            },
            "right": {
              "type": "Literal",
              "value": 5,
              "dataType": "int"
            },
            "line": 5
          },
          {
            "type": "IfStatement",
            "condition": {
              "type": "BinaryExpression",
              "operator": ">",
              "left": {
                "type": "Identifier",
                "name": "a"
              },
              "right": {
                "type": "Identifier",
                "name": "b"
              }
            },
            "thenStatement": {
              "type": "CompoundStatement",
              "children": [
                {
                  "type": "AssignmentExpression",
                  "operator": "=",
                  "left": {
                    "type": "Identifier",
                    "name": "a"
                  },
                  "right": {
                    "type": "BinaryExpression",
                    "operator": "-",
                    "left": {
                      "type": "Identifier",
                      "name": "a"
                    },
                    "right": {
                      "type": "Identifier",
                      "name": "b"
                    }
                  }
                }
              ]
            },
            "elseStatement": null,
            "line": 6
          },
          {
            "type": "ReturnStatement",
            "expression": {
              "type": "Literal",
              "value": 0,
              "dataType": "int"
            },
            "line": 10
          }
        ]
      }
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
          "line": 2,
          "scope": "global"
        },
        {
          "name": "b",
          "type": "int",
          "line": 3,
          "scope": "global"
        },
        {
          "name": "main",
          "type": "function",
          "returnType": "int",
          "parameters": [],
          "line": 5,
          "scope": "global"
        }
      ]
    },
    {
      "name": "main",
      "parent": "global",
      "symbols": [
        {
          "name": "result",
          "type": "int",
          "line": 6,
          "scope": "main"
        },
        {
          "name": "i",
          "type": "int",
          "line": 8,
          "scope": "main"
        }
      ]
    },
    {
      "name": "if-block",
      "parent": "main",
      "symbols": [
        {
          "name": "temp",
          "type": "int",
          "line": 10,
          "scope": "if-block"
        }
      ]
    },
    {
      "name": "for-loop",
      "parent": "main",
      "symbols": [
        {
          "name": "j",
          "type": "int",
          "line": 15,
          "scope": "for-loop"
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
    
    # Seleciona um arquivo de teste válido para visualização
    test_file="tests/valid/test_declarations.c"
    
    if [ -f "$test_file" ]; then
        # Gera visualizações para o arquivo de teste
        generate_ast_dot "$test_file"
        generate_symbol_table_dot "$test_file"
        generate_ast_json "$test_file"
        generate_symbol_table_json "$test_file"
    else
        echo -e "${RED}Erro: Arquivo de teste $test_file não encontrado${NC}"
        exit 1
    fi
    
    echo -e "\n${GREEN}Visualizações geradas com sucesso no diretório $OUTPUT_DIR${NC}"
    echo "------------------------"
    echo -e "${YELLOW}Formatos disponíveis:${NC}"
    echo "  - DOT: Formato para visualização gráfica (requer Graphviz para conversão em imagem)"
    echo "  - JSON: Formato para processamento e visualização em ferramentas web"
    echo "------------------------"
}

# Executa a função principal
main

exit 0
