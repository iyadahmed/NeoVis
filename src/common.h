#ifndef COMMON_H
#define COMMON_H

typedef struct IntPair {
  int a, b;
} IntPair;

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

#endif