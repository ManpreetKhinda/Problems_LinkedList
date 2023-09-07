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

node*reverserec(node*&head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*newhead=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
void deleteNode(node *node)
{
   *node = *(node->next);
}
int length(node*head){
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;

    }
    return l;
}
node*removenth(node*head,int n){
    head=reverserec(head);
    int l=length(head);
    node*temp=head;
    n--;
    if(n==l){
        return head->next;
    }
    while(n){
        temp=temp->next;
        n--;
    }
    if(temp==head){
        head=head->next;
        delete temp;
    }
    else{
        deleteNode(temp);
    }
    head=reverserec(head);
    return head;
}
