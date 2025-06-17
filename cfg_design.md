# Design da Estrutura e Algoritmo para Geração de Fluxograma de Execução (CFG)

## 1. Introdução ao Grafo de Fluxo de Controle (CFG)

O Grafo de Fluxo de Controle (CFG) é uma representação abstrata do fluxo de controle de um programa. Ele é amplamente utilizado em análise de programas, otimização de compiladores e depuração. Diferente da Árvore de Sintaxe Abstrata (AST), que representa a estrutura hierárquica do código, o CFG foca nas possíveis sequências de execução das instruções. Cada nó no CFG representa um bloco básico de código (uma sequência de instruções que é sempre executada do início ao fim sem saltos ou ramificações internas), e as arestas representam as possíveis transições de controle entre esses blocos.

Para o nosso compilador, o objetivo é gerar um CFG que visualize o fluxo de execução do código C de entrada, permitindo uma compreensão clara de como o programa se comporta em tempo de execução. Isso é particularmente útil para identificar caminhos de execução, loops, condições e chamadas de função, auxiliando na depuração e na análise de segurança ou desempenho do código.

## 2. Conceitos Chave do CFG

Para construir um CFG eficaz, definimos diferentes tipos de nós e arestas que representam os elementos de controle de fluxo em um programa C. Estes tipos de nós são essenciais para capturar a semântica do fluxo de controle e para gerar uma representação visual significativa no Graphviz.

### 2.1. Tipos de Nós (CFGNodeType)

Os nós do CFG são categorizados para refletir seu papel no fluxo de controle. A enumeração `CFGNodeType` em `ast.h` define os seguintes tipos:

*   **`CFG_NODE_ENTRY`**: Representa o ponto de entrada de uma função ou de um programa. Geralmente, é o primeiro nó de um subgrafo de função.
*   **`CFG_NODE_EXIT`**: Representa o ponto de saída de uma função ou de um programa. É o último nó de um subgrafo de função.
*   **`CFG_NODE_STATEMENT`**: Representa uma instrução simples ou um bloco básico de instruções que não altera o fluxo de controle (e.g., declarações de variáveis, atribuições, chamadas de função que não são de controle).
*   **`CFG_NODE_CONDITION`**: Representa uma expressão condicional que determina o fluxo de controle (e.g., a condição de um `if`, `while`, `for` ou `do-while`). Este nó terá múltiplas arestas de saída, geralmente rotuladas como "True" e "False".
*   **`CFG_NODE_JOIN`**: Representa um ponto onde múltiplos caminhos de controle se unem (e.g., após um `if-else` ou um `switch`).
*   **`CFG_NODE_LOOP_ENTRY`**: Marca o início de uma estrutura de loop (e.g., `while`, `for`, `do-while`).
*   **`CFG_NODE_LOOP_EXIT`**: Marca o ponto de saída de uma estrutura de loop, para onde o controle é transferido quando o loop termina.
*   **`CFG_NODE_FUNCTION_CALL`**: Representa uma chamada explícita a uma função. Embora as chamadas de função possam ser consideradas `CFG_NODE_STATEMENT`, um tipo dedicado permite uma visualização mais clara.
*   **`CFG_NODE_RETURN`**: Representa a instrução `return` que encerra a execução da função atual e retorna o controle ao chamador.
*   **`CFG_NODE_BREAK`**: Representa a instrução `break`, que transfere o controle para fora da estrutura de loop ou `switch` mais interna.
*   **`CFG_NODE_CONTINUE`**: Representa a instrução `continue`, que transfere o controle para a próxima iteração da estrutura de loop mais interna.
*   **`CFG_NODE_BLOCK_ENTRY`**: Representa a entrada de um bloco de código (`{ ... }`). Útil para estruturar o CFG de forma mais granular.

### 2.2. Arestas (CFGEdge)

As arestas no CFG representam as transições de controle entre os nós. Cada aresta tem um nó de origem (`from`), um nó de destino (`to`) e, opcionalmente, um rótulo (`label`) que descreve a condição da transição (e.g., "True", "False" para ramificações condicionais).




## 3. Estruturas de Dados

As estruturas de dados para representar o CFG são definidas em `ast.h`:

### 3.1. `CFGNode`

```c
typedef struct CFGNode {
    int id;                 // ID único para o nó DOT
    CFGNodeType type;       // Tipo do nó (conforme CFGNodeType)
    char *label;            // Rótulo para o nó (e.g., código, condição)
    CFGEdge *edges;         // Lista de arestas de saída
    AST *ast_node_ref;      // Referência ao nó da AST que gerou este CFGNode
    struct CFGNode *list_next; // Próximo nó na lista global de todos os nós CFG
} CFGNode;
```

