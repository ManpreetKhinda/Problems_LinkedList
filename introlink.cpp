#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertathad(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deletehead(node *&head)
{
    node *toerase = head;
    head = head->next;
    delete toerase;
}
void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next)
    {
        deletehead(head);
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toerase = temp->next;
    temp->next = temp->next->next;
    delete toerase;
}
void deleteNode(node *node)
{
   *node = *(node->next);
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

string genearator(node* head, string s){
    while(head!=NULL){
        s+=to_string(head->data);
        head=head->next;

    }
    return s;
}

int main()
{
    node *head = NULL;
    node*head2  =NULL;
    string s="";
    
    insertattail(head, 9);
    insertattail(head, 4);
    insertattail(head, 6);
    insertattail(head2, 8);
    insertattail(head2, 4);
    string s1=genearator(head,s);
    string s2=genearator(head2,s);
    int n1=stoi(s1);
    int n2=stoi(s2);
    cout<<n1*n2;
    
    
    return 0;
}