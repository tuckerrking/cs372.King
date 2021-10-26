//
//  BinarySearch.h
//  binary_search
//
//  Created by Tucker King on 10/26/21.
//

#ifndef BinarySearch_h
#define BinarySearch_h
#pragma once

#include <iostream>

using namespace std;

template<typename T>
int binary_search(T arr[], int n, T x)
{
    int start= 0;
    int end= n - 1;
    while(start<= end)
    {
        int mid= (start + end) / 2;
        if(arr[mid]== x)
        {
            return mid;
        }
        else if(arr[mid]< x)
        {
            start= mid + 1;
        }
        else
        {
            end= mid - 1;
        }
        return -1;
    }
}


#endif /* BinarySearch_h */
