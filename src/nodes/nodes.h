#ifndef NODES_H
#define NODES_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum NodeType { NODE_ADD } NodeType;
typedef enum NodeSocketType { SOCK_FLOAT } NodeSocketType;

struct Node;
struct NodeInput;
struct NodeOutput;
struct NodeList;

typedef union NodeSocketValue {
  float float_value;
  int int_value;
} NodeSocketValue;

typedef struct NodeOutput {
  NodeSocketType type;
  NodeSocketValue value;
} NodeOutput;

typedef struct NodeInput {
  NodeSocketType type;
  NodeSocketValue default_value;
  struct NodeOutput *linked_output;
} NodeInput;

typedef struct Node {
  NodeType type;

  int num_inputs, num_outputs;
  struct NodeInput *inputs;
  struct NodeOutput *outputs;

  void *data;
} Node;

// Node graph
typedef struct NodeList {
  struct Node *node;
  struct NodeList *adj;
  struct NodeList *next;
} NodeList;

Node *create_node(NodeType node_type);
NodeSocketValue get_node_input_value(NodeInput *node_input);
void set_node_output_value(NodeOutput *node_output, void *value);
void set_node_output_value_float(NodeOutput *node_output, float value);
// NodeGraph *create_node_graph(int max_num_vertices);
// void add_graph_edge(NodeGraph *graph, Node *to, Node *from);

#endif /* NODES_H */