*   `id`: Um identificador numérico único para cada nó do CFG, usado para gerar o arquivo DOT.
*   `type`: O tipo do nó, conforme definido em `CFGNodeType`.
*   `label`: Uma string que descreve o conteúdo ou a função do nó (e.g., a instrução C, a condição, "Entry", "Exit").
*   `edges`: Um ponteiro para a cabeça de uma lista encadeada de estruturas `CFGEdge`, representando todas as arestas de saída deste nó.
*   `ast_node_ref`: Um ponteiro opcional para o nó da AST que corresponde a este nó do CFG. Isso pode ser útil para depuração e para vincular o CFG de volta ao código-fonte original.
*   `list_next`: Um ponteiro usado para manter uma lista global de todos os nós CFG criados. Isso facilita a iteração sobre todos os nós (e.g., para gerar o arquivo DOT ou para liberar memória).

### 3.2. `CFGEdge`

```c
typedef struct CFGEdge {
    CFGNode *to;        // Nó de destino
    char *label;        // Rótulo da aresta (e.g., "True", "False")
    CFGEdge *next;      // Próxima aresta na lista de adjacência
} CFGEdge;
```

*   `to`: Um ponteiro para o `CFGNode` de destino da aresta.
*   `label`: Uma string opcional que rotula a aresta, útil para indicar a condição de uma ramificação (e.g., "True", "False").
*   `next`: Um ponteiro para a próxima aresta na lista de adjacência do nó de origem.

### 3.3. `CFGFragment`

```c
typedef struct {
    CFGNode *entry;
    CFGNode *exit;
} CFGFragment;
```

Esta estrutura é uma conveniência para a construção recursiva do CFG. Ela representa um fragmento do CFG, que possui um único ponto de entrada (`entry`) e um único ponto de saída (`exit`). A função `build_cfg_from_ast` retorna um `CFGFragment` para cada nó da AST processado, permitindo que fragmentos maiores sejam construídos pela composição de fragmentos menores.

## 4. Algoritmo de Geração do CFG a partir da AST

A geração do CFG é realizada percorrendo a AST de forma recursiva. A função principal para isso é `build_cfg_from_ast(AST *node)`, que recebe um nó da AST e retorna um `CFGFragment` correspondente.

### 4.1. Função Principal: `build_cfg_from_ast(AST *node)`

Esta função opera com base no tipo do nó da AST (`node->tipo`):

1.  **Nós de Bloco (`AST_BLOCK`):**
    *   Cria um nó `CFG_NODE_BLOCK_ENTRY` como ponto de entrada do bloco.
    *   Itera sobre a lista de instruções (`node->filho1`, que é uma lista encadeada de `ASTNode`s ligados por `prox`).
    *   Para cada instrução na lista, chama recursivamente `build_cfg_from_ast` para obter o fragmento CFG da instrução.
    *   Conecta a saída do fragmento anterior (ou o nó de entrada do bloco) à entrada do fragmento da instrução atual.
    *   O ponto de saída do bloco é o ponto de saída do último fragmento de instrução processado.

2.  **Nós de Declaração (`AST_VAR_DECL`):**
    *   Cria um nó `CFG_NODE_STATEMENT` com um rótulo descrevendo a declaração (e.g., "Decl: int x").
    *   Este nó é tanto a entrada quanto a saída do fragmento.

3.  **Nós de Atribuição (`AST_ASSIGN`):**
    *   Cria um nó `CFG_NODE_STATEMENT` com um rótulo descrevendo a atribuição (e.g., "Assign: x = ...").
    *   Este nó é tanto a entrada quanto a saída do fragmento.

4.  **Nós de Chamada de Função (`AST_CALL`):**
    *   Cria um nó `CFG_NODE_FUNCTION_CALL` com um rótulo descrevendo a chamada (e.g., "Call: printf(...)").
    *   Este nó é tanto a entrada quanto a saída do fragmento.

5.  **Nós de Retorno (`AST_RETURN`):**
    *   Cria um nó `CFG_NODE_RETURN` com o rótulo "Return".
    *   Este nó é tanto a entrada quanto a saída do fragmento.

6.  **Nós Condicionais (`AST_IF`, `AST_IF_ELSE`):**
    *   Cria um nó `CFG_NODE_CONDITION` para a expressão condicional (`node->filho1`). Este é o ponto de entrada do fragmento.
    *   Chama recursivamente `build_cfg_from_ast` para o bloco `then` (`node->filho2`).
    *   Conecta o nó de condição ao ponto de entrada do fragmento `then` com uma aresta rotulada "True".
    *   Cria um nó `CFG_NODE_JOIN` que será o ponto de saída do fragmento.
    *   Conecta o ponto de saída do fragmento `then` ao nó de `join`.
    *   Se houver um bloco `else` (`node->filho3`):
        *   Chama recursivamente `build_cfg_from_ast` para o bloco `else`.
        *   Conecta o nó de condição ao ponto de entrada do fragmento `else` com uma aresta rotulada "False".
        *   Conecta o ponto de saída do fragmento `else` ao nó de `join`.
    *   Se não houver bloco `else`:
        *   Conecta o nó de condição diretamente ao nó de `join` com uma aresta rotulada "False".

