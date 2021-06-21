#include <stddef.h>
#include <stdlib.h>

#include "common.h"

// free memory allocated to stack and its items
// also sets the pointer to NULL
#define FREE_STACK(stack_ptr)                                                  \
  {                                                                            \
    free(stack->items);                                                        \
    free(stack);                                                               \
    stack = NULL;                                                              \
  }

int get_int_pair(const IntPair *pairs, const size_t num_pairs, int value,
                 int default_value) {
  for (size_t i = 0; i < num_pairs; i++) {
    if (pairs->a == value) {
      return pairs->b;
    }
    if (pairs->b == value) {
      return pairs->a;
    }
  }
  return default_value;
}

Stack *create_stack(int maxsize) {
  Stack *stack = malloc(sizeof(Stack));
  stack->maxsize = maxsize;
  stack->top = -1;
  stack->items = malloc(maxsize * sizeof(int));
  return stack;
}

bool is_full(Stack *stack) { return stack->top == stack->maxsize - 1; }
bool is_empty(Stack *stack) { return stack->top == -1; }

// returns 0 on sucess, -1 if stack is full
int push(Stack *stack, int value) {
  if (is_full(stack)) {
    return -1;
  }

  stack->items[stack->top] = value;
  stack->top++;
  return 0;
}

// returns 0 on sucess, -1 if stack is empty
int pop(Stack *stack, int *out) {
  if (is_empty(stack)) {
    return -1;
  }

  *out = stack->items[stack->top];
  stack->top--;
  return 0;
}

// returns 0 on sucess, -1 if stack is empty
int peek(Stack *stack, int *out) {
  if (is_empty(stack)) {
    return -1;
  }

  *out = stack->items[stack->top];
  return 0;
}