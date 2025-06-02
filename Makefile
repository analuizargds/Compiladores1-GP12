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
	@chmod +x run_tests.sh
	@./run_tests.sh

visualize: $(MAIN)
	@echo "Gerando visualizações da AST e tabela de símbolos..."
	@mkdir -p $(VISUALIZATION_DIR)
	@chmod +x visualize.sh
	@./visualize.sh

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
