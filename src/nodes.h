#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int v;
    int weight;
} Node;

typedef struct Graph
{
    int n;
    Node nodes[265];
    int adj[256][256];
} Graph;

void add_edge(Graph *graph, int u, int v, int w)
{
    Node node = {.v = v, .weight = w};
    // TODO
}

typedef struct Stack
{
    int top;
    int maxsize;
    int *items;
} Stack;

int is_full(Stack *pt)
{
    return pt->top == pt->maxsize - 1;
}

void push(Stack *pt, int x)
{
    if (is_full(pt))
    {
        exit(EXIT_FAILURE);
    }

    pt->items[++pt->top] = x;
}

void topological_sort(Graph *graph, int v, int visited[], Stack *stack)
{
    visited[v] = 1;
    // TODO
}