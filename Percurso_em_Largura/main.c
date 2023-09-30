#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main()
{
    // Cria uma árvore binária de exemplo e insere alguns elementos
    struct Node *root = NULL;
    int input, choice;
    do
    {
        view_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido:\n");
            scanf("%d", &input);
            insert(&root, input);
            break;

        case 2:
            BFS(root);
            break;
        default:
            break;
        }
        system("clear");
    } while (choice != 3);

    return 0;
}
