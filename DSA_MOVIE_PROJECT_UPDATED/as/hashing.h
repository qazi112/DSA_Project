#include <iostream>
#include <fstream>
#define TABLE_SIZE 200
#include "LinkedList.h"
#include "Node.h"
#ifndef HASHING_H
#define HASHING_H

using namespace std;

/**
    " Hashing_IMDB Class "
    Having all the functionality for hashing the data
    IMDB formula is used
**/

class Hashing_IMDB
{
public:
    LinkedList table[TABLE_SIZE];
    LinkedList table_Simple[TABLE_SIZE];
    Hashing();
    void getsTop_260_movies();
    void readDataFromFile();
    void display(); /// Uses Display function Of linked List
    int hashA(float wr);    /// Hashes On The Basis of IMDB Formula
    int hashB(float ranking);
    void insert(int votes,string id, float avRate); /// Insert Data
    Node* bestMovie_MaxVotes();
    void display_Simple();
    void worstMovies_IMDB();
    void worst_Movie_Simple();
    void best_Movie_Formula();
};
#endif // HASHING_H
