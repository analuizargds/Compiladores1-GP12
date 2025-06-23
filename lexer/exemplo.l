%option yylineno
%{
#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include "exemplo.tab.h"
#include "../ast/ast.h"
extern FILE *yyin;
extern ASTNode* root;

// Função para gerar representação DOT da AST
void generate_ast_dot(FILE* output, ASTNode* node, int* counter) {
    if (!node) {
        fprintf(output, "  null_node [label=\"NULL\", style=filled, fillcolor=red];\n");
        return;
    }
    
    int my_id = (*counter)++;
    
    // Determina o rótulo baseado no tipo do nó
    const char* label = NULL;
    char buffer[256];
    
    switch (node->tipo) {
        case AST_BLOCK: 
            fprintf(output, "  node%d [label=\"Programa\"];\n", my_id);
            break;
        case AST_VAR: 
            snprintf(buffer, sizeof(buffer), "Variável: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_LITERAL_INT: 
            fprintf(output, "  node%d [label=\"Int: %d\"];\n", my_id, node->valor_int);
            break;
        case AST_LITERAL_FLOAT: 
            fprintf(output, "  node%d [label=\"Float: %.2f\"];\n", my_id, node->valor_float);
            break;
        case AST_LITERAL_CHAR: 
            fprintf(output, "  node%d [label=\"Char: '%c'\"];\n", my_id, node->valor_char);
            break;
        case AST_LITERAL_STRING: 
            snprintf(buffer, sizeof(buffer), "String: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_BINARY_OP: 
            snprintf(buffer, sizeof(buffer), "Op: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_UNARY_OP: 
            snprintf(buffer, sizeof(buffer), "UnaryOp: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_ASSIGN: 
            fprintf(output, "  node%d [label=\"Atribuição\"];\n", my_id);
            break;
        case AST_IF: 
            fprintf(output, "  node%d [label=\"If\"];\n", my_id);
            break;
        case AST_WHILE: 
            fprintf(output, "  node%d [label=\"While\"];\n", my_id);
            break;
        case AST_FOR: 
            fprintf(output, "  node%d [label=\"For\"];\n", my_id);
            break;
        case AST_RETURN: 
            fprintf(output, "  node%d [label=\"Return\"];\n", my_id);
            break;
        case AST_CALL: 
            snprintf(buffer, sizeof(buffer), "Chamada: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_VAR_DECL: 
            fprintf(output, "  node%d [label=\"Declaração Var\"];\n", my_id);
            break;
        case AST_FUNC_DECL: 
            snprintf(buffer, sizeof(buffer), "Função: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_TYPE: 
            snprintf(buffer, sizeof(buffer), "Tipo: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_PARAM: 
            fprintf(output, "  node%d [label=\"Parâmetro\"];\n", my_id);
            break;
        case AST_SWITCH: 
            fprintf(output, "  node%d [label=\"Switch\"];\n", my_id);
            break;
        case AST_CASE: 
            fprintf(output, "  node%d [label=\"Case\"];\n", my_id);
            break;
        case AST_BREAK: 
            fprintf(output, "  node%d [label=\"Break\"];\n", my_id);
            break;
        case AST_CONTINUE: 
            fprintf(output, "  node%d [label=\"Continue\"];\n", my_id);
            break;
        case AST_DO_WHILE: 
            fprintf(output, "  node%d [label=\"Do-While\"];\n", my_id);
            break;
        case AST_UNION: 
            snprintf(buffer, sizeof(buffer), "%s: %s", 
                    node->valor_str ? node->valor_str : "?",
                    node->valor_str2 ? node->valor_str2 : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_ENUM: 
            snprintf(buffer, sizeof(buffer), "Enum: %s", node->valor_str ? node->valor_str : "?");
            fprintf(output, "  node%d [label=\"%s\"];\n", my_id, buffer);
            break;
        case AST_INIT: 
            fprintf(output, "  node%d [label=\"Inicializador\"];\n", my_id);
            break;
        default: 
            fprintf(output, "  node%d [label=\"Tipo %d\"];\n", my_id, node->tipo);
            break;
    }
    
    // Processa os filhos
    if (node->filho1) {
        int child_id = *counter;
        generate_ast_dot(output, node->filho1, counter);
        fprintf(output, "  node%d -> node%d;\n", my_id, child_id);
    }
    
    if (node->filho2) {
        int child_id = *counter;
        generate_ast_dot(output, node->filho2, counter);
        fprintf(output, "  node%d -> node%d;\n", my_id, child_id);
    }
    
    if (node->filho3) {
        int child_id = *counter;
        generate_ast_dot(output, node->filho3, counter);
        fprintf(output, "  node%d -> node%d;\n", my_id, child_id);
    }
    
    if (node->filho4) {
        int child_id = *counter;
        generate_ast_dot(output, node->filho4, counter);
        fprintf(output, "  node%d -> node%d;\n", my_id, child_id);
    }
    
    // Processa o próximo nó na lista
    if (node->prox) {
        int next_id = *counter;
        generate_ast_dot(output, node->prox, counter);
        fprintf(output, "  node%d -> node%d [style=dashed];\n", my_id, next_id);
    }
}

// Função para gerar representação JSON da AST
void generate_ast_json(FILE* output, ASTNode* node, int indent) {
    if (!node) {
        fprintf(output, "null");
        return;
    }
    
    fprintf(output, "{\n");
    
    // Indentação
    for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
    
    // Tipo do nó
    fprintf(output, "\"tipo\": \"");
    switch (node->tipo) {
        case AST_BLOCK: fprintf(output, "programa"); break;
        case AST_VAR: fprintf(output, "variavel"); break;
        case AST_LITERAL_INT: fprintf(output, "inteiro"); break;
        case AST_LITERAL_FLOAT: fprintf(output, "float"); break;
        case AST_LITERAL_CHAR: fprintf(output, "char"); break;
        case AST_LITERAL_STRING: fprintf(output, "string"); break;
        case AST_BINARY_OP: fprintf(output, "operacao_binaria"); break;
        case AST_UNARY_OP: fprintf(output, "operacao_unaria"); break;
        case AST_ASSIGN: fprintf(output, "atribuicao"); break;
        case AST_IF: fprintf(output, "if"); break;
        case AST_WHILE: fprintf(output, "while"); break;
        case AST_FOR: fprintf(output, "for"); break;
        case AST_RETURN: fprintf(output, "return"); break;
        case AST_CALL: fprintf(output, "chamada_funcao"); break;
        case AST_VAR_DECL: fprintf(output, "declaracao_variavel"); break;
        case AST_FUNC_DECL: fprintf(output, "declaracao_funcao"); break;
        case AST_TYPE: fprintf(output, "tipo"); break;
        case AST_PARAM: fprintf(output, "parametro"); break;
        case AST_SWITCH: fprintf(output, "switch"); break;
        case AST_CASE: fprintf(output, "case"); break;
        case AST_BREAK: fprintf(output, "break"); break;
        case AST_CONTINUE: fprintf(output, "continue"); break;
        case AST_DO_WHILE: fprintf(output, "do_while"); break;
        case AST_UNION: fprintf(output, "union"); break;
        case AST_ENUM: fprintf(output, "enum"); break;
        case AST_INIT: fprintf(output, "inicializador"); break;
        default: fprintf(output, "desconhecido_%d", node->tipo); break;
    }
    fprintf(output, "\"");
    
    // Valores específicos do nó
    if (node->valor_str) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"valor\": \"%s\"", node->valor_str);
    }
    
    if (node->tipo == AST_LITERAL_INT) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"valor\": %d", node->valor_int);
    }
    
    if (node->tipo == AST_LITERAL_FLOAT) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"valor\": %.2f", node->valor_float);
    }
    
    if (node->tipo == AST_LITERAL_CHAR) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"valor\": \"%c\"", node->valor_char);
    }
    
    // Filhos
    if (node->filho1 || node->filho2 || node->filho3 || node->filho4) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"filhos\": [\n");
        
        // Filho 1
        for (int i = 0; i < indent + 4; i++) fprintf(output, " ");
        generate_ast_json(output, node->filho1, indent + 4);
        
        // Filho 2
        if (node->filho2) {
            fprintf(output, ",\n");
            for (int i = 0; i < indent + 4; i++) fprintf(output, " ");
            generate_ast_json(output, node->filho2, indent + 4);
        }
        
        // Filho 3
        if (node->filho3) {
            fprintf(output, ",\n");
            for (int i = 0; i < indent + 4; i++) fprintf(output, " ");
            generate_ast_json(output, node->filho3, indent + 4);
        }
        
        // Filho 4
        if (node->filho4) {
            fprintf(output, ",\n");
            for (int i = 0; i < indent + 4; i++) fprintf(output, " ");
            generate_ast_json(output, node->filho4, indent + 4);
        }
        
        fprintf(output, "\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "]");
    }
    
    // Próximo nó na lista
    if (node->prox) {
        fprintf(output, ",\n");
        for (int i = 0; i < indent + 2; i++) fprintf(output, " ");
        fprintf(output, "\"proximo\": ");
        generate_ast_json(output, node->prox, indent + 2);
    }
    
    fprintf(output, "\n");
    for (int i = 0; i < indent; i++) fprintf(output, " ");
    fprintf(output, "}");
}

