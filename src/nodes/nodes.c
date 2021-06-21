#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "add.h"
#include "nodes.h"

Node *create_node(NodeType node_type) {
  Node *node = malloc(sizeof(Node));
  node->type = node_type;
  switch (node_type) {
  case NODE_ADD:
    setup_add_node(node);
    break;

  default:
    break;
  }
  return node;
}

void *get_node_input_value(NodeInput *node_input) {
  if (node_input->linked_output) {
    return node_input->linked_output->value;
  }
  return node_input->default_value;
}

void set_node_output_value(NodeOutput *node_output, void *value) {
  if (node_output->value) {
    free(node_output->value);
  }
  node_output->value = value;
}

void set_node_output_value_float(NodeOutput *node_output, float value) {
  float *value_ptr = malloc(sizeof(float));
  *value_ptr = value;
  set_node_output_value(node_output, value_ptr);
}

// NodeGraph *create_node_graph(int max_num_vertices) {
//   NodeGraph *graph = malloc(sizeof(NodeGraph));
//   graph->num_verices = 0;
//   graph->num_edges = 0;
//   graph->max_num_vertices = max_num_vertices;
//   // TODO: check bounds
//   graph->max_num_edges = max_num_vertices * max_num_vertices;
//   graph->adj_lists = malloc(max_num_vertices * sizeof(Node *));
//   for (int i = 0; i < max_num_vertices; i++) {
//     graph->adj_lists[0] = NULL;
//   }
//   return graph;
// }

// void add_graph_edge(NodeGraph *graph, Node *from, Node *to) {
//   graph->adj_lists[from->index] = to;
// }

// int add_edge(Graph *graph, Node *to, Node *from) {
//   return 0;
// }

// int add_edge(Graph *graph, int u, int v, int w) {
//   Node node = {.v = v, .weight = w};
//   // TODO
//   return 0;
// }

// static inline bool is_full(Stack *pt) { return pt->top == pt->maxsize - 1; }

// static inline long push(Stack *pt, int x) {
//   if (is_full(pt)) {
//     return LONG_MAX;
//   }

//   pt->items[++pt->top] = x;
//   return x;
// }

// void topological_sort(Graph *graph, int v, int visited[], Stack *stack) {
//   visited[v] = 1;
//   // TODO
// }