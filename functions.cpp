#include "Header.h"

int* NodeDel;
int AdjMatrix[6][6];

void printMenu()
{
   
    printf( "\n---------------------------------------------\n");
    printf( "|                   МЕНЮ                    |\n");
    printf( "---------------------------------------------\n");
    printf( "|          1) Создать граф                  |\n");
    printf( "|          2) Удалить рёбра с номером 4     |\n");
    printf( "|          3) Удалить вершину с номером 5   |\n");
    printf( "|          4) Вывести граф                  |\n");
    printf( "|          5) Вывести матрицу смежности     |\n");
    printf( "|          6) Выход из программы            |\n");
    printf( "---------------------------------------------\n");
}



struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode = (AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph()
{
    int V=7;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 1; i < V; i++)
    {
        graph->array[i].head = NULL;
    }
    NodeDel = (int*)malloc(V * sizeof(int));
    
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            AdjMatrix[i][j] =0;
        }
    
    addEdge(graph, 1, 2, 7);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 6, 1);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 5, 2);
    addEdge(graph, 3, 6, 4);
    addEdge(graph, 5, 2, 2);
    addEdge(graph, 5, 4, 5);
    addEdge(graph, 6, 5, 3);
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    AdjMatrix[src-1][dest-1]=weight;
}


void printGraph(struct Graph* graph)
{
    int v;
    printf("\n");
    for (v = 1; v < graph->V; ++v)
    {
       
        struct AdjListNode* pCrawl = graph->array[v].head;
        if (NodeDel[v])
        {
            continue;
        }
        printf("----------------------------------------------");
        printf("\nВершина %d:\n", v);
        if (!pCrawl)
        {
            printf("Эта вершина не связана с другими вершинами.\n");
        }
        while (pCrawl)
        {
            printf("Ребро  %d соединяет с вершиной %d;\n", pCrawl->weight, pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("----------------------------------------------\n");
    }
}

void delEdge(struct Graph* graph, int nEdge)
{
    struct AdjListNode* del, * prevDel, * tmp;
    int counter = 0;
    for (int i = 1; i < graph->V; i++)
    {
        prevDel = NULL;
        del = graph->array[i].head;
        while (del && del->weight != nEdge)
        {
            prevDel = del;
            del = del->next;
        }
        if (del)
        {
            if (prevDel)
            {
                tmp = del;
                prevDel->next = del->next;
                free(del);
                counter++;
            }
            else
            {
                tmp = del;
                graph->array[i].head = del->next;
                free(del);
                counter++;
            }
        }
    }
    if (counter)
    {
        printf("Рёбра %i удалены!\n", nEdge);
    }
    else
    {
        printf("В графе нет такого ребра!\n");
    }
    
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            if(AdjMatrix[i][j] == 4)
                AdjMatrix[i][j] = 0;
        }
}

void delNode(struct Graph* graph, int nNode)
{
    struct AdjListNode* tmp, * del, * prevDel;
    if (nNode >= 0 && nNode < graph->V)
    {
        if (NodeDel[nNode])
        {
            printf("Вершина уже удалена!\n");
            return;
        }
        if (graph->array[nNode].head)
        {
            del = graph->array[nNode].head;
            while (del)
            {
                tmp = del;
                del = del->next;
                free(tmp);
            }
        }
        NodeDel[nNode] = 1;
        for (int i = 1; i < graph->V; i++)
        {
            prevDel = NULL;
            if (NodeDel[i])
            {
                continue;
            }
            del = graph->array[i].head;
            while (del && del->dest != nNode)
            {
                prevDel = del;
                del = del->next;
            }
            if (del)
            {
                if (prevDel)
                {
                    tmp = del;
                    prevDel->next = del->next;
                    free(del);
                }
                else
                {
                    tmp = del;
                    graph->array[i].head = del->next;
                    free(del);
                }
            }
        }
        printf("Вершина %i удалена\n", nNode);
    }
    else
    {
        printf("Такой вершины не существует!\n");
    }
    
    for(int i = 0; i < 6; i++)
    {
        AdjMatrix[4][i] = 0;
        AdjMatrix[i][4] = 0;
    }
}

void printAdjMatrix(){
    printf("\n↓ Матрица смежности\n\n");
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            std::cout<<AdjMatrix[i][j]<<' ';
        }std::cout<<std::endl;
    }
}


