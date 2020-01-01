
#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#ifndef NODE_H
#define NODE_H


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
#endif // NODE_H
