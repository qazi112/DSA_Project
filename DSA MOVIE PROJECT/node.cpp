#include<iostream>
#include "LinkedList.h"


Node::Node()
{
    data=0;
    next=NULL;
}
Node::Node(int d)
{
    data=d;
    next=NULL;
}
void Node:: setData(int d)
{   data=d;
}
void Node:: setPointer( Node *n)
{   next=n;
}
int Node::getData()
{   return data;
}
Node* Node:: getPointer()
{   return next;
}

