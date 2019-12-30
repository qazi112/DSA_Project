#include<iostream>
#include <fstream>
#include <string>
using namespace std;


class NODE{
int vote;
float rate;
string id;
NODE* next;

public:
    NODE(){
    vote=0;
    next=NULL;
    rate=0;
    }
    NODE(int vot, float rat, string id1)
    {

        rate=rat;
        vote=vot;
        id=id1;
        next=NULL;
    }


    void vote1(int d){
    vote=d;
    }
    void rate1(int rat){
    rate=rat;

    }
    void id1(string id1)
    {
        id=id1;
    }



    void next1(NODE *n){
    next=n;

    }
    int getvote(){
    return vote;}
    NODE* getnext(){
    return next;}

    float getrate()
    {
        return rate;
    }
    string getid()
    {
        return id;
    }

};


class linklist
{

public:
NODE* first;


linklist(){
first=NULL;
}
void adder(int vot, float rat, string id);
void findindex(float d);
int remval(float d);
void display();
};
 void linklist::adder(int vot, float rat, string id)
{
        NODE *temp=new NODE(vot,rat,id);
        NODE *temp2=first;

        if(first==NULL)
        {
            first=temp;
            return;
        }
        else{

            while(temp2!=NULL)
            {


                if(temp2->getnext()==NULL)
                {

                    temp2->next1(temp);
                    break;
                }
            else{temp2=temp2->getnext();}

            }

    }
}


void linklist::findindex(float d){
        NODE*temp=first;
        int x;

        int counter=0;



        if(first->getrate()==d)
        {
           cout<<"exist"<<endl;
}
        else{

    while(temp->getrate()!=d)
    {


        counter++;

        if(temp->getnext()==NULL)
        {   x=-1;
            cout << "exist" << endl;
            break;
        }
        temp=temp->getnext();


    }
if(x!=-1){
cout << counter << endl;}



    }


}




















int linklist::remval(float d){


       NODE* temp=first;
       if(temp->getrate()==d)
       {
           first=temp->getnext();
           return 1;
       }
       else{
        while(2)
        {
            if(temp->getnext()->getrate()==d)
            {
                temp->next1(temp->getnext()->getnext());
                return 1;
                //break;
            }
            else
            {
                    temp=temp->getnext();

            }
        }

        }



       }







void linklist::display()
    {
if(first==NULL)
{
    return;
}
        NODE* temp=first;
        cout <<"----------------"<< endl;
        while(temp!=NULL)
        {

            cout<<temp->getvote()<<endl;
            cout<<temp->getid()<<endl;
            cout<<temp->getrate()<<endl;
            temp=temp->getnext();


        }

    }




































