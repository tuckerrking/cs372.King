#pragma once

#include <iostream>
#include <vector>
#include "Tree.h"

template<typename T>
bool binarySearch(T val, vector<T> arr, int min, int max)
{
  if(min > max)
  {
    return false;
  }
  else if(min== max)
  {
    return val== arr[min];
  }
  
  int mid= (min + max) / 2;
  
  if(val== arr[mid])
  {
    return binarySearch(val, arr, low, mid- 1);
  }
  return binarySearch(val, arr, mid+ 1, max);
}

template<typename T>
bool find(T val, vector<T> arr)
{
  return binarySearch(val, arr, 0, arr.size()- 1);
}
  
