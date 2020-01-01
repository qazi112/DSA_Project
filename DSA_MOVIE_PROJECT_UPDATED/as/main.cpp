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
#include "LinkedList.h"
#include "Node.h"
#include "hashing.h"
using namespace std;

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
        cout<<"\t Press \"C\" Display All Movies Ranked Using Formula\n";
        cout<<"\t Press \"D\" Display Best Movie According to Votes\n";
        cout<<"\t Press \"E\" Display All Movies According To Simple Hashing\n";
        cout<<"\t Press \"F\" To Display Worst Movies According To IMDB Formula\n";
        cout<<"\t Press \"G\" To Display Worst Movie without formula\n";
        cout<<"\t Press \"H\" To Display Best Movie According To Formula\n";
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
        case 'D':
            {
                Node *a=h_Obj.bestMovie_MaxVotes();
                cout<<"Id : "<<a->getId()<<"\t"
                <<"Average Rate :"<<a->getAverageRate()<<"\t"
                <<"Votes :"<<a->getVote()<<endl;
                break;
            }
        case 'E':
            {
                h_Obj.display_Simple();
                break;
            }
        case 'F':
            {
                h_Obj.worstMovies_IMDB();
                break;
            }
        case 'G':
            {
                h_Obj.worst_Movie_Simple();
                break;
            }
        case 'H':
            {
                h_Obj.best_Movie_Formula();
                break;
            }
        }
        cout<<"Press \"Y\" To Continue"<<endl;
        cin>>ch;
    }while(ch=='Y' || ch=='y');


    return 0;

}

