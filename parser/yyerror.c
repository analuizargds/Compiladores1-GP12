#include <stdio.h>

// Implementação da função yyerror
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}