7.  **Nós de Loop (`AST_WHILE`, `AST_FOR`, `AST_DO_WHILE`):**
    *   **`AST_WHILE`**: `WHILE (cond) body`
        *   Cria um `CFG_NODE_LOOP_ENTRY` (ponto de entrada do fragmento).
        *   Cria um `CFG_NODE_CONDITION` para a condição (`node->filho1`).
        *   Cria um `CFG_NODE_LOOP_EXIT` (ponto de saída do fragmento).
        *   Conecta `LOOP_ENTRY` a `CONDITION`.
        *   Chama recursivamente `build_cfg_from_ast` para o corpo do loop (`node->filho2`).
        *   Conecta `CONDITION` à entrada do corpo com aresta "True".
        *   Conecta a saída do corpo de volta a `LOOP_ENTRY` (ou diretamente a `CONDITION`, dependendo da preferência de visualização do loop).
        *   Conecta `CONDITION` a `LOOP_EXIT` com aresta "False".
    *   **`AST_FOR`**: `FOR (init; cond; increment) body`
        *   Cria um `CFG_NODE_STATEMENT` para a inicialização (`node->filho1`). Este é o ponto de entrada do fragmento.
        *   Cria um `CFG_NODE_LOOP_ENTRY`.
        *   Cria um `CFG_NODE_CONDITION` para a condição (`node->filho2`).
        *   Cria um `CFG_NODE_STATEMENT` para o incremento (`node->filho3`).
        *   Cria um `CFG_NODE_LOOP_EXIT` (ponto de saída do fragmento).
        *   Conecta `INIT` a `LOOP_ENTRY`.
        *   Conecta `LOOP_ENTRY` a `CONDITION`.
        *   Chama recursivamente `build_cfg_from_ast` para o corpo do loop (`node->filho4`).
        *   Conecta `CONDITION` à entrada do corpo com aresta "True".
        *   Conecta a saída do corpo ao nó de `INCREMENT`.
        *   Conecta `INCREMENT` de volta a `LOOP_ENTRY` (ou `CONDITION`).
        *   Conecta `CONDITION` a `LOOP_EXIT` com aresta "False".
    *   **`AST_DO_WHILE`**: `DO body WHILE (cond)`
        *   Cria um `CFG_NODE_LOOP_ENTRY` (ponto de entrada do fragmento).
        *   Chama recursivamente `build_cfg_from_ast` para o corpo do loop (`node->filho2`).
        *   Cria um `CFG_NODE_CONDITION` para a condição (`node->filho1`).
        *   Cria um `CFG_NODE_LOOP_EXIT` (ponto de saída do fragmento).
        *   Conecta `LOOP_ENTRY` à entrada do corpo.
        *   Conecta a saída do corpo a `CONDITION`.
        *   Conecta `CONDITION` de volta a `LOOP_ENTRY` (ou à entrada do corpo) com aresta "True".
        *   Conecta `CONDITION` a `LOOP_EXIT` com aresta "False".

8.  **Nós de `break` e `continue` (`AST_BREAK`, `AST_CONTINUE`):**
    *   Cria nós `CFG_NODE_BREAK` ou `CFG_NODE_CONTINUE`.
    *   A conexão desses nós aos seus alvos corretos (saída do loop/switch para `break`, início da próxima iteração para `continue`) é mais complexa e geralmente requer informações de contexto sobre os loops ou switches envolventes. Isso pode ser gerenciado passando ponteiros para os nós de `LOOP_EXIT` (para `break`) e `LOOP_ENTRY` ou `INCREMENT` (para `continue`) durante a construção recursiva do CFG do corpo do loop.
    *   Na implementação atual, eles são criados como nós terminais, e a conexão precisa ser feita em uma passagem posterior ou por um mecanismo de empilhamento de alvos de `break`/`continue`.

9.  **Nós de Declaração de Função (`AST_FUNC_DECL`):**
    *   Cria um `CFG_NODE_ENTRY` para a função, com o nome da função como rótulo.
    *   Chama recursivamente `build_cfg_from_ast` para o corpo da função (`node->filho3`).
    *   Conecta o `CFG_NODE_ENTRY` da função à entrada do CFG do corpo da função.
    *   O ponto de saída do fragmento da função é o ponto de saída do CFG do corpo. Se o corpo for vazio ou não tiver um `return` explícito, um `CFG_NODE_EXIT` implícito pode ser necessário.

