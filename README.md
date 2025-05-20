# Compiladores

## Introdução

Este repositório é destinado ao projeto da Disciplina Compiladores 1 da UnB-FCTE. Aqui você encontrará o objetivo, como executar o projeto e os colaboradores.

## Objetivo

Construir um compilador que traduzirá o código de c para DOT utilizando as ferramentas Bison e Flex para análise sintática e léxica, respectivamente.

## Como Executar

#### Estrutura do Projeto

- **parser/:** Contém os arquivos relacionados à análise sintática, incluindo a gramática definida em exemplo.y.
- **lexer/:** Contém os arquivos relacionados à análise léxica, incluindo os padrões de tokens definidos em exemplo.l.
- **src/:** Diretório reservado para o código principal do projeto.
- **entrada.c:** Exemplo de entrada em C para ser processado pelo compilador.
- **teste.c:** Outro exemplo de entrada em C.

#### Pré-Requisitos

Certifique-se de ter as seguintes ferramentas instaladas no seu sistema:

- Bison
- Flex
- GCC

#### Como Executar o Projeto

**1 -** Navegue até o diretório parser e gere os arquivos do Bison:

```
cd parser
bison -d exemplo.y
```

**2 -** Navegue até o diretório lexer e gere os arquivos do Flex:

```
cd ../lexer
flex exemplo.l
```

**3 -** Volte para o diretório raiz e compile o projeto usando o GCC:

```
cd ..
gcc -o exemplo -I./parser ./parser/exemplo.tab.c ./lexer/lex.yy.c -lfl
```

**4 -** Execute o compilador passando um arquivo de entrada em C:

```
./exemplo <arquivo de entrada>
```

#### Como Executar Testes

```
cd tests
gcc -Wall -Wextra -g -I.. teste_interativo.c ../simbolos.c -o teste_interativo
```

substituir teste_interativo.c pelo arquivo desejado

## Colaboradores - Grupo 12

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