%option yylineno
%{
#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include "exemplo.tab.h"
#include "../ast/ast.h"
extern FILE *yyin;
extern ASTNode* root;
%}

%option noyywrap
%option noinput


/* Definições de padrões de token e ações */
%%
\n { /* yylineno é incrementado automaticamente */ }
[ \t\r]+              { /* Não faz nada, apenas ignora */ }
"//".*                { /* ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/"    { /* ignora comentários de bloco */ }

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

\"([^\"]|\\.)*\" { 
                        yylval.strValue = strdup(yytext);
                        return STRING; 
                      }

\'(.)\' { 
    if (yytext[1] == '\\') {
        // caracteres de escape
        switch (yytext[2]) {
            case 'n': yylval.charValue = '\n'; break;
            case 't': yylval.charValue = '\t'; break;
            case 'r': yylval.charValue = '\r'; break;
            case '0': yylval.charValue = '\0'; break;
            case '\'': yylval.charValue = '\''; break;
            case '"': yylval.charValue = '"'; break;
            case '\\': yylval.charValue = '\\'; break;
            default: yylval.charValue = yytext[2]; break; // Should not happen
        }
    } else {
        yylval.charValue = yytext[1]; // O caractere está entre aspas simples
    }
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
"%="    { return MOD_ASSIGN; }
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

"?"     { return QUESTION; }
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

. { /* Ignorar outros caracteres */ }

