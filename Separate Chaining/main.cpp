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
using namespace std;
/**
    ** Node Class : "Movie Class" **
    ** Each Node Object will be a single movie having three attributes **
    ** movie id , average Rating and number of votes **
**/
class Node
{
private:
  string id;
  float avrg_rat;
  int numVotes;
  Node *Next;
public:
  void set_id(string);
  string get_id();
  void set_avrg_rat(float);
  float get_avrg_rat();
  void set_numVotes(int);
  int get_numVotes();
  void set_Next(Node*);
  Node* get_Next();
  Node(string id,float avrg_rat,int numVotes)
  {
    this->id=id;
    this->avrg_rat=avrg_rat;
    this->numVotes=numVotes;
    Next=NULL;
  }
};
void Node::set_id(string id)
{
  this->id=id;
}
string Node::get_id()
{
  return id;
}
void Node::set_avrg_rat(float avrg_rat)
{
  this->avrg_rat=avrg_rat;
}
float Node::get_avrg_rat()
{
  return avrg_rat;
}
void Node::set_numVotes(int numVotes)
{
  this->numVotes=numVotes;
}
int Node::get_numVotes()
{
  return numVotes;
}
void Node::set_Next(Node* ptr)
{
  Next=ptr;
}
Node* Node::get_Next()
{
  return Next;
}
class Link_list
{
private:
  Node *first;
public:
  Link_list()
  {
    first=NULL;
  }
  void set_first(Node *first)
  {
      this->first=first;
  }
  void add_node_start_list(string,float,int);
  void find_value(int);
  void display_hash_table();
  void display_max();
  void display_min();
};
void Link_list::add_node_start_list(string id,float avrg_rat,int numVotes)
{
  Node *temp2=new Node(id,avrg_rat,numVotes);
  Node *temp;
  temp=first;
  if(first==NULL)
  {
    first=temp2;
  }
  else
  {
   if(first->get_numVotes()<numVotes)
   {
    temp2->set_Next(temp);
    first=temp2;
    return;
   }
   else
   {
    temp=first->get_Next();//To save chain
    first->set_Next(temp2);//Now first point to new node
    temp2=first->get_Next();
    temp2->set_Next(temp);//To get back the chain
    return;
   }
   }
}
void Link_list::display_hash_table()
{
  Node *temp;
  temp=first;
  if(first==NULL)
  {
      return;
  }
  while(temp!=NULL)
  {
    cout << temp->get_id();
    cout << "  ";
    cout << temp->get_avrg_rat();
    cout << "  ";
    cout << temp->get_numVotes();
    cout << "  ";
    cout << endl;
    temp=temp->get_Next();
  }
}
void Link_list::display_max() {
    if(first==NULL)
    {
        return;
    }
    cout << first -> get_id();
    cout << "  ";
    cout << first -> get_avrg_rat();
    cout << "  ";
    cout << first -> get_numVotes();
    cout << "  ";
    cout << endl;
    return;
}
void Link_list::display_min() {
    if(first==NULL){
    return;
    }
    cout << first -> get_id();
    cout << "  ";
    cout << first -> get_avrg_rat();
    cout << "  ";
    cout << first -> get_numVotes();
    cout << "  ";
    cout << endl;
    return;
}
/**
    " Hashing Class "
    Having all the functionality for hashing the data
**/
class Hashing
{
  private:
  Link_list object[200];
  public:
  Hashing()
  {
      int i;
      for(i=0;i<200;i++)
        {
            object[i].set_first(NULL);
        }
  }
  int hashing_function(int);
  void insert(int votes,string name,float rank);
  void add_value_in_hash_table();
  void display();
  void find_min_rated_movie();
  void find_max_rated_movie();
  void find_same_rank_movie(float);
};
void Hashing::insert(int votes,string name,float rank)
{
    float a=rank*10;
    int index=hashing_function(a);

    object[index].add_node_start_list(name,rank,votes);
}



int Hashing::hashing_function(int avrg)
{
            return avrg%200;
}
void Hashing::add_value_in_hash_table()
{
    ifstream read;
    int check;
    string id_num;
    float avrg;
    int num_v;
    int counter=0;
    read.open("data.txt");
    read >> id_num;
    read >> id_num;
    read >> id_num;
    while(!read.eof())
    {
    read >> id_num;
    read >> avrg;
    read >> num_v;
    insert(num_v,id_num,avrg);
    counter++;
    }
    read.close();

}
void Hashing::display()
{
    int a;
    for(a=0;a<=100;a++)
    {
        cout << "Displaying data of index in hash table " << a << endl;
        object[a].display_hash_table();
        cout << "Display data of index " << a << " Done\n";
    }
    return;
}
void Hashing::find_max_rated_movie(){
    cout << "Here is the most high rated movie\n";
    object[100].display_max();
    return;
}
void Hashing::find_min_rated_movie(){
    cout << "Here is the low rated movie\n";
    object[10].display_min();
    return;
}
void Hashing::find_same_rank_movie(float input)
{
    int final=input*10;

    object[final].display_hash_table();
    return;
}
int main()
{
  Hashing object;
  int a,input,choice;
  while(true)
  {
  cout << "*********************************************************\n";
  cout << "Enter 1 to load data in your objects\n";
  cout << "Enter 2 for display\n";
  cout << "Enter 3 for find maximum rated movie\n";
  cout << "Enter 4 for find minimum rated movie\n";
  cout << "Enter 5 for find same rating movie\n";
  cout << "**********************************************************\n";
  cin >> input;

  if(input==1)
  {
    object.add_value_in_hash_table();
  }
  else if(input==2)
  {
    object.display();
  }
  else if (input == 3)
  {
      object.find_max_rated_movie();
  }
  else if (input == 4)
  {
      object.find_min_rated_movie();
  }
  else if (input == 5)
  {
      cout << "Enter rank of your movie you want to find out\n";
      float input;
      cin >> input;
      object.find_same_rank_movie(input);
  }
  cout << "Enter 1 for to continue use functions for list or 0 to stop\n";
  cin >> choice;

  if(choice!=1)
  {
    break;
  }
 }
}
