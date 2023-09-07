#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
node*reverse(node*&head){
    node*prev=NULL;
    node*curr=head;
    node*nextp;
    while(curr!=NULL){
        nextp=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nextp;
    }
    return prev;
}
node*reverserec(node*&head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*newhead=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node*reversek(node*&head,int k){
    node*prev=NULL;
    node*curr=head;
    node*nextp;
    int count=0;
    while(curr!=NULL&&count<k){
        nextp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextp;
        count++;
    }
    if(nextp!=NULL){
    head->next=reversek(nextp,k);
    }
    return prev;
}
void reverselist(node*&head){
    node*prev=NULL,*curr=head,*next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void rearrange(node*&head){
    node*slow=head,*fast=slow->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    node*head1=head;
    node*head2=slow->next;
    slow->next=NULL;
    reverselist(head2);
    head=new node(0);
    node*curr=head;
    while(head1||head2){
        if(head1){
            curr->next=head1;
            curr=curr->next;
            head1=head1->next;
        }
        if(head2){
            curr->next=head2;
            curr=curr->next;
            head2=head2->next;
        }
    }
    head=head->next;
}
