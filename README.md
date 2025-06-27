# CtoMMD - Compilador C para Mermaid Flowchart

CtoMMD é um compilador que converte código C em fluxogramas visuais usando a sintaxe Mermaid. O compilador analisa a estrutura do código C e gera um grafo de fluxo de controle (CFG) que pode ser visualizado como um fluxograma intuitivo, ideal para iniciantes em programação.

## Características

- **Análise sintática completa**: Processa declarações de variáveis, estruturas de controle (if-else, while, for), funções e retornos
- **Fluxograma detalhado**: Gera visualizações que mostram o fluxo de execução do código
- **Formato Mermaid**: Saída compatível com visualizadores Mermaid populares
- **Estilo Flowgorithm**: Visual similar ao Flowgorithm para facilitar a compreensão
- **Cores diferenciadas**: Cada tipo de nó tem cor e forma específicas (decisões, processos, início/fim)

## Pré-requisitos

### Para compilar o CtoMMD:
- GCC (GNU Compiler Collection)
- Flex (analisador léxico)
- Bison (gerador de parser)
- Make

### Para visualizar os fluxogramas:
- Navegador web com acesso à internet (para visualizadores online)
- OU editor que suporte Mermaid (VS Code, Obsidian, etc.)
- OU **Mermaid CLI** (recomendado para conversão em imagens)

## Instalação do Mermaid CLI

O Mermaid CLI permite converter arquivos `.mmd` diretamente para imagens PNG, SVG ou PDF.

### Instalação via npm:
```bash
npm install -g @mermaid-js/mermaid-cli
```

### Verificar instalação:
```bash
mmdc --version
```

### Repositório oficial:
- **GitHub**: [mermaid-js/mermaid-cli](https://github.com/mermaid-js/mermaid-cli)
- **Documentação**: [Mermaid CLI Documentation](https://github.com/mermaid-js/mermaid-cli#readme)

## Instalação

1. Clone o repositório:
```bash
git clone https://github.com/analuizargds/Compiladores1-GP12.git
cd Compiladores1-GP12
```

2. Compile o projeto:
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

Exemplo:
```bash
./CtoMMD entrada.c
```

Isso gerará um arquivo `cfg.mmd` contendo o fluxograma em formato Mermaid.

### 2. Usar o Makefile para compilação e conversão automática

#### Gerar fluxograma e converter para PNG:
```bash
make compPng ARQUIVO=entrada.c
```

#### Gerar fluxograma e converter para PDF:
```bash
make compPdf ARQUIVO=entrada.c
```

#### Limpar arquivos gerados:
```bash
make clean        # Remove arquivos objeto e executável
make cleanImg     # Remove arquivos PNG e PDF gerados
make cleanAll     # Remove todos os arquivos gerados
```

### 3. Visualizar o fluxograma manualmente

#### Opção A: Visualizador online (Recomendado)
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

## Exemplo de Uso

### Código C de entrada (`exemplo.c`):
```c
int main(){
   int x;

   if (x > 0) {
       x = x + 1;
   } else {
       x = x - 1;
   }
   return 0;
}
```

### Comando:
```bash
./CtoMMD exemplo.c
```

### Saída gerada (`cfg.mmd`):
```mermaid
graph TD
    0([Start: main]) :::startEnd
    2[VAR_DECL: TYPE: int x] :::process
    3{x > 0} :::decision
    6[x = x - 1] :::process
    5[x = x + 1] :::process
    4(( )) :::join
    7[RETURN 0] :::return
    1([End]) :::startEnd
    0 --> 2
    2 --> 3
    3 -->|False| 6
    3 -->|True| 5
    6 --> 4
    5 --> 4
    4 --> 7
    7 --> 1

    classDef startEnd fill:#90EE90,stroke:#333,stroke-width:2px,color:#000
    classDef decision fill:#FFD700,stroke:#333,stroke-width:2px,color:#000
    classDef process fill:#87CEEB,stroke:#333,stroke-width:2px,color:#000
    classDef function fill:#DDA0DD,stroke:#333,stroke-width:2px,color:#000
    classDef return fill:#FFA07A,stroke:#333,stroke-width:2px,color:#000
    classDef join fill:#D3D3D3,stroke:#333,stroke-width:2px,color:#000
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

## Estruturas Suportadas

- **Declarações de variáveis**: `int x;`, `float y;`
- **Atribuições**: `x = 5;`, `y = x + 1;`
- **Condicionais**: `if (condição) { ... } else { ... }`
- **Loops**: `while (condição) { ... }`, `for (init; condição; incremento) { ... }`
- **Funções**: `int main() { ... }`, chamadas de função
- **Retornos**: `return valor;`
- **Operações**: aritméticas, relacionais, lógicas

## Solução de Problemas

### Erro de compilação
- Verifique se todos os pré-requisitos estão instalados
- Execute `make clean` antes de `make`

### Arquivo cfg.mmd não gerado
- Verifique se o arquivo C de entrada existe
- Verifique se há erros de sintaxe no código C

### Fluxograma não renderiza
- Verifique se o conteúdo do arquivo cfg.mmd está correto
- Teste em diferentes visualizadores Mermaid

## Desenvolvimento

### Estrutura do projeto:
```
├── ast/           # Árvore de Sintaxe Abstrata e CFG
├── lexer/         # Analisador léxico
├── parser/        # Analisador sintático
├── semantic/      # Análise semântica
├── src/           # Código principal
├── Makefile       # Script de compilação
└── README.md      # Esta documentação
```

### Para desenvolvedores:
- O arquivo principal está em `src/main.c`
- A geração do CFG está implementada em `ast/ast.c`
- A função `build_and_generate_cfg_mermaid()` é responsável pela conversão

## Licença

Este projeto é parte do curso de Compiladores e está disponível para fins educacionais.

## Contribuições

Contribuições são bem-vindas! Por favor, abra uma issue ou pull request no repositório GitHub.

