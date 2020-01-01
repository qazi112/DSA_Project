#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;

/**
    ** LinkedList Class : "Movies Chain" **
    ** Each Object will be Holding Movies list **
**/

class LinkedList
{
private:
    Node *first;
public:
    Node *backP;
    LinkedList();
    void setFirst(Node *first);
    Node* getFirst();
    void add(string id,int vote,float avgRate);
    void addAtStart(string id,int vote,float avgRate);
    void display();
    int getSize();
    void add_According(string id,int vote,float avgRate);
};
#endif
