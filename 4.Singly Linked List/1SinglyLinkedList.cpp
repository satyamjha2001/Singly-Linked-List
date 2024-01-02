#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    void search(int);
    node *searchMySirg(int);
    void insertAfter(node *, int);
    void printlist();
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~SLL();
};
SLL::SLL()
{
    start = NULL;
}
void SLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void SLL::insertAtEnd(int data)
{
    node *n = new node, *temp;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
        start = n;
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
void SLL::search(int data)
{
    node *temp;
    int count = 0;
    int loc = 0;
    temp = new node;
    temp = start;
    while (temp != NULL)
    {
        if (temp->item == data)
        {
            count = 1;
            break;
        }
        loc++;
        temp = temp->next;
    }
    if (count == 1)
        cout << "Your data is present at position " << loc + 1 << " in the linked list" << endl;
    else
        cout << "Your data is not present in the linked list" << endl;
}
node *SLL::searchMySirg(int data)
{
    node *t;
    t = start;
    while (t != NULL)
    {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return NULL;
}
void SLL::insertAfter(node *temp, int data)
{
    if (temp != NULL)
    {
        node *n = new node;
        n->item = data;
        n->next = temp->next;
        temp->next = n;
    }
}
void SLL::deleteFirst()
{
    node *temp;
    if (start != NULL)
    {
        temp = start->next;
        delete start;
        start = temp;
    }
}
void SLL::deleteLast()
{
    node *temp;
    if (start != NULL)
    {
        temp = start;
        if (temp->next == NULL)
        {
            delete temp;
            start == NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
}
void SLL::deleteNode(int data)
{

    node *t,*temp;
    if(start)
    {
        t=start;
        if(t->item==data)
        {
            start=start->next;
            delete t;
        }
        else
        {
            while(t->next!=NULL)
            {
                if(t->next->item==data)
                {
                    temp=t->next;
                    t->next=temp->next;
                    delete temp;
                    break;
                }
                t=t->next;
            }
        }
    }
}
void SLL::printlist()
{
    node *temp = new node;
    temp = start;
    while (temp != NULL)
    {
        cout << temp->item << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
SLL::~SLL()
{
    while(start)
      deleteFirst();
}
int main()
{
    SLL s1, s2;
    s1.insertAtStart(5);
    s1.insertAtStart(4);
    s1.insertAtStart(3);
    s1.insertAtStart(2);
    s1.insertAtStart(1);
    s1.insertAtEnd(6);
    s2.insertAtEnd(1);
    s2.insertAtEnd(2);
    s1.printlist();
    s2.printlist();
    // s1.search(3);
    // s2.search(3);
    // node* temp=s1.searchMySirg(3);
    // s1.insertAfter(temp,7);
    // s1.printlist();
    s1.deleteFirst();
    s1.deleteLast();
    s1.deleteNode(4);
    s1.printlist();
    return 0;
}