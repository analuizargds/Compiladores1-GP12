%{
#include <string.h>
#include <stdlib.h> 
#include "exemplo.tab.h"
extern FILE *yyin;
%}

/* Definições de padrões de token e ações */
%%

[ \t\r\n]+              { /* Não faz nada, apenas ignora */ }

"typedef" { printf("Reconhecido: TYPEDEF\n"); return TYPEDEF; }
"struct" { printf("Reconhecido: STRUCT\n"); return STRUCT; }
"union"  { printf("Reconhecido: UNION\n"); return UNION; }
"enum"   { printf("Reconhecido: ENUM\n"); return ENUM; }

"int"     { printf("Reconhecido: INT\n"); return INT; }
"float"   { printf("Reconhecido: FLOAT\n"); return FLOAT; }
"char"    { printf("Reconhecido: CHAR\n"); return CHAR; }
"void"    { printf("Reconhecido: VOID\n"); return VOID; }
"double"  { printf("Reconhecido: DOUBLE\n"); return DOUBLE; }

"if"    { printf("Reconhecido: IF\n"); return IF; }
"else"  { printf("Reconhecido: ELSE\n"); return ELSE; }
"switch" { printf("Reconhecido: SWITCH\n"); return SWITCH; }
"case"   { printf("Reconhecido: CASE\n"); return CASE; }
"default" { printf("Reconhecido: DEFAULT\n"); return DEFAULT; } 
"break"  { printf("Reconhecido: BREAK\n"); return BREAK; } 
"while" { printf("Reconhecido: WHILE\n"); return WHILE; }
"return" { printf("Reconhecido: RETURN\n"); return RETURN; }
"do" { printf("Reconhecido: DO\n"); return DO; }
"for" { printf("Reconhecido: FOR\n"); return FOR; }
"continue" { printf("Reconhecido: CONTINUE\n"); return CONTINUE; }



[+\-]?[0-9]{1,10}     {
                        printf("Reconhecido: NUM (%s)\n", yytext);
                        yylval.intValue = atoi(yytext);
                        return NUM;
                      }

[+\-]?[0-9]+\.[0-9]+  {
                        printf("Reconhecido: FLOAT (%s)\n", yytext);
                        yylval.floatValue = atof(yytext);
                        return FLOAT;
                      }

\'[a-zA-Z0-9]\'   {
    printf("Reconhecido: CHAR_LITERAL (%s)\n", yytext);
    yylval.charValue = yytext[1]; // O caractere está entre aspas simples
    return CHAR_LITERAL;
}


[a-zA-Z_][a-zA-Z0-9_]* { 
                         printf("Reconhecido: ID (%s)\n", yytext);
                         yylval.strValue = strdup(yytext);
                         return ID; 
                       }

"=="    { printf("Reconhecido: EQ\n"); return EQ; }
"="     { printf("Reconhecido: ASSIGN\n"); return ASSIGN; }
">="     { printf("Reconhecido: GE\n"); return GE; }
"<="     { printf("Reconhecido: LE\n"); return LE; }
">"     { printf("Reconhecido: GT\n"); return GT; }
"<"     { printf("Reconhecido: LT\n"); return LT; }
"+"     { printf("Reconhecido: PLUS\n"); return PLUS; }
"-"     { printf("Reconhecido: MINUS\n"); return MINUS; }
"*"     { printf("Reconhecido: MULT\n"); return MULT; }
"/"     { printf("Reconhecido: DIV\n"); return DIV; }
","     { printf("Reconhecido: COMMA\n"); return COMMA; }
"."     { printf("Reconhecido: DOT\n"); return DOT; }

":"     { printf("Reconhecido: COLON\n"); return COLON; }
";"     { printf("Reconhecido: SEMICOLON\n"); return SEMICOLON; }
"{"     { printf("Reconhecido: LBRACE\n"); return LBRACE; }
"}"     { printf("Reconhecido: RBRACE\n"); return RBRACE; }
"("     { printf("Reconhecido: LPAREN\n"); return LPAREN; }
")"     { printf("Reconhecido: RPAREN\n"); return RPAREN; }

0[xX][0-9a-fA-F]+ { 
                        printf("Reconhecido: HEX (%s)\n", yytext);
                        yylval.intValue = strtol(yytext, NULL, 16);
                        return HEX; 
                      }

\'(\\[ntr0\'\"\\]|[^\\'])\' {
    printf("Reconhecido: CHAR_LITERAL (%s)\n", yytext);
    if (yytext[1] == '\\') {
        // caracteres de escape
        switch (yytext[2]) {
            case 'n': yylval.charValue = '\n'; break;
            case 't': yylval.charValue = '\t'; break;
            case 'r': yylval.charValue = '\r'; break;
            case '0': yylval.charValue = '\0'; break;
            case '\'': yylval.charValue = '\''; break;
            case '\"': yylval.charValue = '\"'; break;
            case '\\': yylval.charValue = '\\'; break;
            default: yylval.charValue = yytext[2]; break;
        }
    } else {
        // caracteres simples
        yylval.charValue = yytext[1];
    }
    return CHAR_LITERAL;
}

\"[^\"]*\"           { 
                       printf("Reconhecido: STRING (%s)\n", yytext);
                       yylval.strValue = strdup(yytext);
                       return STRING; 
                     }

'\\.?.'         { 
                       printf("Reconhecido: CARACT (%s)\n", yytext);
                       yylval.strValue = strdup(yytext);
                       return CARACT; 
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