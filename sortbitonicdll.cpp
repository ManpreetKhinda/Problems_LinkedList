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
    node*prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void reverse(node*head){
    node*temp=NULL;
    node*curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL){
        head=temp->prev;

    }
}
node*merge(node*first,node*second){
    if(!first){
        return second;
    }
    if(!second){
        return first;
    }
    if(first->data<second->data){
        first->next=merge(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }
    else{
        second->next=merge(first,second->next);
        second->next->prev=second;
        second->prev=NULL;
        return second;
    }
}

node*sort(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*curr=head->next;
    while(curr!=NULL){
        if(curr->data<curr->prev->data){
            break;
        }
        curr=curr->next;
    }
    if(curr==NULL){
        return head;
    }
    curr->prev->next=NULL;
    curr->prev=NULL;
    reverse(curr);
    return merge(head,curr);
}