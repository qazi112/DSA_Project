#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#include "LinkedList.h"
#include "Node.h"
#include "hashing.h"
using namespace std;

Hashing_IMDB::Hashing()
    {
        for(int i=0;i<200;i++)
        {
            table[i].setFirst(NULL);    /// Using IMDB Formula
            table_Simple[i].setFirst(NULL); /// Using Its Own Rank
        }
    }

/// Hash Function For Simple Hashing
int Hashing_IMDB::hashB(float ranking)
{
    float a=ranking*10;
    return a;
}
void Hashing_IMDB:: best_Movie_Formula()
{
    cout<<"Best Movie According To Formula : \n";
    cout<<"Id : "<<table[98].getFirst()->getId()<<"\t";
    cout<<"Rating : "<<table[98].getFirst()->getAverageRate()<<"\t";
    cout<<"Votes : "<<table[98].getFirst()->getVote()<<"\n";
}

void Hashing_IMDB::worst_Movie_Simple()
{
    cout<<"Worst Movie : \n"<<"Id :"<<table_Simple[10].backP->getId()<<"\t";
    cout<<"Rating :"<<table_Simple[10].backP->getAverageRate()<<"\t";
    cout<<"Votes :"<<table_Simple[10].backP->getVote()<<endl;
}

void Hashing_IMDB:: worstMovies_IMDB()
{
    cout<<" Displaying 10 Worst Movies ...... ! "<<endl;
    for(int i=13;i<22;i++)
    {
        if(table[i].getFirst()!=NULL)
        {
            table[i].display();
            cout<<endl;
        }
    }
    cout<<"Total Movies : 10 "<<endl;
}

void Hashing_IMDB::display_Simple()
{
    for(int i=0;i<100;i++)
    {
        if(table_Simple[i].getFirst()!=NULL)
        {
            table_Simple[i].display();
            cout<<endl;
        }
    }
}

Node* Hashing_IMDB:: bestMovie_MaxVotes()
{
    int maxVotes=0;
    Node *trace;
    for(int i=10;i<99;i++)
    {
        if(table[i].getFirst()==NULL)
        {
            continue;
        }
        else{
            if(table[i].getFirst()->getVote()> maxVotes)
            {
               maxVotes=table[i].getFirst()->getVote();
               trace=table[i].getFirst();
            }
        }
    }
    return trace;
}
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
    int index=hashA(WR);        /// Generating Indexes on basis of Weighted Rank
    table[index].addAtStart(id,votes,avRate);
    int in=hashB(avRate);       /// Generating Indexes on Basis of AverageRate
    table_Simple[in].add_According(id,votes,avRate);
}
void Hashing_IMDB::display()
{
    cout<<"Displaying Most Popular Movies \n";
    for(int i=0;i<100;i++)
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
