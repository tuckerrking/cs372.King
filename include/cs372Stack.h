//
//  cs372Stack.h
//  cs372_headers
//
//  Created by Tucker King on 9/20/21.
//

#ifndef cs372Stack_h
#define cs372Stack_h
#pragma once

#include "cs372List.h"

using namespace std;

template<typename T>
class Stack
{
private:
    List<T> *stackList= new List<T>();
    int stackSize= 0;
public:
    Stack();
    Stack(Stack& rhs);
    ~Stack();
    bool empty() override;
    void push(T data);
    T pop();
    void traverse(void(*doIt)(T data));
    size_t size() override;
    size_t max_size() override;
    void swap(Container&, Container&) override;
    void clear() override;
};

Stack()
{
    
}

Stack(Stack& rhs)
{
    
}

~Stack()
{
    delete stackList;
}

bool empty()
{
    return stackList->empty();
}

void push(T data)
{
    stackList->push_back(data);
    stackSize++;
}

T pop()
{
    stackSize--;
    T back = stackList->back();
    stackList->pop_back();
    return back;
}

void traverse(void(*doIt)(T data))
{
    stackList->traverse(doIt);
}

size_t size()
{
    return stackSize;
}

size_t max_size()
{
    return INT_MAX;
}

void swap(Container& a, Container& b)
{
    Stack tempStack;
    Stack& aStack = dynamic_cast<Stack&>(a);
    Stack& bStack = dynamic_cast<Stack&>(b);
    
    while(!aStack.empty())
    {
        tempStack.push(aStack.pop());
    }
    
    int bCount = bStack.size();
    
    while(!bStack.empty())
    {
        tempStack.push(bStack.pop());
    }
    
    for(int i= 0; i< bCount; i++)
    {
        aStack.push(tempStack.pop());
    }
    
    while(!tempStack.empty())
    {
        bStack.push(tempStack.pop());
    }
}

void clear()
{
    while(!empty())
    {
        pop();
    }
}


#endif /* cs372Stack_h */
