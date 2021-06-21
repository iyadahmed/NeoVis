#include "add.h"
#include "../nodes.h"

// This is likely to change
NodeInput add_node_inputs[] = {{SOCK_FLOAT, NULL, NULL},
                               {SOCK_FLOAT, NULL, NULL}};

NodeOutput add_node_outputs[] = {{SOCK_FLOAT, NULL}};

void setup_add_node(Node *node) {
  node->inputs = add_node_inputs;
  node->outputs = add_node_outputs;

  // test
  float *a = malloc(sizeof(float));
  *a = 0.f;
  float *b = malloc(sizeof(float));
  *b = 0.f;

  node->inputs[0].default_value = a;
  node->inputs[1].default_value = b;

  node->data = NULL;
}

void exec_add_node(Node *node) {
  float *a = get_node_input_value(&(node->inputs[0]));
  float *b = get_node_input_value(&(node->inputs[1]));
  set_node_output_value_float(&(node->outputs[0]), *a + *b);
}

// TODO: free functions