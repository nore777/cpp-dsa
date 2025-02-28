#pragma once

#include <vector>

template <typename T>
long long int binary_search(std::vector<T> arr, T search) {
  size_t min = 0;
  size_t max = arr.size();
  size_t mid;

  while (min <= max) {
    mid = static_cast<size_t>((min + max) / 2);

    if (arr[mid] < search) {
      min = mid + 1;
    } else if (arr[mid] > search) {
      max = mid - 1;
    } else {
      break;
    }
  }

  if (arr[mid] == search) {
    return mid;
  }

  return -1;
}
