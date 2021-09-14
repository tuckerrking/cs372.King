#pragma once
#include <iostream>

template <typename T>
class Deque :: public Container
{
private:
  class Node {
    T data;
    Node *tail;
  };
  Node *head = nullptr;
  Node *tail = nullptr;
public:
  Deque()
  Deque(Deque &rhs); // copy constructor
  void push_front(T data);
  T pop_front();
  void push_back(T data);
  T pop_back();
  void traverse();
  size_t size() override;
  size_t max_size() override;
  bool empty() override;
  void swap(Container &, Container &) override;
  void clear() override;
};
