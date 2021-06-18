#ifndef NODES_H
#define NODES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int v;
  int weight;
} Node;

typedef struct Graph {
  int n;
  Node nodes[265];
  int adj[256][256];
} Graph;

typedef struct Stack {
  int top;
  int maxsize;
  int *items;
} Stack;

int add_edge(Graph *graph, int u, int v, int w);
static inline bool is_full(Stack *pt);
static inline long push(Stack *pt, int x);
void topological_sort(Graph *graph, int v, int visited[], Stack *stack);

#endif /* NODES_H */