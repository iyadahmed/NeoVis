#ifndef NODES_H
#define NODES_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define FREE_NODE(node_ptr)                                                    \
  {                                                                            \
    free_node(node_ptr);                                                       \
    node_ptr = NULL;                                                           \
  }

typedef enum NodeType {
  NODE_ADD,
} NodeType;

typedef enum NodeSocketType {
  SOCK_IN,
  SOCK_OUT,
} NodeSocketType;

typedef enum NodeSocketValueType {
  SOCK_FLOAT,
  // Special socket type to signify end of socket list
  SOCK_END = -1,
} NodeSocketValueType;

extern const size_t NODE_SOCKET_VALUE_SIZE[];

struct Node;
struct NodeInput;
struct NodeOutput;
struct NodeList;

typedef struct NodeSocketDef {
  NodeSocketValueType type;
  const char *name;
} NodeSocketDef;

typedef struct NodeSocket {
  NodeSocketValueType value_type;
  NodeSocketType sock_type;
  const char *name;
  void *value;
  /* Only used when a socket is an input */
  struct NodeSocket *linked_output;
  /* --- */
} NodeSocket;

typedef struct Node {
  NodeType type;

  size_t num_inputs, num_outputs;
  struct NodeSocket *inputs;
  struct NodeSocket *outputs;

  void (*exec)(struct Node *node);

  void *data;
} Node;

typedef struct NodeTree {
  struct Node *node;
  struct NodeTree *adj;
  struct NodeTree *next;
} NodeTree;

Node *create_node(NodeType node_type);
void free_node(Node *node);

NodeSocket *create_sockets_from_definition(NodeSocketDef *defintion,
                                           NodeSocketType sock_type,
                                           size_t *sock_count_out);
int set_node_inputs(Node *node, NodeSocketDef *defintion);
int set_node_outputs(Node *node, NodeSocketDef *defintion);

void exec_node_tree(NodeTree *tree);

#endif /* NODES_H */