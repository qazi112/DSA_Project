#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#include "LinkedList.h"
#include "Node.h"

/**

    * Definition of Node Class
**/

Node::Node()
{
    averagerate=0;
    votes=0;
    next=NULL;
}
Node::Node(string name,float rate,int vote)
{
    id=name;
    averagerate=rate;
    votes=vote;
    next=NULL;
}
void Node:: setData(string d,float rate,int vote)
{
    id=d;
    averagerate=rate;
    votes=vote;

}
void Node:: setnext( Node *n)
{
      next=n;
}
string Node::getId()
{
    return id;
}
float Node::getAverageRate()
{
    return averagerate;
}
int Node::getVote()
{
    return votes;
}
Node* Node:: getnext()
{   return next;
}
