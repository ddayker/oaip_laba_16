#ifndef Header_h
#define Header_h

#endif /* Header_h */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>



struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode* head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int a, int b);
struct Graph* createGraph();
void addEdge(struct Graph* graph, int a , int b , int c);
void printGraph(struct Graph* graph);
void delEdge(struct Graph* graph, int a);
void delNode(struct Graph* graph, int a);
void printAdjMatrix();
void printMenu();


