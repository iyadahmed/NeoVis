#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "nodes.h"

int add_edge(Graph *graph, int u, int v, int w) {
  Node node = {.v = v, .weight = w};
  // TODO
  return 0;
}

static inline bool is_full(Stack *pt) { return pt->top == pt->maxsize - 1; }

static inline long push(Stack *pt, int x) {
  if (is_full(pt)) {
    return __LONG_MAX__;
  }

  pt->items[++pt->top] = x;
  return x;
}

void topological_sort(Graph *graph, int v, int visited[], Stack *stack) {
  visited[v] = 1;
  // TODO
}