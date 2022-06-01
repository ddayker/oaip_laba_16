#include "Header.h"

int main()
{
    
    printMenu();
    int choice;
    int nNode = 5;
    int nEdge = 4;
    struct Graph* graph = NULL;
    printf("Ваш выбор: ");
    scanf("%i", &choice);

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
        {
            if (!graph)
            {
                graph = createGraph();
                printf("Граф создан!");
            }
            else
            {
                printf("Граф уже существует!\n");
            }
        }
        break;
        case 2:
        {
            if (graph)
            {
                if (nEdge == 4)
                {
                    delEdge(graph, nEdge);
                    nEdge++;
                }
                else
                {
                    printf("Ребро уже удалено!");
                }
            }
            else
            {
                printf("Граф не существует!\n");
            }
        }
        break;
        case 3:
        {
            if (graph)
            {
                if (nNode == 5)
                {
                    delNode(graph, nNode);
                    nNode++;
                }
                else
                {
                    printf("Вершина уже удалена!");
                }
            }
            else
            {
                printf("Граф не существует!\n");
            }
        }
        break;
        case 4:
            if (graph)
            {
                printGraph(graph);
            }
            else
            {
                printf("Граф не существует!\n");
            }
            break;
        case 5:
            if (graph)
            {
                printAdjMatrix();
            }
            else
            {
                printf("Граф не существует!\n");
            }
            break;
        }
        printMenu();
        printf("Ваш выбор: ");
        scanf("%i", &choice);
    }
}


