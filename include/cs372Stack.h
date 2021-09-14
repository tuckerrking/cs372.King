#pragma once
#include <iostream> 
#include "cs372List.h"

template <typename T>
  
class Stack :: Container
{
private:
  List<T> *stackList; = new List<T>();
public:
  Stack() {}
  Stack(Stack &rhs( {}
  ~Stack() {delete stackList;}
  bool empty() {return stackList.empty();}
  void push(T data) {stackList.push_front(data);}
  T pop() {return stackList.pop_front()}
  void traverse(void (*dolt)(T data)){
    stackList.traverse(dolt);
  };
  size_t size() override;
  size_t max_size() override;
  bool empty() override;
  void swap(Container &, Container &) override;
  void clear() override;
};
