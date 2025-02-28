#pragma once

#include <cstddef>

namespace hash {

// Integer modulus hashing function
size_t int_mod(size_t size, const char *key) {
  size_t str_sum = 0;

  while (*key != '\0') {
    str_sum += *key;
    key++;
  }

  return str_sum % size;
}

// Fibonacci hashing function
size_t fibonacci_hash_64(const char *key, short unsigned int bits) {
  size_t str_sum = 0;

  while (*key != '\0') {
    str_sum += *key;
    key++;
  }
  // 2^64 * 0.618...(golden ratio conjugate) = 11400714819323198485
  return (str_sum * 11400714819323198485llu) >> (64 - bits);
}

} // namespace hash
