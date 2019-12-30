/*
 * Project Name : "Movie Search Engine".
 * Course : Data Structure And Algorithm.
 * Module Instructor : Dr Malik Jahan Khan.
 * Lab Engineer : Jaleel Sb
 * Semester Project
 * Developed In Year 2019.
 * Team Project.
 * Developed By :
     *************************
 *   1. Qazi Arsalan Shah (BSCS Year 2nd)
 *   2. Abdullah Tahir    (BSCS Year 2nd)
 *   3. Mahmood Yousaf    (BSCS Year 2nd)
     *************************
     "Namal Institute Mianwali"
     *************************
 * This program is written using CodeBlocks IDE
 * Programing language Used : C++
 * Data Structure Used : Linked List
 * Hashing Used for saving the data in data structure
 * Team Project using GitHub
 * GitHub Repository Link : https://github.com/qazi112/DSA_Project
 */

/*

   * Header Files *

*/
#include <iostream>
#include <fstream>
#define TABLE_SIZE 200


using namespace std;
/**
    ** Node Class : "Movie Class" **
    ** Each Node Object will be a single movie having three attributes **
    ** movie id , average Rating and number of votes **
**/

class Node
{
private:
    string id;                      /** Movie Unique Id **/
    float averagerate;              /** Average Rating **/
    int votes;                      /** Votes **/
    Node *next;                     /** Address Of Next Node **/
public:

    Node();                         /** Node Class Default Constructor **/

    Node(string name,float rate,int vote); /** Node Class Parameterized **/

/*
    * Getters Setters
*/
    void setData(string d,float rate,int vote);
    void setnext(Node *n);
    string getId();
    float getAverageRate();
    int getVote();
    Node* getnext();
};
/*

    * Definition of Node Class
*/

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

/**
    ** LinkedList Class : "Movies Chain" **
    ** Each Object will be Holding Movies list **
**/



class LinkedList
{
private:
    Node *first;
public:
    LinkedList();
    void setFirst(Node *first);
    Node* getFirst();
    void add(string id,int vote,float avgRate);
    void addAtStart(string id,int vote,float avgRate);
    void display();
    int getSize();
};




/**
        * Implementation of Linked Class *
**/

LinkedList::LinkedList()
{
    first=NULL;
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
    Node *second=first;
    first=temp;
    temp->setnext(second);
}

/**
    * Display_Function : Displays Entries of linked list *
**/
void  LinkedList::display()
{   Node *temp=first;
    int counter=0;
    if(first==NULL)
    {
        cout<<"Empty List\n";
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








/**
    " Hashing_IMDB Class "
    Having all the functionality for hashing the data
    IMDB formula is used
**/

class Hashing_IMDB
{
public:
    LinkedList table[TABLE_SIZE];
    Hashing()
    {
        for(int i=0;i<200;i++)
        {
            table[i].setFirst(NULL);
        }
    }
    void getsTop_260_movies();
    void readDataFromFile();
    void display(); /// Uses Display function Of linked List
    int hashA(float wr);    /// Hashes On The Basis of IMDB Formula
    void insert(int votes,string id, float avRate); /// Insert Data
};

void Hashing_IMDB::getsTop_260_movies()
{
    for(int a=89;a<99;a++)
    {
        table[a].display();
        cout<<endl;
    }
}

int Hashing_IMDB::hashA(float wr)
{
    return wr*10;

}
void Hashing_IMDB::insert(int votes,string id, float avRate)
{
    float R=avRate;
    float v=votes;
    float m=1500;   /// Bench mark for movies to be in top Ranks
    float c=6.9;
   float WR=(v/(v+m))*R+(m/(v+m))*c;

    ///  Formula
    int index=hashA(WR);    /// Generating Indexes on basis of Weighted Rank
    table[index].addAtStart(id,votes,avRate);

}
void Hashing_IMDB::display()
{
    cout<<"Displaying Most Popular Movies \n";
    for(int i=88;i<90;i++)
    {
        if(table[i].getFirst()!=NULL)
        {
            cout<<i <<" "<<"->>>";
            table[i].display();
            cout<<endl;

        }

    }
}
void Hashing_IMDB :: readDataFromFile()
{
    int vote;
    float avRate;
    string id;
    fstream file;
    file.open("data.txt");
    if(!file)
    {
        cout<<"File opening Error"<<endl;
        return;
    }
    file>>id;
    file>>id;
    file>>id;
    while(!file.eof())
    {
        file>>id;
        file>>avRate;
        file>>vote;
        insert(vote,id,avRate);

    }
}

int main()
{
    Hashing_IMDB h_Obj;
    char choice;
    char ch;
    do{
        cout<<"\tAccording To IMDB Formula\n";
        cout<<"\t Select From Below Options \n\n";
        cout<<"\t Press \"A\" for inserting data \n";
        cout<<"\t Press \"B\" for Displaying Top 250 Movies \n";
        cout<<"\t Press \"C\" Display All Movies\n";
        cin>>choice;
        switch(choice)
        {
        case 'A':

           {
                h_Obj.readDataFromFile();
                break;
           }
        case 'B':
            {
                h_Obj.getsTop_260_movies();
                break;
            }
        case 'C':
            {
                h_Obj.display();
                break;
            }
        }
        cout<<"Press \"Y\" To Continue"<<endl;
        cin>>ch;
    }while(ch=='Y' || ch=='y');


    return 0;

}

