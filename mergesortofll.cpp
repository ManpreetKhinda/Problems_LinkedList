#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void mergesort(node*&headref){
    node*head=headref;
    node*a;
    node*b;
    if((head==NULL)||(head->next==NULL)){
        return ;
    }
    frontbacksplit(head,a,b);
    mergesort(a);
    mergesort(b);
    headref=sortedmerge(a,b);
}
node*sortedmerge(node*a,node*b){
    node*res=NULL;
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    if(a->data<=b->data){
        res=a;
        res->next=sortedmerge(a->next,b);
    }
    else{
        res=b;
        res->next=sortedmerge(a,b->next);
    }
    return res;
}
void frontbacksplit(node*source,node*&front, node*&back){
    node*fast;
    node*slow;
    slow=source;
    fast=source->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    front=source;
    back=slow->next;
    slow->next=NULL;
}

/*
second approach*/

node*merge(node*firstnode,node*secondnode){
    node*merged=new node;
    node*temp=new node;
    merged=temp;
    while(firstnode!=NULL && secondnode!=NULL){
        if(firstnode->data<=secondnode->data){
            temp->next=firstnode;
            firstnode=firstnode->next;
        }
        else{
            temp->next=secondnode;
            secondnode=secondnode->next;
        }
        temp=temp->next;
    }
    while(firstnode!=NULL){
        temp->next=firstnode;
        firstnode=firstnode->next;
        temp=temp->next;
    }
    while(secondnode!=NULL){
        temp->next=secondnode;
        firstnode=firstnode->next;
        temp=temp->next;
    }
    return merged->next;
}
node*middle(node*head){
    node*slow=head;
    node*fast=head->next;
    while(!slow->next &&(!fast&&!fast->next)){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node*sort(node*head){
    if(head->next==NULL){
        return head;
    }
    node*mid=new node;
    node*head2=new node;
    mid=middle(head);
    head2=mid->next;
    mid->next=NULL;
    node*finalhead=merge(sort(head),sort(head2));
    return finalhead;
}
