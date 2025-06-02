CC = gcc
CFLAGS = -Wall -I./parser -I./ast -I./semantic

# Arquivos fonte
PARSER_SRC = parser/exemplo.tab.c parser/yyerror.c
LEXER_SRC = lexer/lex.yy.c
AST_SRC = ast/ast.c
SEMANTIC_SRC = semantic/semantic.c
SYMBOL_SRC = simbolos.c

# Arquivos objeto
PARSER_OBJ = parser/exemplo.tab.o parser/yyerror.o
LEXER_OBJ = lexer/lex.yy.o
AST_OBJ = ast/ast.o
SEMANTIC_OBJ = semantic/semantic.o
SYMBOL_OBJ = simbolos.o

# Executável principal
MAIN = exemplo

# Executável de teste para análise semântica
TEST_SEMANTIC = test_semantic

# Diretórios de teste e visualização
TEST_DIR = tests
VISUALIZATION_DIR = visualization

# Caminhos absolutos para scripts
RUN_TESTS_SCRIPT = $(CURDIR)/run_tests.sh
VISUALIZE_SCRIPT = $(CURDIR)/visualize.sh

all: $(MAIN)

$(MAIN): $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

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

# Verifica se o Graphviz está instalado
check-graphviz:
	@which dot > /dev/null || (echo "Graphviz não está instalado. Instale com: sudo apt-get install graphviz" && exit 1)

# Limpa arquivos gerados
clean:
	rm -f $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ) $(SYMBOL_OBJ) $(MAIN) $(TEST_SEMANTIC)
	rm -f parser/exemplo.tab.c parser/exemplo.tab.h lexer/lex.yy.c
	rm -rf $(VISUALIZATION_DIR)

# Limpa e reconstrói tudo
rebuild: clean all

.PHONY: all clean test visualize check-graphviz rebuild