10. **Outros Nós (Expressões, Tipos, etc.):**
    *   Muitos nós da AST (e.g., literais, variáveis, operadores binários, tipos) não representam diretamente instruções de controle de fluxo. Eles são geralmente incorporados nos rótulos dos nós `CFG_NODE_STATEMENT` ou `CFG_NODE_CONDITION` que os contêm.
    *   Se encontrados isoladamente (o que pode indicar uma expressão como uma instrução, e.g., `x + 1;`), podem ser tratados como um `CFG_NODE_STATEMENT` com um rótulo apropriado.
    *   Nós `AST_EMPTY` (instrução vazia `;`) podem ser representados por um nó `CFG_NODE_STATEMENT` com rótulo "EMPTY_STMT" ou simplesmente ignorados, conectando o nó anterior ao próximo.

### 4.2. Gerenciamento de Nós e Arestas

*   **`criarCFGNode(...)`**: Função auxiliar para alocar e inicializar um novo `CFGNode`. Cada nó recebe um `id` único (`cfg_node_counter++`) e é adicionado à lista global `cfg_nodes_head` para facilitar a liberação de memória e a geração do DOT.
*   **`add_cfg_edge(from, to, label)`**: Função auxiliar para criar uma nova `CFGEdge` e adicioná-la à lista de arestas de saída do nó `from`.
*   **`liberarCFG()`**: Libera toda a memória alocada para os nós e arestas do CFG, percorrendo a lista `cfg_nodes_head`.

### 4.3. Geração do Arquivo DOT (`cfg_to_dot(AST *node)`)

1.  Abre um arquivo `cfg.dot` para escrita.
2.  Escreve o cabeçalho do grafo DOT (`digraph CFG { ... }`).
3.  Chama `liberarCFG()` para limpar qualquer CFG anterior e reinicia `cfg_node_counter`.
4.  Chama `build_cfg_from_ast(node)` para construir o CFG a partir da raiz da AST.
5.  Itera sobre a lista global `cfg_nodes_head`:
    *   Para cada `CFGNode`, escreve sua definição no formato DOT, incluindo `id`, `label`, `shape` e `color` (determinados pelo `CFGNodeType`).
    *   Para cada `CFGEdge` de saída do nó atual, escreve a definição da aresta no formato DOT, conectando `node<id_from> -> node<id_to>` com o `label` da aresta.
6.  Escreve o fechamento do grafo DOT (`}`).
7.  Fecha o arquivo.

## 5. Visualização com Graphviz

O arquivo `cfg.dot` gerado pode ser processado pela ferramenta `dot` do Graphviz para criar uma imagem visual do fluxograma:

```bash
dot -Tpng cfg.dot -o cfg.png
```

Isso produzirá um arquivo `cfg.png` que pode ser visualizado. Os diferentes `shapes` e `colors` atribuídos aos `CFGNodeType`s ajudam a distinguir visualmente os diferentes tipos de elementos de controle de fluxo.

## 6. Desafios e Melhorias Futuras

*   **Tratamento de `goto`**: A instrução `goto` introduz arestas arbitrárias no CFG, o que pode tornar sua construção e análise mais complexas. Atualmente, não é explicitamente tratada.
*   **Tratamento de `switch`**: A estrutura `switch` pode ser complexa de modelar com precisão, especialmente com `case`s que caem para o próximo (`fall-through`) e `default` labels. A implementação atual precisaria ser expandida para lidar com `AST_SWITCH` e `AST_CASE` de forma robusta.
*   **Precisão do Fluxo de Controle para `break` e `continue`**: A implementação atual cria nós para `break` e `continue`, mas a conexão exata ao ponto de saída do loop/switch ou ao início da próxima iteração requer um mecanismo mais sofisticado de rastreamento de contexto (e.g., uma pilha de alvos de `break`/`continue` durante a travessia da AST).
*   **CFG Interprocedural**: A geração atual é intraprocedural (um CFG por função). Um CFG interprocedural conectaria os nós `CFG_NODE_FUNCTION_CALL` aos `CFG_NODE_ENTRY` das funções chamadas e os `CFG_NODE_RETURN` de volta aos locais de chamada.
*   **Otimizações e Simplificações**: O CFG gerado pode conter nós redundantes ou ser mais detalhado do que o necessário para certas análises. Técnicas de simplificação poderiam ser aplicadas.
*   **Mapeamento para Código Fonte**: Melhorar a ligação entre os nós do CFG e as linhas específicas do código-fonte original (usando `ast_node_ref->linha`) para facilitar a depuração.

Este design fornece uma base sólida para a geração de fluxogramas de execução. A implementação em `ast.c` reflete a maior parte desta lógica, com espaço para refinamentos e extensões futuras.

