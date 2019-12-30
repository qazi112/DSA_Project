#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "avl.cpp"

using namespace std;

class Hash {


  public:

  AVL array1[150];
  void adder(int d, float rat, string id);
  int hash_function(int d);
  void File_handling();
  void smallest();
  void largest();
  void custom_rate_disp(float rat);

};

int Hash::hash_function(int d) {
  return d % 150;
}

void Hash::custom_rate_disp(float rat) {
  int a = rat * 10;
  cout << "================================" << endl;
  cout << "Hash Table Index: " << a << endl;
  array1[a].disp_I(array1[a].getroot());
  cout << "================================" << endl;

}

void Hash::smallest() {
  int a = 0;
  while (true) {
    if (array1[a].getroot() != NULL) {
      cout << "================================" << endl;
      array1[a].smallest(array1[a].getroot());
      cout << "================================" << endl;
      break;

    }

    a++;
  }
}

void Hash::largest() {
  int a = 149;
  while (true) {
    if (array1[a].getroot() != NULL) {
      cout << "================================" << endl;
      array1[a].largest(array1[a].getroot());
      cout << "================================" << endl;
      break;

    }
    a--;
  }
}

void Hash::adder(int d, float rat, string id) {

  float b = rat * 10;
  int a = hash_function(b);

  array1[a].add(d, rat, id);

}

void Hash::File_handling() {
  ifstream thefile("data.txt");

  int vote;
  float rate;
  string id;
  cout << "Adding Data, Please take cup of tea" << endl;

  while (thefile >> id >> rate >> vote) {
    adder(vote, rate, id);

  }

  cout << "Added Successfully" << endl;
}

void template1() {
  Hash obj;
  obj.File_handling();
  float b;
  char a, x;
  cout << "================================" << endl;
  cout << "For Least popular movie, Press A" << endl;
  cout << "For Most popular movie, Press B" << endl;
  cout << "Enter C to Enter Rate to find all Movies of same rate" << endl;
  cout << "Press Q for END" << endl;

  do {

    cin >> a;

    switch (a) {
    case 'A':
      obj.smallest();
      break;
    case 'B':
      obj.largest();
      break;
    case 'C':
      cout << "Enter Data" << endl;
      cin >> b;
      obj.custom_rate_disp(b);
      break;

    default:
      break;
    }
    if (a != 'Q') {
      cout << "Character again" << endl;
    }

  }
  while (a != 'Q');

}

int main() {

  template1();

}
