#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>

// goes to "bail" label
#define BAIL() goto bail;

typedef struct IntPair {
  int a, b;
} IntPair;

int get_int_pair(const IntPair *pairs, const size_t num_pairs, int value,
                 int default_value);

#endif /* COMMON_H */