#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char* yytext;

// Implementação da função yyerror com informações de linha e contexto
void yyerror(const char *s) {
    // Mensagens específicas para construções não suportadas
    if (strstr(s, "syntax error") != NULL) {
        // Verificar por construções específicas não suportadas
        if (strstr(yytext, "[") != NULL) {
            fprintf(stderr, "Erro na linha %d: Arrays não são completamente suportados nesta versão do compilador\n", yylineno);
        } 
        else if (strstr(s, "near") != NULL && strstr(s, "#include") != NULL) {
            fprintf(stderr, "Erro na linha %d: Diretivas de pré-processador não são suportadas nesta versão do compilador\n", yylineno);
        }
        else if (strstr(yytext, "*") != NULL && (yytext[0] == '*' || strchr(yytext, '&') != NULL)) {
            fprintf(stderr, "Erro na linha %d: Operações com ponteiros não são completamente suportadas nesta versão do compilador\n", yylineno);
        }
        else {
            // Mensagem genérica com linha
            fprintf(stderr, "Erro sintático na linha %d: %s (próximo a '%s')\n", yylineno, s, yytext);
        }
    } else {
        // Outros erros
        fprintf(stderr, "Erro na linha %d: %s\n", yylineno, s);
    }
}
