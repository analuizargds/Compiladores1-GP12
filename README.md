# Compilador C Simplificado

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
├── exemplo             # Executável principal do compilador
├── Makefile            # Regras de compilação
├── run_tests.sh        # Script para automação de testes
├── simbolos.c          # Implementação da tabela de símbolos
├── simbolos.h          # Cabeçalho da tabela de símbolos
└── visualize.sh        # Script para visualização da AST e tabela de símbolos
```

## Requisitos

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Graphviz (opcional, para visualização gráfica)

## Compilação

Para compilar o projeto, execute:

```bash
make
```

Isso irá gerar o executável `exemplo` que pode ser usado para compilar arquivos C simplificados.

## Testes

O projeto inclui um conjunto de testes automatizados para verificar o funcionamento do compilador. Para executar os testes:

```bash
make test
```

Isso executará o script `run_tests.sh` que testará o compilador com arquivos válidos e inválidos localizados nos diretórios `tests/valid` e `tests/invalid`.

## Visualização

Para gerar visualizações da AST (Árvore Sintática Abstrata) e da tabela de símbolos:

```bash
make visualize
```

Isso executará o script `visualize.sh` que gerará representações visuais em formatos DOT e JSON no diretório `visualization/`. Se o Graphviz estiver instalado, também serão geradas imagens PNG.

Para verificar se o Graphviz está instalado:

```bash
make check-graphviz
```

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

## Limpeza

Para limpar os arquivos gerados:

```bash
make clean
```

Para limpar e reconstruir tudo:

```bash
make rebuild
```

## Contribuidores

<div  class="HomeProfiles" style="justify-content: center; display: flex; flex-direction: column">

<a href="https://github.com/analuizargds" target="_blank">
    <figure>
      <img  src="https://github.com/analuizargds.png" alt="Foto da Ana Luiza Rodrigues" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Ana Luiza Rodrigues</figcaption>
    </figure>
  </a>

<a href="https://github.com/WonnzDA" target="_blank">
    <figure>
      <img  src="https://github.com/WonnzDA.png" alt="Foto da Julia Lopes" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Julia Lopes</figcaption>
    </figure>
  </a>

<a href="https://github.com/LuaMedeiros" target="_blank">
    <figure>
      <img  src="https://github.com/LuaMedeiros.png" alt="Foto da Luana Medeiros" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Luana Medeiros</figcaption>
    </figure>
  </a>

<a href="https://github.com/Katuner" target="_blank">
    <figure>
      <img  src="https://github.com/Katuner.png" alt="Foto do Lucas Meireles" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Lucas Meireles</figcaption>
    </figure>
  </a>

<a href="https://github.com/milenaaires" target="_blank">
    <figure>
      <img  src="https://github.com/milenaaires.png" alt="Foto da Milena Aires" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Milena Aires</figcaption>
    </figure>
  </a>

<a href="https://github.com/Rodrigomfab88" target="_blank">
    <figure>
      <img  src="https://github.com/Rodrigomfab88.png" alt="Foto do Rodrigo Mattos" width="220px" style="border-radius: 6%">
      <figcaption style="font-weight: bold; color: #000000;">Rodrigo Mattos</figcaption>
    </figure>
  </a>

</div>
