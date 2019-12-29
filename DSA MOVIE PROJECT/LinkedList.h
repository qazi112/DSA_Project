#include<iostream>
#include <string>
using namespace std;
class Node
{
private:
    string id;
    float averagerate;
    int votes;
    Node *next;
public:
    Node();
    Node(string name,float rate,int vote);
    void setData(string d,float rate,int vote);
    void setPointer(Node *n);
    string getId();
    float getAverageRate();
    int getVote();
    Node* getPointer();
};
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
    void removeFromStart();
    void removeFromEnd();
    void display();
    void removeAt(int index);
    int getSize();
    int findFunction(int value);
    int getAt(int index);
    void removeValue(int d);
    void fileHandling();
    void add_By_rec(Node *n,int d);

};

