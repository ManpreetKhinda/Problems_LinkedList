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
    node* next,*arbit;
    node(int val){
        data=val;
        next=NULL;
        arbit=NULL;
    }
};
void mergesort(node*&headref){
    node*head=headref;
    node*a,*b;
    if(head==NULL||(head->arbit==NULL)){
        return;
    }
    frontbacksplit(head,a,b);
    mergesort(a);
    mergesort(b);
    headref=sortedmerge(a,b);
}
node*sortedmerge(node*a,node*b){
    node*result=NULL;
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    if(a->data<=b->data){
        result=a;
        result->arbit=sortedmerge(a->arbit,b);
    }
    else{
        result=b;
        result->arbit=sortedmerge(a,b->arbit);
    }
    return result;
}
void frontbacksplit(node*source,node*front, node*back){
    node*fast,*slow;
    if(source==NULL||source->arbit==NULL){
        front=source;
        back=NULL;
        return;
    }
    slow=source,fast=source->arbit;
    while(fast!=NULL){
        fast=fast->arbit;
        if(fast!=NULL){
            slow=slow->arbit;
            fast=fast->arbit;
        }
    }
    front=source;
    back=slow->arbit;
    slow->arbit=NULL;
}

