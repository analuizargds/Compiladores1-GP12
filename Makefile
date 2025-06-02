CC = gcc
CFLAGS = -Wall -I./parser -I./ast -I./semantic

# Arquivos fonte
PARSER_SRC = parser/exemplo.tab.c parser/yyerror.c
LEXER_SRC = lexer/lex.yy.c
AST_SRC = ast/ast.c
SEMANTIC_SRC = semantic/semantic.c

# Arquivos objeto
PARSER_OBJ = parser/exemplo.tab.o parser/yyerror.o
LEXER_OBJ = lexer/lex.yy.o
AST_OBJ = ast/ast.o
SEMANTIC_OBJ = semantic/semantic.o

# Executável principal
MAIN = exemplo

# Executável de teste para análise semântica
TEST_SEMANTIC = test_semantic

all: $(MAIN)

$(MAIN): $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ)
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

$(TEST_SEMANTIC): semantic/test_semantic.c $(SEMANTIC_OBJ) $(AST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

parser/exemplo.tab.c parser/exemplo.tab.h: parser/exemplo.y
	cd parser && bison -d exemplo.y

lexer/lex.yy.c: lexer/exemplo.l parser/exemplo.tab.h
	cd lexer && flex exemplo.l

test: $(TEST_SEMANTIC)
	./$(TEST_SEMANTIC)

clean:
	rm -f $(PARSER_OBJ) $(LEXER_OBJ) $(AST_OBJ) $(SEMANTIC_OBJ) $(MAIN) $(TEST_SEMANTIC)
	rm -f parser/exemplo.tab.c parser/exemplo.tab.h lexer/lex.yy.c

.PHONY: all clean test
