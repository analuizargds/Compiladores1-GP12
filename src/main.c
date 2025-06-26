#include <stdio.h>
#include <stdlib.h>
#include "../parser/exemplo.tab.h"
#include "../ast/ast.h"

extern FILE *yyin;
extern AST *root;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror("Erro ao abrir arquivo");
            return 1;
        }
        yyin = f;
    }

    yyparse();

    if (root) {
        // ast_to_dot(root); // Removed as we are now generating Mermaid CFG
        build_and_generate_cfg_mermaid(root);
    }

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}


