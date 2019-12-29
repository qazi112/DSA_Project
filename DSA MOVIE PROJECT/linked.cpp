#include<iostream>
#include "LinkedList.h"

using namespace std;

Node::Node()
{
    //string id;
    //float averagerate;
    //int votes;
    averagerate=0.0;
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
void Node:: setPointer( Node *n)
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
Node* Node:: getPointer()
{   return next;
}


LinkedList::LinkedList()
{
    first=NULL;
}

// implementation of Linked Class
void LinkedList:: setFirst(Node *first)
{   this->first=first;
}
Node* LinkedList:: getFirst()
{   return first;
}
//void add(string id,int vote,float avgRate);

  //  Node::Node(string name,float rate,int vote)

void LinkedList::add(string id,int vote,float avgRate)
{   Node *temp=new Node(id,avgRate,vote);
    if(first == NULL)
    {
           first=temp;
    }
    else
    {

        Node *second=first;
        while(second->getPointer()!=NULL)
        {
              second=second->getPointer();
        }
        second->setPointer(temp);
    }
}
void LinkedList::addAtStart(string id,int vote,float avgRate)
{   Node *temp=new Node(id,avgRate,vote);
    Node *second=first;
    first=temp;
    temp->setPointer(second);
}
void LinkedList::removeFromStart()
{
    first=first->getPointer();
}
void LinkedList::removeFromEnd()
{   Node *temp=first;
    if(first==NULL)
    {
        return;
    }
    else if(temp->getPointer()==NULL)
    {
        first=NULL;
    }
    else
    {

    while(temp->getPointer()->getPointer()!=NULL)
    {
           temp=temp->getPointer();
    }
    temp->setPointer(NULL);
    }
}
void  LinkedList::display()
{   Node *temp=first;
    if(first==NULL)
    {
        cout<<"Empty List\n";
    }
    else
    {   while(temp!=NULL)
        {   cout<<temp->getAverageRate()<<endl;
            cout<<temp->getVote()<<endl;
            cout<<temp->getId()<<endl;
            temp=temp->getPointer();
        }
    }
}
void LinkedList:: removeAt(int index)
{   if(index>=getSize())
    {
        cout<<"Index Exceeds\n";
    }
    else
    {   Node *second=first;
        for(int i=0;second->getPointer()!=NULL; i++)
        {

            if(index==0)
            {   removeFromStart();
                break;
            }
            else if(i==index-1)
            {   second->setPointer(second->getPointer()->getPointer());
                break;
            }
            else
            {
                second=second->getPointer();
            }
        }
    }


}


int LinkedList::getSize()
{
    if(first==NULL)
    {
        cout<<"List Is Empty!\n";
        return 0;
    }
else{
     int i=0;            // counter
    Node *temp=first;
    for( i=0; temp!=NULL; i++)
    {
         temp=temp->getPointer();
    }
    return i;
    }       // Length of List
}



