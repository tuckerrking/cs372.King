#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
struct Node
{
  T data;
  Node* next;
};

template<typename T>
class Stack
{
  Node<T> *top; //top of stack
 public:
  //Constructor
  Stack()
  {
    top= nullptr;
  }
  
  void push(T data)
  {
    node<T> *temp;
    temp= new Node<T>;
    temp->data= data;
    temp->next= top;
    top= temp;
  }
  
  void pop(T& ch)
  {
    if(top!= nillptr)
    {
      Node<T> *temp= top;
      top= top->next;
      ch= temp->data;
      delete temp;
    }
  }
  
  bool isEmpty()
  {
    return top== nullptr;
  }
  
  ~Stack()
  {
    while(!isEmpty())
    {
      node<T> *temp= top;
      top= top->next;
      delete temp;
    }
  }
};

//-----------------------------------------

int main()
{
  Stack<char> stack;
  char filename[50];
  
  ifstream inFile.open("input.txt");
  if(!inFile)
  {
    cout << "File not found\n";
    return 1;
  }
  
  char c;
  while(inFile.get(c))
  {
    stack.push(c);
  }
  
  inFile.close();
  
  ofstream outFile.open("output.txt");
  
  while(!stack.isEmpty())
  {
    stack.pop(c);
    outFile.put(c);
  }
  
  outFile.close();
  
  return 0;
}
