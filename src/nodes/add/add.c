#include "add.h"
#include "../nodes.h"

NodeSocketDef node_add_inputs[] = {
    {SOCK_FLOAT, "Value"},
    {SOCK_FLOAT, "Value"},
    {SOCK_END, ""},
};

NodeSocketDef node_add_outputs[] = {
    {SOCK_FLOAT, "Value"},
    {SOCK_END, ""},
};

void exec_add_node(Node *node) {
  float sum = 0.f;
  for (size_t i = 0; i < node->num_inputs; i++) {
    sum += *(float *)(node->inputs[i].value);
  }
  *(float *)(node->outputs[0].value) = sum;
}

void setup_add_node(Node *node) {
  set_node_inputs(node, node_add_inputs);
  set_node_outputs(node, node_add_outputs);

  node->exec = &exec_add_node;
  node->data = NULL;
}