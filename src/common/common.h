#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>

// goes to "bail" label
#define BAIL() goto bail;

typedef struct IntPair {
  int a, b;
} IntPair;

typedef struct Stack {
  int top;
  int maxsize;
  int *items;
} Stack;

int get_int_pair(const IntPair *pairs, const size_t num_pairs, int value,
                 int default_value);

Stack *create_stack(size_t maxsize);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
int push(Stack *stack, int x);
int pop(Stack *stack, int *out);
int peek(Stack *stack, int *out);

#endif /* COMMON_H */