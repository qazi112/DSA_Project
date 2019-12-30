#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "avl.cpp"

using namespace std;

class Hash {
public:
  AVL array1[150];

  public:


  void disp();
  void adder_linear(int d, float rat, string id);
  int hashf(int d);
  void serarch(int d);
  void add();
  void smallest();
  void largest();
  void custom_disp(float rat);


  void status();
};

void Hash::status() {
  int i = 0;
  for (int a = 0; a < 100; a++) {
    if (array1[a].getroot() == NULL) {
      i++;
    }
  }
  if (i == 100) {
    cout << "empty" << endl;
  }
  if (i == 0) {
    cout << "full" << endl;
  } else {
    cout << "not full" << endl;
  }

}

void Hash::serarch(int d) {

  array1[hashf(d * 10)].search(array1[hashf(d * 10)].getroot(), d);

}

int Hash::hashf(int d) {
  return d%150;
}

void Hash::custom_disp(float rat) {
    int a=rat*10;
    cout << "================================" << endl;
    cout << "Hash Table Index: " << a << endl;
    array1[a].disp_I(array1[a].getroot());
    cout << "================================" << endl;





}

void Hash::smallest()
{ int a=0;
    while(true)
    {
        if(array1[a].getroot()!=NULL)
        {
            array1[a].smallest(array1[a].getroot());
            break;

        }

        a++;
    }
}

void Hash::largest()
{ int a=149;
    while(true)
    {
        if(array1[a].getroot()!=NULL)
        {
            array1[a].largest(array1[a].getroot());
            break;

        }

        a--;
    }
}





void Hash::adder_linear(int d, float rat, string id) {

  float b=rat*10;
  int a=hashf(b);

  array1[a].add(d, rat, id);


}

void Hash::add() {
  ifstream thefile("data.txt");

  int vote;
  float rate;
  string id;
  cout << "Adding Data, Please take cup of tea" << endl;

  while (thefile >> id >> rate >> vote) {
    adder_linear(vote, rate, id);

  }

  cout << "Added Successfully" << endl;
}


void template1()
{
Hash obj;
obj.add();
float b;
char a,x;
    cout << "================================" << endl;
    cout << "For Least popular movie, Press A" << endl;
    cout << "For Most popular movie, Press B" << endl;
    cout << "Enter C to Enter Rate to find all Movies of same rate" << endl;
    cout << "Press Q for END" << endl;


do{

    cin>>a;

    switch(a)
    {
        case 'A':
        obj.smallest();
        break;
        case 'B':
        obj.largest();
        break;
        case 'C':
        cout <<"Enter Data" << endl;
        cin>> b;
        obj.custom_disp(b);
        break;

        default:
        break;
}
if(a!='Q')
   {cout << "Character again" << endl;}


}
while(a!='Q');



}


int main()
{

    template1();


}
