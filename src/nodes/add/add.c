#include "add.h"
#include "../nodes.h"

// This is likely to change
NodeInput add_node_inputs[] = {{SOCK_FLOAT, {.float_value = 0.f}, NULL},
                               {SOCK_FLOAT, {.float_value = 0.f}, NULL}};

NodeOutput add_node_outputs[] = {{SOCK_FLOAT, {.float_value = 0.f}}};

void setup_add_node(Node *node) {
  node->inputs = add_node_inputs;
  node->outputs = add_node_outputs;

  node->inputs[0].default_value.float_value = 0.f;
  node->inputs[1].default_value.float_value = 0.f;

  node->data = NULL;
}

void exec_add_node(Node *node) {
  float a = get_node_input_value(&(node->inputs[0])).float_value;
  float b = get_node_input_value(&(node->inputs[1])).float_value;
  set_node_output_value_float(&(node->outputs[0]), a + b);
}