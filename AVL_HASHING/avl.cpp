#include<iostream>
#include <fstream>
#include <string>
using namespace std;


class NODE{

int vote;
float rate;
string id;
NODE* left;
NODE* right;
int height;
public:
    NODE()
    {
        vote=0;
        rate=0;
        left=NULL;
        right=NULL;
        height=0;

    }
    NODE(int vot, float rat, string id1)
    {
        rate=rat;
        vote=vot;
        id=id1;
        left=NULL;
        right=NULL;
        height=0;
    }
    void height1(int h)
    {
        height=h;
    }
    int getheight()
    {
        return height;
    }

    void vote1(int d){
    vote=d;
    }
    void rate1(float rat){
    rate=rat;

    }

    void id1(string id1)
    {
        id=id1;
    }
    void right1(NODE *n){
    right=n;

    }
    void left1(NODE *n)
   {

   left=n;}


    float getrate()
    {
        return rate;
    }
    string getid()
    {
        return id;
    }
     NODE* getright(){
    return right;}
    NODE* getleft(){
    return left;}
    int getvote(){
    return vote;}

};
class AVL
{
   public:
       NODE* root;

       AVL()
       {
           root=NULL;
       }
       NODE* getroot()
       {
           return root;
       }
       void setroot(NODE* temp)
       {
           root=temp;
       }


NODE* adderrec(NODE* root,int vot, float rat, string id1);
void disp_I(NODE* node);
int max(int a, int b);
int height(NODE* node);
int getbf(NODE* node);
void add(int vot, float rat, string id1);
NODE* rotate_right(NODE* node);
NODE* rotate_left(NODE* node);
NODE* left_right(NODE* node);
NODE* right_left(NODE* node);
int search(NODE* node,int vot);
void last_value(NODE* node);
void last_value1(NODE* node);
int minvalue(NODE* node);
void smallest(NODE* temp);
void largest(NODE* temp);
};
void AVL::last_value(NODE* node)
{
    NODE* node2=node;
    node=node->getleft();
    NODE* node1;


    while(node->getright()!=NULL)
    {   node1=node;
        node=node->getright();
    }
if(root->getvote()!=node2->getvote())
   {int a=node->getvote();
    cout << node2->getvote() << "---" << endl;
    node1->right1(NULL);
    node2->vote1(a);}
else if(root->getvote()==node2->getvote())
{
    node->left1(root->getleft());
    node->right1(root->getright());
    root->left1(NULL);
    root->right1(NULL);
    root=node;
    node1->right1(NULL);

}

}

void AVL::last_value1(NODE* node)
{
    NODE* node2=node;
    node=node->getright();
    NODE* node1;

    while(node->getleft()!=NULL)
    {   node1=node;
        node=node->getleft();
    }
    int a=node->getvote();
    node1->left1(NULL);
    node2->vote1(a);

}









NODE* AVL::rotate_right(NODE* node)
{



NODE* n2=node->getleft();
node->left1(n2->getright());
 n2->right1(node);
 n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
 node->height1(max(height(node->getleft()),height(node->getright()))+1);


 return n2;

}


NODE* AVL::left_right(NODE* node)
 {
   NODE* n2=node->getleft();

   node->left1(n2->getright());
   n2->right1(NULL);
   node->getleft()->left1(n2);


   return rotate_right(node);

}

NODE* AVL::right_left(NODE* node)
{

   NODE* n2=node->getright();

   node->right1(n2->getleft());
   n2->left1(NULL);
   node->getright()->right1(n2);


   return rotate_left(node);

}






















NODE* AVL::rotate_left(NODE* node)
{



NODE* n2=node->getright();
node->right1(n2->getleft());
n2->left1(node);
n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
node->height1(max(height(node->getleft()),height(node->getright()))+1);


return n2;

}


int AVL:: search(NODE* node,int vot)
{

    if (node->getvote()==vot)
       return node->getvote();



    if (node->getvote()<vot)
        return search(node->getright(), vot);






    return search(node->getleft(), vot);
}
int AVL::minvalue(NODE* node)
{


    while(node->getleft()!=NULL)

       {node=node->getleft();}

    return node->getvote();
}




int AVL::getbf(NODE* node)
{
  return     height(node->getleft())-height(node->getright());
}

void AVL::smallest(NODE* temp)
{




    while(temp!=NULL)
    {
        if(temp->getleft()==NULL)
        {
            disp_I(temp);
            break;

        }
        temp=temp->getleft();
    }




}



void AVL::largest(NODE* temp)
{




    while(temp!=NULL)
    {
        if(temp->getright()==NULL)
        {
            disp_I(temp);
            break;

        }
        temp=temp->getright();
    }




}






















int AVL::max(int a, int b)
{
    if(a>b)
    {return a;}
    else if(a<b){return b;}
    else{return b;}
}

int AVL::height(NODE* node)
{
    if(node==NULL)
    {
        return -1;
    }
   else
   {return node->getheight();}
}

void AVL::disp_I(NODE* temp2)
{

    if(temp2==NULL)
        return;
    else
    {

         disp_I(temp2->getleft());
         cout << temp2->getid() << " " << temp2->getrate() << " " << temp2->getvote() << endl;

         disp_I(temp2->getright());

    }
}

void AVL:: add(int vot, float rat, string id1)
{
    setroot(adderrec(root,vot,rat,id1));
}







NODE* AVL::adderrec(NODE* temp2,int vot, float rat, string id1)
{

    if(temp2==NULL)
    {
         temp2=new NODE(vot,rat,id1);
    }
    else if(vot<=temp2->getvote())
        {

            temp2->left1(adderrec(temp2->getleft(),vot,rat,id1));

            int bf=getbf(temp2);
           if(bf==2 || bf==-2)
            {
                if(vot<temp2->getleft()->getvote())
                {
                   temp2=rotate_right(temp2);
                }
                else if(vot>temp2->getleft()->getvote())
                {

                   temp2=left_right(temp2);

                }

            }


        }
  else if(vot>temp2->getvote())
        {

             temp2->right1(adderrec(temp2->getright(),vot,rat,id1));
            int bf=getbf(temp2);
            if(bf==2 || bf==-2)
            {   ;
                if(vot>temp2->getright()->getvote())
                {
                   temp2=rotate_left(temp2);
                }
                else if(vot<temp2->getright()->getvote())
                {

                   temp2=right_left(temp2);

                }
            }
        }


temp2->height1(max(height(temp2->getleft()),height(temp2->getright()))+1);
return temp2;
}






















