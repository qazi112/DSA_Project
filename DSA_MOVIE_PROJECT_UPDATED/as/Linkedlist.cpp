#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#include "LinkedList.h"
#include "Node.h"

/**
        * Implementation of Linked Class *
**/

LinkedList::LinkedList()
{
    first=NULL;
    backP=NULL;
}

void LinkedList:: setFirst(Node *first)
{   this->first=first;
}
Node* LinkedList:: getFirst()
{   return first;
}

/**
    * Adds the value at end in linked list *
**/
void LinkedList::add(string id,int vote,float avgRate)
{   Node *temp=new Node(id,avgRate,vote);
    if(first == NULL)
    {
           first=temp;
    }
    else
    {

        Node *second=first;
        while(second->getnext()!=NULL)
        {
              second=second->getnext();
        }
        second->setnext(temp);
    }
}
/**
    * AddAtStart_Function : Adds value at start of linked list *
    * Takes Three parameters Id"string", Votes"Integer" , AverageRate"Float" *
**/

void LinkedList::addAtStart(string id,int vote,float avgRate)
{   Node *temp=new Node(id,avgRate,vote);
    Node *second;               /// Adding in a way that first index,
    if(first==NULL)             /// Contain Max Votes Movie
    {
        first=temp;
        return;
    }
    else{
            if(temp->getVote()>first->getVote())
            {
                second=first;
                first=temp;
                temp->setnext(second);
            }
            else{
                second=first->getnext();
                first->setnext(temp);
                temp->setnext(second);
            }
    }

}


//copy add at start
void LinkedList::add_According(string id,int vote,float avgRate)
{   Node *temp=new Node(id,avgRate,vote);
    Node *second;               /// Adding in a way that first index,
    if(first==NULL)             /// Contain Max Votes Movie
    {
        first=temp;
        backP=temp;
        return;
    }
    else{
            if(temp->getVote()>first->getVote())
            {
                second=first;
                first=temp;
                temp->setnext(second);
            }
            else if(temp->getVote()<backP->getVote())
            {
                second=first->getnext();
                first->setnext(temp);
                temp->setnext(second);
                backP=temp;
            }
            else{
                second=first->getnext();
                first->setnext(temp);
                temp->setnext(second);
            }
    }

}










/**
    * Display_Function : Displays Entries of linked list *
**/
void  LinkedList::display()
{   Node *temp=first;
    int counter=0;
    if(first==NULL)
    {
        return;
    }

    else
    {   while(temp!=NULL)
        {   cout<<temp->getId()<<"\t";
            cout<<temp->getAverageRate()<<"\t";
            cout<<temp->getVote()<<endl;
            temp=temp->getnext();
            counter++;

        }
        cout<<endl;
        cout<<"Number of Movies : "<<counter<<endl;
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
         temp=temp->getnext();
    }
    return i;
    }       // Length of List
}
