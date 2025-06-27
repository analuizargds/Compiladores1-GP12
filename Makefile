CC = gcc
CFLAGS = -Wall -I./parser -I./ast -I./semantic

# Arquivos fonte
PARSER_SRC = parser/exemplo.tab.c parser/yyerror.c
LEXER_SRC = lexer/lex.yy.c
AST_SRC = ast/ast.c
MAIN_SRC = src/main.c
SEMANTIC_SRC = semantic/semantic.c
SYMBOL_SRC = simbolos.c

# Arquivos objeto
PARSER_OBJ = parser/exemplo.tab.o parser/yyerror.o
LEXER_OBJ = lexer/lex.yy.o
AST_OBJ = ast/ast.o
MAIN_OBJ = src/main.o
SEMANTIC_OBJ = semantic/semantic.o
SYMBOL_OBJ = simbolos.o
OBJECTS = $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ) $(MAIN_OBJ)

# Executável principal
MAIN = CtoMMD

# Executável de teste para análise semântica
TEST_SEMANTIC = test_semantic

# Diretórios de teste e visualização
TEST_DIR = tests
VISUALIZATION_DIR = visualization

# Caminhos absolutos para scripts
RUN_TESTS_SCRIPT = $(CURDIR)/run_tests.sh
VISUALIZE_SCRIPT = $(CURDIR)/visualize.sh

all: $(MAIN)

$(MAIN): $(PARSER_OBJ) $(LEXER_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ) $(MAIN_OBJ) $(AST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(PARSER_OBJ) $(LEXER_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ) $(MAIN_OBJ) $(AST_OBJ) -lfl

parser/exemplo.tab.o: parser/exemplo.tab.c
	$(CC) $(CFLAGS) -c -o $@ $<

parser/yyerror.o: parser/yyerror.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LEXER_OBJ): $(LEXER_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(AST_OBJ): $(AST_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SEMANTIC_OBJ): $(SEMANTIC_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SYMBOL_OBJ): $(SYMBOL_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TEST_SEMANTIC): semantic/test_semantic.c $(SEMANTIC_OBJ) $(AST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

parser/exemplo.tab.c parser/exemplo.tab.h: parser/exemplo.y
	cd parser && bison -d exemplo.y

lexer/lex.yy.c: lexer/exemplo.l parser/exemplo.tab.h
	cd lexer && flex exemplo.l

# Regras para testes e visualização
test: $(MAIN)
	@echo "Executando testes automatizados..."
	@echo "Verificando existência do script: $(RUN_TESTS_SCRIPT)"
	@if [ ! -f "$(RUN_TESTS_SCRIPT)" ]; then \
		echo "ERRO: Script de testes não encontrado em: $(RUN_TESTS_SCRIPT)"; \
		echo "Diretório atual: $(CURDIR)"; \
		echo "Listando arquivos:"; \
		ls -la; \
		exit 1; \
	fi
	@echo "Definindo permissões de execução para: $(RUN_TESTS_SCRIPT)"
	@chmod +x "$(RUN_TESTS_SCRIPT)"
	@echo "Executando: $(RUN_TESTS_SCRIPT)"
	@bash "$(RUN_TESTS_SCRIPT)"

visualize: $(MAIN)
	@echo "Gerando visualizações da AST e tabela de símbolos..."
	@echo "Verificando existência do script: $(VISUALIZE_SCRIPT)"
	@if [ ! -f "$(VISUALIZE_SCRIPT)" ]; then \
		echo "ERRO: Script de visualização não encontrado em: $(VISUALIZE_SCRIPT)"; \
		echo "Diretório atual: $(CURDIR)"; \
		echo "Listando arquivos:"; \
		ls -la; \
		exit 1; \
	fi
	@mkdir -p $(VISUALIZATION_DIR)
	@echo "Definindo permissões de execução para: $(VISUALIZE_SCRIPT)"
	@chmod +x "$(VISUALIZE_SCRIPT)"
	@echo "Executando: $(VISUALIZE_SCRIPT)"
	@bash "$(VISUALIZE_SCRIPT)"

# Limpa arquivos gerados
clean:
	rm -f $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ) $(MAIN) $(TEST_SEMANTIC)
	rm -f parser/exemplo.tab.c parser/exemplo.tab.h lexer/lex.yy.c
	rm -rf $(VISUALIZATION_DIR)

# Limpa arquivos de imagem gerados
cleanImg:
	@echo "Removendo arquivos de imagem gerados..."
	rm -f *.png *.pdf *.svg cfg.mmd

# Limpa todos os arquivos gerados
cleanAll: clean cleanImg
	@echo "Todos os arquivos gerados foram removidos."

# Compila e gera fluxograma em PNG
compPng: $(MAIN)
	@echo "Compilando código C e gerando fluxograma em PNG..."
	@if [ -z "$(ARQUIVO)" ]; then \
		echo "ERRO: Especifique o arquivo C usando ARQUIVO=nome_do_arquivo.c"; \
		echo "Exemplo: make compPng ARQUIVO=entrada.c"; \
		exit 1; \
	fi
	@if [ ! -f "$(ARQUIVO)" ]; then \
		echo "ERRO: Arquivo $(ARQUIVO) não encontrado"; \
		exit 1; \
	fi
	@echo "Processando arquivo: $(ARQUIVO)"
	./$(MAIN) $(ARQUIVO)
	@if [ ! -f "cfg.mmd" ]; then \
		echo "ERRO: Arquivo cfg.mmd não foi gerado"; \
		exit 1; \
	fi
	@echo "Verificando se Mermaid CLI está instalado..."
	@which mmdc > /dev/null || (echo "ERRO: Mermaid CLI não encontrado. Instale com: npm install -g @mermaid-js/mermaid-cli" && exit 1)
	@echo "Convertendo para PNG..."
	mmdc -i cfg.mmd -o fluxograma.png
	@echo "✅ Fluxograma gerado com sucesso: fluxograma.png"

# Compila e gera fluxograma em PDF
compPdf: $(MAIN)
	@echo "Compilando código C e gerando fluxograma em PDF..."
	@if [ -z "$(ARQUIVO)" ]; then \
		echo "ERRO: Especifique o arquivo C usando ARQUIVO=nome_do_arquivo.c"; \
		echo "Exemplo: make compPdf ARQUIVO=entrada.c"; \
		exit 1; \
	fi
	@if [ ! -f "$(ARQUIVO)" ]; then \
		echo "ERRO: Arquivo $(ARQUIVO) não encontrado"; \
		exit 1; \
	fi
	@echo "Processando arquivo: $(ARQUIVO)"
	./$(MAIN) $(ARQUIVO)
	@if [ ! -f "cfg.mmd" ]; then \
		echo "ERRO: Arquivo cfg.mmd não foi gerado"; \
		exit 1; \
	fi
	@echo "Verificando se Mermaid CLI está instalado..."
	@which mmdc > /dev/null || (echo "ERRO: Mermaid CLI não encontrado. Instale com: npm install -g @mermaid-js/mermaid-cli" && exit 1)
	@echo "Convertendo para PDF..."
	mmdc -i cfg.mmd -o fluxograma.pdf
	@echo "✅ Fluxograma gerado com sucesso: fluxograma.pdf"

# Limpa e reconstrói tudo
rebuild: clean all

.PHONY: all clean cleanImg cleanAll compPng compPdf test visualize rebuild


$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<


