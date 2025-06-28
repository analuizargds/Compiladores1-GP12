# CtoMMD

Este repositório contém a implementação de um compilador simplificado para a linguagem C, desenvolvido como parte do projeto da disciplina de Compiladores.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

```
.
├── ast/                # Implementação da Árvore Sintática Abstrata (AST)
├── lexer/              # Analisador léxico (Flex)
├── parser/             # Analisador sintático (Bison)
├── semantic/           # Análise semântica
├── tests/              # Arquivos de teste
│   ├── valid/          # Testes com código válido
│   └── invalid/        # Testes com código inválido
├── visualization/      # Visualizações geradas da AST e tabela de símbolos
├── exemplo             # CtoMMD
├── Makefile            # Regras de compilação
├── cfg_design.md       # Documentação de explicação para funcionamento da conversão para fluxograma
├── README.md           # Este arquivo de leitura
├── run_tests.sh        # Script para automação de testes
├── simbolos.c          # Implementação da tabela de símbolos
├── simbolos.h          # Cabeçalho da tabela de símbolos
└── visualize.sh        # Script para visualização da AST e tabela de símbolos
```

## Requisitos

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- MermaidCLI (opcional, para visualização gráfica)
- Make

O Mermaid CLI é a opção prática para converter os arquivos diretmanete na máquina, porém pode ser substituido por um Navegador Web com acesso à internet ou ainda um editor que tenha suporte à arquivos mermaid (.mmd), como VS Code, Obsidian.
Informações adicionais:

- **GitHub**: [mermaid-js/mermaid-cli](https://github.com/mermaid-js/mermaid-cli)
- **Documentação**: [Mermaid CLI Documentation](https://github.com/mermaid-js/mermaid-cli#readme)

## Instalação do Mermaid CLI

O Mermaid CLI permite converter arquivos `.mmd` diretamente para imagens PNG, SVG ou PDF.

### Instalação via npm

```bash
npm install -g @mermaid-js/mermaid-cli
```

### Verificar instalação

```bash
mmdc --version
```

## Instalação do compilador

1. Clone o repositório

```bash
git clone https://github.com/analuizargds/Compiladores1-GP12.git
cd Compiladores1-GP12
```

2. Compile o projeto

```bash
make clean
make
```

Isso criará o executável `CtoMMD` no diretório raiz.

## Uso

### 1. Compilar código C para Mermaid

```bash
./CtoMMD arquivo_entrada.c
```

Isso gerará um arquivo `cfg.mmd` contendo o fluxograma em formato Mermaid.

### 2. Usar o Makefile para compilação e conversão automática

#### Gerar fluxograma e converter para PNG

```bash
make compPng ARQUIVO=entrada.c
```

#### Gerar fluxograma e converter para PDF

```bash
make compPdf ARQUIVO=entrada.c
```

#### Limpar arquivos gerados

```bash
make clean        # Remove arquivos objeto e executável
make cleanImg     # Remove arquivos PNG e PDF gerados
make cleanAll     # Remove todos os arquivos gerados
```

### 3. Visualizar o fluxograma manualmente

#### Opção A: Visualizador online

1. Abra um visualizador Mermaid online:
   - [Mermaid Live Editor](https://mermaid.live/)
   - [Mermaid Chart](https://www.mermaidchart.com/)

2. Copie o conteúdo do arquivo `cfg.mmd` e cole no editor

3. O fluxograma será renderizado automaticamente

#### Opção B: VS Code com extensão Mermaid

1. Instale a extensão "Mermaid Preview" no VS Code
2. Abra o arquivo `cfg.mmd` no VS Code
3. Use Ctrl+Shift+P e digite "Mermaid: Preview"

#### Opção C: Mermaid CLI (conversão manual)

```bash
# Para PNG
mmdc -i cfg.mmd -o fluxograma.png

# Para PDF
mmdc -i cfg.mmd -o fluxograma.pdf

# Para SVG
mmdc -i cfg.mmd -o fluxograma.svg
```

## Tipos de Nós no Fluxograma

| Tipo | Forma | Cor | Descrição |
|------|-------|-----|-----------|
| Início/Fim | Oval `([texto])` | Verde claro | Pontos de entrada e saída da função |
| Decisão | Losango `{texto}` | Amarelo | Condições (if, while, for) |
| Processo | Retângulo `[texto]` | Azul claro | Declarações, atribuições, instruções |
| Função | Retângulo duplo `[[texto]]` | Roxo claro | Chamadas de função |
| Retorno | Retângulo `[texto]` | Laranja | Instruções return |
| Junção | Círculo pequeno `(( ))` | Cinza | Convergência de fluxos |

## Arquivos de Teste

### Testes Válidos

- `test_declarations.c`: Testa diferentes tipos de declarações válidas
- `test_expressions.c`: Testa diferentes tipos de expressões válidas
- `test_control_structures.c`: Testa diferentes estruturas de controle válidas

### Testes Inválidos

- `test_syntax_errors.c`: Contém erros de sintaxe para testar o compilador
- `test_semantic_errors.c`: Contém erros semânticos para testar o compilador
- `test_scope_errors.c`: Contém erros de escopo para testar o compilador

## Funcionalidades Implementadas

- Análise léxica
- Análise sintática
- Construção da AST
- Tabela de símbolos
- Análise semântica
- Verificação de tipos
- Visualização da AST e tabela de símbolos
- Testes automatizados

## Melhorias

- Reconhecimento de arrays, ponteiros e casting
- Regras do parser
- Melhoria da construção da AST
- Melhoria da conversão para CFG


## Solução de Problemas

### Erro de compilação

- Verifique se todos os pré-requisitos estão instalados
- Execute `make clean` antes de `make`

### Arquivo cfg.mmd não gerado

- Verifique se o arquivo C de entrada existe
- Verifique se há erros de sintaxe no código C

### Fluxograma não renderiza

- Verifique se o conteúdo do arquivo cfg.mmd está correto
- Para Linux, não execute como root, há um [problema conhecido](https://github.com/mermaid-js/mermaid-cli/blob/11.6.0/docs/linux-sandbox-issue.md)
- Teste em diferentes visualizadores Mermaid

## Contribuidores

| ![Ana Luiza Rodrigues](https://github.com/analuizargds.png) | ![Julia Lopes](https://github.com/WonnzDA.png) | ![Luana Medeiros](https://github.com/LuaMedeiros.png) | ![Lucas Meireles](https://github.com/Katuner.png) | ![Milena Aires](https://github.com/milenaaires.png) | ![Rodrigo Mattos](https://github.com/Rodrigomfab88.png) |
|:----------------:|:--------------------:|:---------------------:|:-------------------:|:-------------------:|:-------------------:|
|[Ana Luiza Rodrigues](https://github.com/analuizargds)|[Julia Lopes](https://github.com/WonnzDA)|[Luana Medeiros](https://github.com/LuaMedeiros)|[Lucas Meireles](https://github.com/Katuner)| [Milena Aires](https://github.com/milenaaires)|[Rodrigo Mattos](https://github.com/Rodrigomfab88)|