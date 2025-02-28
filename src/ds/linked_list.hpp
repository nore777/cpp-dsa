#pragma once

#include <iostream>
#include <stdexcept>

/**
 *
 * */
template <typename T> struct LinkedListNode {
  T value;
  LinkedListNode *next;

  LinkedListNode(T value) : value(value), next(nullptr) {}
};

/**
 *
 * */
template <typename T> class LinkedList {
private:
  LinkedListNode<T> *root;

public:
  LinkedList() : root(nullptr) {}

  ~LinkedList() {}

  void append(T value) {
    LinkedListNode<T> *newNode = new LinkedListNode(value);

    if (root == nullptr) {
      root = newNode;
      return;
    }

    auto current = root;

    while (current->next != nullptr) {
      current = current->next;
    }

    current->next = newNode;
  }

  T pop() {
    auto current = root;
    if (current == nullptr) {
      throw std::out_of_range("Linked List pop(), root is nullptr");
    }

    if (current->next == nullptr) {
      T val = root->value;
      root = nullptr;
      return val;
    }

    while (current->next->next != nullptr) {
      current = current->next;
    }

    T val = current->next->value;
    current->next = nullptr;
    return val;
  }

  T at(size_t index) {
    if (root == nullptr) {
      throw std::out_of_range("Linked List at(), root is nullptr");
    }

    auto current = root;

    while (index > 0 && current->next != nullptr) {
      current = current->next;
      index--;
    }

    if (index == 0) {
      return current->value;
    } else {
      throw std::out_of_range("Linked List at() out of range");
    }
  }

  void print() {
    auto current = root;
    while (current != nullptr) {
      std::cout << current->value << '\n';
      current = current->next;
    }
  }
};
