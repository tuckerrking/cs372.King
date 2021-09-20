//
//  cs372Bag.h
//  cs372_headers
//
//  Created by Tucker King on 9/20/21.
//

/*#ifndef cs372Bag_h
#define cs372Bag_h

#include <iostream>
#include "cs372List.h"
using namespace std;

template<typename T>
class Bag
{
private:
    List<T> bagList();
public:
    void insert(T item)
    {
        bagList.push_back(item);
    }
    
    T pop()
    {
        bagList.pop_back();
    }
    
    int size()
    {
        return bagList.size();
    }
    
    int count(T item)
    {
        int total= 0;
        int bagSize= bagList.size();
        
        for(int i= 0; i< bagSize; i++)
        {
            if(bagList[i]== item)
            {
                total++;
            }
        }
        
        return total;
    }
};


#endif * cs372Bag_h */

