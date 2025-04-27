%{
#include <string.h>
#include <stdlib.h> 
#include "exemplo.tab.h"
extern FILE *yyin;
%}

/* Definições de padrões de token e ações */
%%

[ \t\n]+              { /* Não faz nada, apenas ignora */ }

[+\-]?[0-9]{1,10}     {
                        printf("Reconhecido: NUM (%s)\n", yytext);
                        yylval.intValue = atoi(yytext);
                        return NUM;
                      }

"int"     { printf("Reconhecido: INT\n"); return INT; }
"float"   { printf("Reconhecido: FLOAT\n"); return FLOAT; }
"char"    { printf("Reconhecido: CHAR\n"); return CHAR; }
"void"    { printf("Reconhecido: VOID\n"); return VOID; }
"double"  { printf("Reconhecido: DOUBLE\n"); return DOUBLE; }

[+\-]?[0-9]{1,10}     {
                        printf("Reconhecido: NUM (%s)\n", yytext);
                        yylval.intValue = atoi(yytext);
                        return NUM;
                      }

"if"    { printf("Reconhecido: IF\n"); return IF; }
"else"  { printf("Reconhecido: ELSE\n"); return ELSE; }
"switch" { printf("Reconhecido: SWITCH\n"); return SWITCH; }
"case"   { printf("Reconhecido: CASE\n"); return CASE; }
"default" { printf("Reconhecido: DEFAULT\n"); return DEFAULT; } 
"break"  { printf("Reconhecido: BREAK\n"); return BREAK; } 
"while" { printf("Reconhecido: WHILE\n"); return WHILE; }
"return" { printf("Reconhecido: RETURN\n"); return RETURN; }

[a-zA-Z_][a-zA-Z0-9_]* { 
                         printf("Reconhecido: ID (%s)\n", yytext);
                         yylval.strValue = strdup(yytext);
                         return ID; 
                       }

"=="    { printf("Reconhecido: EQ\n"); return EQ; }
"="     { printf("Reconhecido: ASSIGN\n"); return ASSIGN; }
"+"     { printf("Reconhecido: PLUS\n"); return PLUS; }
"-"     { printf("Reconhecido: MINUS\n"); return MINUS; }
"*"     { printf("Reconhecido: MULT\n"); return MULT; }
"/"     { printf("Reconhecido: DIV\n"); return DIV; }

":"     { printf("Reconhecido: COLON\n"); return COLON; }
";"     { printf("Reconhecido: SEMICOLON\n"); return SEMICOLON; }
"{"     { printf("Reconhecido: LBRACE\n"); return LBRACE; }
"}"     { printf("Reconhecido: RBRACE\n"); return RBRACE; }
"("     { printf("Reconhecido: LPAREN\n"); return LPAREN; }
")"     { printf("Reconhecido: RPAREN\n"); return RPAREN; }

\"[^\"]*\"           { 
                       printf("Reconhecido: STRING (%s)\n", yytext);
                       yylval.strValue = strdup(yytext);
                       return STRING; 
                     }

.    { printf("Caractere não reconhecido: %s\n", yytext); }

%%

/* Função auxiliar do Flex (quando termina o arquivo de entrada) */
int yywrap(void) {
    return 1;
}

/* Função principal: chamará o parser ao ser executado */
int main(int argc, char **argv) {
    /* Se houver arquivo de entrada como parâmetro, redireciona o yyin */
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) {
            yyin = f;
        } else {
            fprintf(stderr, "Não foi possível abrir o arquivo: %s\n", argv[1]);
            return 1;
        }
    }
    return yyparse();
}