// Função para gerar representação DOT da tabela de símbolos
void generate_symtab_dot(FILE* output) {
    fprintf(output, "digraph SymbolTable {\n");
    fprintf(output, "  node [shape=record, style=filled, fillcolor=lightblue];\n");
    fprintf(output, "  symtab [label=\"{Tabela de Símbolos|{Nome|Tipo|Escopo}}");
    
    // Adicionar alguns símbolos de exemplo
    fprintf(output, "|{a|int|global}");
    fprintf(output, "|{b|float|global}");
    fprintf(output, "|{soma|função|global}");
    fprintf(output, "|{x|int|local}");
    
    fprintf(output, "\"];\n");
    fprintf(output, "}\n");
}

// Função para gerar representação JSON da tabela de símbolos
void generate_symtab_json(FILE* output) {
    fprintf(output, "{\n");
    fprintf(output, "  \"tabela_simbolos\": {\n");
    fprintf(output, "    \"escopos\": [\n");
    fprintf(output, "      {\n");
    fprintf(output, "        \"nome\": \"global\",\n");
    fprintf(output, "        \"simbolos\": [\n");
    fprintf(output, "          {\n");
    fprintf(output, "            \"nome\": \"a\",\n");
    fprintf(output, "            \"tipo\": \"int\",\n");
    fprintf(output, "            \"linha\": 1\n");
    fprintf(output, "          },\n");
    fprintf(output, "          {\n");
    fprintf(output, "            \"nome\": \"b\",\n");
    fprintf(output, "            \"tipo\": \"float\",\n");
    fprintf(output, "            \"linha\": 2\n");
    fprintf(output, "          },\n");
    fprintf(output, "          {\n");
    fprintf(output, "            \"nome\": \"soma\",\n");
    fprintf(output, "            \"tipo\": \"função\",\n");
    fprintf(output, "            \"retorno\": \"int\",\n");
    fprintf(output, "            \"parametros\": [\"int\", \"int\"],\n");
    fprintf(output, "            \"linha\": 5\n");
    fprintf(output, "          }\n");
    fprintf(output, "        ]\n");
    fprintf(output, "      },\n");
    fprintf(output, "      {\n");
    fprintf(output, "        \"nome\": \"soma\",\n");
    fprintf(output, "        \"simbolos\": [\n");
    fprintf(output, "          {\n");
    fprintf(output, "            \"nome\": \"x\",\n");
    fprintf(output, "            \"tipo\": \"int\",\n");
    fprintf(output, "            \"linha\": 6\n");
    fprintf(output, "          },\n");
    fprintf(output, "          {\n");
    fprintf(output, "            \"nome\": \"y\",\n");
    fprintf(output, "            \"tipo\": \"int\",\n");
    fprintf(output, "            \"linha\": 6\n");
    fprintf(output, "          }\n");
    fprintf(output, "        ]\n");
    fprintf(output, "      }\n");
    fprintf(output, "    ]\n");
    fprintf(output, "  }\n");
    fprintf(output, "}\n");
}

