#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
using namespace std;
//-----------------------//
//Node Class : MOVIE
class Node
{
private:
    string id;
    float averagerate;
    double votes;
    float weightedRank; // Calculated By Formula
    Node *next;
public:
    Node();
    Node(string name,float rate,double vote,float wr);
    void setData(string d,float rate,double vote,float weightR);
    void setPodoubleer(Node *n);
    string getId();
    float getAverageRate();
    double getVote();
    Node* getPodoubleer();
    float getWeightedRank();
    void setWeightedRank(float wr);
};
Node::Node()
{
    averagerate=0;
    votes=0;
    next=NULL;
}
Node::Node(string name,float rate,double vote,float wr)
{
    id=name;
    averagerate=rate;
    votes=vote;
    weightedRank=wr;
    next=NULL;
}
void Node:: setData(string d,float rate,double vote,float weightR)
{
    id=d;
    averagerate=rate;
    votes=vote;
    weightedRank=weightR;
}
void Node:: setPodoubleer( Node *n)
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
double Node::getVote()
{
    return votes;
}
Node* Node:: getPodoubleer()
{   return next;
}
float Node::getWeightedRank()
{
    return weightedRank;
}
void Node::setWeightedRank(float wr)
{
    weightedRank=wr;
}


//Linked List : Movies
class LinkedList
{
private:
    Node *first;
public:
    LinkedList();
    void setFirst(Node *first);
    Node* getFirst();
    void add(string id,double vote,float avgRate,float wr);
    void addAtStart(string id,double vote,float avgRate,float wr);
    void removeFromStart();
    void removeFromEnd();
    void display();
    void removeAt(double index);
    double getSize();
    double findFunction(double value);
    double getAt(double index);
    void removeValue(double d);
    void sortedAddition(string id,double vote,float avgRate,float wr);
};






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
//void add(string id,double vote,float avgRate);

  //  Node::Node(string name,float rate,double vote)

void LinkedList::add(string id,double vote,float avgRate,float wr)
{   Node *temp=new Node(id,avgRate,vote,2.6);
    if(first == NULL)
    {
           first=temp;
    }
    else
    {

        Node *second=first;
        while(second->getPodoubleer()!=NULL)
        {
              second=second->getPodoubleer();
        }
        second->setPodoubleer(temp);
    }
}
/*
//----------------------------------------------------//
    addAtStart = Add value at start

//----------------------------------------------------//
*/

void LinkedList::addAtStart(string id,double vote,float avgRate,float wr)
{   Node *temp=new Node(id,avgRate,vote,2.6);
    Node *second=first;
    first=temp;
    temp->setPodoubleer(second);
}
//----------------------------------------------------//
//----------------------------------------------------//


void LinkedList::removeFromStart()
{
    first=first->getPodoubleer();
}
void LinkedList::removeFromEnd()
{   Node *temp=first;
    if(first==NULL)
    {
        return;
    }
    else if(temp->getPodoubleer()==NULL)
    {
        first=NULL;
    }
    else
    {

    while(temp->getPodoubleer()->getPodoubleer()!=NULL)
    {
           temp=temp->getPodoubleer();
    }
    temp->setPodoubleer(NULL);
    }
}
void  LinkedList::display()
{   Node *temp=first;
    double counter=0;
    if(first==NULL)
    {
        cout<<"Empty List\n";
    }

    else
    {   while(temp!=NULL)
        {   cout<<temp->getId()<<"\t";
            cout<<temp->getAverageRate()<<"\t";
            cout<<temp->getVote()<<endl;
            temp=temp->getPodoubleer();
            counter++;

        }
        cout<<counter<<endl;
    }
}
void LinkedList:: removeAt(double index)
{   if(index>=getSize())
    {
        cout<<"Index Exceeds\n";
    }
    else
    {   Node *second=first;
        for(double i=0;second->getPodoubleer()!=NULL; i++)
        {

            if(index==0)
            {   removeFromStart();
                break;
            }
            else if(i==index-1)
            {   second->setPodoubleer(second->getPodoubleer()->getPodoubleer());
                break;
            }
            else
            {
                second=second->getPodoubleer();
            }
        }
    }


}


double LinkedList::getSize()
{
    if(first==NULL)
    {
        cout<<"List Is Empty!\n";
        return 0;
    }
else{
     double i=0;            // counter
    Node *temp=first;
    for( i=0; temp!=NULL; i++)
    {
         temp=temp->getPodoubleer();
    }
    return i;
    }       // Length of List
}









//-------------------------//
class Hashing_IMDB
{
public:
    Hashing()
    {
        for(int i=0;i<200;i++)
        {
            table[i].setFirst(NULL);
        }
    }
    void display();
    LinkedList table[TABLE_SIZE];
    double hashA(float wr);
    void insert(double votes,string id, float avRate);
};
double Hashing_IMDB::hashA(float wr)
{
    return wr*10;
}
void Hashing_IMDB::insert(double votes,string id, float avRate)
{
   // Formula IMDB
    float R=avRate;
    float v=votes;
    float m=1500;
    float c=6.9;
   float WR=(v/(v+m))*R+(m/(v+m))*c;

    //  Formula
    int index=hashA(WR);
    table[index].addAtStart(id,votes,avRate,2.7);

}
void Hashing_IMDB::display()
{
    cout<<"Displaying Most Popular Movies \n";
    for(int i=90;i<101;i++)
    {
        if(table[i].getFirst()!=NULL)
        {
            cout<<i <<" "<<"->>>";
            table[i].display();
            cout<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        }

    }
}


int main()
{
    Hashing_IMDB a;
    double vote;
    float avRate;
    string id;
    fstream file;
    file.open("data.txt");
    if(!file)
    {
        cout<<"Not";
        return 0;
    }
    file>>id;
    file>>id;
    file>>id;
    while(!file.eof())
    {
        file>>id;
        file>>avRate;
        file>>vote;
        a.insert(vote,id,avRate);

    }

    a.display();
    return 0;

}

