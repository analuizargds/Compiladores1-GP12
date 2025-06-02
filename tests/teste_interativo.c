#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../simbolos.h"

void mostrarMenu()
{
    printf("\n=== Tabela de Símbolos ===\n");
    printf("1. Inserir símbolo\n");
    printf("2. Buscar símbolo\n");
    printf("3. Iniciar novo escopo\n");
    printf("4. Finalizar escopo atual\n");
    printf("5. Mostrar tabela completa\n");
    printf("6. Mostrar escopo atual\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    char nome[32];
    int opcao, tipo;

    iniciarTabelaSimbolos();
    printf("Tabela de símbolos iniciada!\n");

    while (1)
    {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1: // Inserir símbolo
            printf("Nome do símbolo: ");
            fgets(nome, 32, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Tipo (1=int, 2=float): ");
            scanf("%d", &tipo);
            getchar();

            Simbolo *s = inserirSimbolo(nome, tipo);
            if (s == NULL)
            {
                printf("Erro: Símbolo já existe no escopo atual!\n");
            }
            else
            {
                printf("Símbolo inserido com sucesso!\n");
            }
            break;

        case 2: // Buscar símbolo
            printf("Nome do símbolo: ");
            fgets(nome, 32, stdin);
            nome[strcspn(nome, "\n")] = 0;

            Simbolo *b = buscarSimbolo(nome);
            if (b == NULL)
            {
                printf("Símbolo não encontrado!\n");
            }
            else
            {
                printf("Símbolo encontrado!\n");
                printf("Tipo: %s\n", b->tipo == TIPO_INT ? "int" : "float");
                printf("Nível: %d\n", b->nivel);
            }
            break;

        case 3: // Iniciar escopo
            iniciarEscopo();
            printf("Novo escopo iniciado (nível %d)\n", nivelEscopoAtual());
            break;

        case 4: // Finalizar escopo
            if (nivelEscopoAtual() == 0)
            {
                printf("Erro: Não é possível finalizar o escopo global!\n");
            }
            else
            {
                finalizarEscopo();
                printf("Escopo finalizado (nível atual: %d)\n", nivelEscopoAtual());
            }
            break;

        case 5: // Mostrar tabela completa
            imprimirTabelaSimbolos();
            break;

        case 6: // Mostrar escopo atual
            imprimirEscopoAtual();
            break;

        case 0: // Sair
            finalizarTabelaSimbolos();
            printf("Tabela de símbolos finalizada!\n");
            return 0;

        default:
            printf("Opção inválida!\n");
        }
    }

    return 0;
}