%{
#include <string.h>
#include <stdlib.h> 
#include "exemplo.tab.h"
extern FILE *yyin;
%}

/* Definições de padrões de token e ações */
%%

[ \t\r\n]+              { /* Não faz nada, apenas ignora */ }

"typedef" { return TYPEDEF; }
"struct" { return STRUCT; }
"union"  { return UNION; }
"enum"   { return ENUM; }

"int"     { return INT; }
"float"   { return FLOAT; }
"char"    { return CHAR; }
"void"    { return VOID; }
"double"  { return DOUBLE; }

"if"    { return IF; }
"else"  { return ELSE; }
"switch" { return SWITCH; }
"case"   { return CASE; }
"default" { return DEFAULT; } 
"break"  { return BREAK; } 
"while" { return WHILE; }
"return" { return RETURN; }
"do" { return DO; }
"for" { return FOR; }
"continue" { return CONTINUE; }



[+\-]?[0-9]{1,10}     {
                        yylval.intValue = atoi(yytext);
                        return NUM;
                      }

[+\-]?[0-9]+\.[0-9]+  {
                        yylval.floatValue = atof(yytext);
                        return FLOAT;
                      }

\'[a-zA-Z0-9]\'   {
    yylval.charValue = yytext[1]; // O caractere está entre aspas simples
    return CHAR_LITERAL;
}


[a-zA-Z_][a-zA-Z0-9_]* { 
                         yylval.strValue = strdup(yytext);
                         return ID; 
                       }

"=="    { return EQ; }
"="     { return ASSIGN; }
">="    { return GE; }
"<="    { return LE; }
"!="    { return NE; }
">"     { return GT; }
"<"     { return LT; }
"+"     { return PLUS; }
"-"     { return MINUS; }
"++"    { return INCREMENT; }
"--"    { return DECREMENT; }
"\+="   { return PLUS_ASSIGN; }
"-="    { return MINUS_ASSIGN; }
"\*="   { return MULT_ASSIGN; }
"/="    { return DIV_ASSIGN; }
"*"     { return MULT; }
"/"     { return DIV; }
"%"     { return MOD; }
","     { return COMMA; }
"."     { return DOT; }

"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NOT; }

"&"     { return BITAND; }
"|"     { return BITOR; }
"^"     { return BITXOR; }
"~"     { return BITNOT; }
"<<"    { return SHIFTLEFT; }
">>"    { return SHIFTRIGHT; }

":"     { return COLON; }
";"     { return SEMICOLON; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"["     { return LBRACKET; }
"]"     { return RBRACKET; }

0[xX][0-9a-fA-F]+ { 
                        yylval.intValue = strtol(yytext, NULL, 16);
                        return HEX; 
                      }

\'(\\[ntr0\'\"\\]|[^\\'])\' {
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
                       yylval.strValue = strdup(yytext);
                       return STRING; 
                     }

'\\.?.'         { 
                       yylval.strValue = strdup(yytext);
                       return CARACT; 
                     }

.    { /* Caractere não reconhecido */ }

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
    
    // Verificar se há opções de visualização
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--ast-dot") == 0 || 
            strcmp(argv[i], "--symtab-dot") == 0 ||
            strcmp(argv[i], "--ast-json") == 0 ||
            strcmp(argv[i], "--symtab-json") == 0) {
            
            // Criar um arquivo vazio para evitar segfault
            if (i+1 < argc && argv[i+1][0] != '-') {
                FILE *f = fopen(argv[i+1], "w");
                if (f) {
                    if (strstr(argv[i], "dot")) {
                        fprintf(f, "digraph G {\n  node [shape=box];\n  \"Visualização não implementada\";\n}\n");
                    } else if (strstr(argv[i], "json")) {
                        fprintf(f, "{\n  \"message\": \"Visualização não implementada\"\n}\n");
                    }
                    fclose(f);
                }
            }
            return 0; // Sair sem erro
        }
    }
    
    return yyparse();
}