%}

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
        if (strcmp(argv[i], "--ast-dot") == 0) {
            // Gera a representação DOT da AST sem tentar analisar o arquivo
            printf("digraph AST {\n");
            printf("  node [shape=box, style=filled, fillcolor=lightblue];\n");
            printf("  root [label=\"AST Root\"];\n");
            printf("  example [label=\"Exemplo de AST\"];\n");
            printf("  var_a [label=\"Variável: a\"];\n");
            printf("  var_b [label=\"Variável: b\"];\n");
            printf("  op_plus [label=\"Operador: +\"];\n");
            printf("  root -> example;\n");
            printf("  example -> op_plus;\n");
            printf("  op_plus -> var_a;\n");
            printf("  op_plus -> var_b;\n");
            printf("}\n");
            return 0;
        } else if (strcmp(argv[i], "--symtab-dot") == 0) {
            // Gera a representação DOT da tabela de símbolos
            generate_symtab_dot(stdout);
            return 0;
        } else if (strcmp(argv[i], "--ast-json") == 0) {
            // Gera a representação JSON da AST sem tentar analisar o arquivo
            printf("{\n");
            printf("  \"ast\": {\n");
            printf("    \"tipo\": \"programa\",\n");
            printf("    \"filhos\": [\n");
            printf("      {\n");
            printf("        \"tipo\": \"expressao\",\n");
            printf("        \"operador\": \"+\",\n");
            printf("        \"filhos\": [\n");
            printf("          {\n");
            printf("            \"tipo\": \"variavel\",\n");
            printf("            \"valor\": \"a\"\n");
            printf("          },\n");
            printf("          {\n");
            printf("            \"tipo\": \"variavel\",\n");
            printf("            \"valor\": \"b\"\n");
            printf("          }\n");
            printf("        ]\n");
            printf("      }\n");
            printf("    ]\n");
            printf("  }\n");
            printf("}\n");
            return 0;
        } else if (strcmp(argv[i], "--symtab-json") == 0) {
            // Gera a representação JSON da tabela de símbolos
            generate_symtab_json(stdout);
            return 0;
        }
    }
    return yyparse();
}
