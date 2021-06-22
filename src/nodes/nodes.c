#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "add.h"
#include "nodes.h"

const size_t NODE_SOCKET_VALUE_SIZE[] = {
    [SOCK_FLOAT] = sizeof(float),
};

// returns NULL on failure
Node *create_node(NodeType node_type) {
  Node *node = malloc(sizeof(Node));
  if (!node) {
    return NULL;
  }
  node->type = node_type;
  node->num_inputs = 0;
  node->num_outputs = 0;
  node->inputs = NULL;
  node->outputs = NULL;
  node->exec = NULL;
  node->data = NULL;
  switch (node_type) {
  case NODE_ADD:
    setup_add_node(node);
    break;

  default:
    break;
  }
  return node;
}

void free_node(Node *node) {
  if (node->data) {
    // TODO: call specified free function per node type
    // will probably be member of Node itself
    free(node->data);
  }
  if (node->inputs) {
    for (size_t i = 0; i < node->num_inputs; i++) {
      if (node->inputs[i].value) {
        free(node->inputs[i].value);
      }
    }
    free(node->inputs);
  }
  if (node->outputs) {
    for (size_t j = 0; j < node->num_outputs; j++) {
      if (node->outputs[j].value) {
        free(node->outputs[j].value);
      }
    }
    free(node->outputs);
  }
  free(node);
}

// Create sockets from socket definition array
// returns NULL on failure
NodeSocket *create_sockets_from_definition(NodeSocketDef *defintion,
                                           NodeSocketType sock_type,
                                           size_t *sock_count_out) {
  size_t count = 0;
  *sock_count_out = 0;
  NodeSocketDef *cur = defintion;
  while (cur->type != SOCK_END) {
    count++;
    cur++;
  }
  if (count == 0) {
    return NULL;
  }
  *sock_count_out = count;
  NodeSocket *sockets = malloc(count * sizeof(NodeSocket));
  if (!sockets) {
    return NULL;
  }

  int success = 0;
  for (size_t i = 0; i < count; i++) {
    sockets[i].sock_type = sock_type;
    sockets[i].linked_output = NULL;
    sockets[i].name = defintion[i].name;
    sockets[i].value = NULL;
    sockets[i].value_type = defintion[i].type;

    if (defintion[i].type != SOCK_END) {
      sockets[i].value = malloc(NODE_SOCKET_VALUE_SIZE[defintion[i].type]);
      if (!sockets[i].value) {
        goto bail;
      }
    }
  }

  success = 1;

bail:
  if (success) {
    return sockets;
  }

  free(sockets);
  for (size_t j = 0; j < count; j++) {
    if (sockets[j].value) {
      free(sockets[j].value);
    }
  }
  return NULL;
}

int set_node_inputs(Node *node, NodeSocketDef *defintion) {
  size_t num_inputs;
  NodeSocket *inputs =
      create_sockets_from_definition(defintion, SOCK_IN, &num_inputs);
  if (inputs) {
    node->num_inputs = num_inputs;
    node->inputs = inputs;
    return 0;
  }
  return -1;
}

int set_node_outputs(Node *node, NodeSocketDef *defintion) {
  size_t num_outputs;
  NodeSocket *outputs =
      create_sockets_from_definition(defintion, SOCK_OUT, &num_outputs);
  if (outputs) {
    node->num_outputs = num_outputs;
    node->outputs = outputs;
    return 0;
  }
  return -1;
}