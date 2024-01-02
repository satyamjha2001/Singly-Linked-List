#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int item;
    node *next;
    node(int data)
    {
        item = data;
        next = NULL;
    }
};
class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStart(int);
    void reverse();
    void printsll();
};
SLL::SLL()
{
    start = NULL;
}
void SLL::insertAtStart(int data)
{
    node *n = new node(data);
    n->next = start;
    start = n;
}
void SLL::reverse()
{
    node*prev,*temp,*curr;
    prev=NULL;
    curr=start;
    while(curr)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    start=prev;
}
void SLL::printsll()
{
    node* t=start;
    while(t!=NULL)
     { cout<<t->item<<" ";
        t=t->next;
     }
}

int main()
{
    SLL s1;
    while(1)
    {
    cout<<"\n1.Insert an item\n2.show data\n3.Reverse list\n4.Exit";
    int choice;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1: 
        int x;
        cout<<"\nEnter value to be inserted: ";
        cin>>x;
        s1.insertAtStart(x);
        break;
        case 2:
          s1.printsll(); break;
        case 3:
         s1.reverse(); break;
        case 4:
         exit(0); break;
        default:
        cout<<"\nInvalid choice"; 
    }
    }
    return 0;
}