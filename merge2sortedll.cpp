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
node*merge(node* &head1,node* &head2){
    node*p1=head1;
    node*p2=head2;
    node*dummynode=new node(-1);
    node*p3=dummynode;
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;


        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;

    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummynode->next;

}

node*mergerecursive(node*&head1,node*&head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node*result;

    if(head1->data < head2->data){
        result=head1;
        result->next=mergerecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergerecursive(head1,head2->next);

    }
    return result;
}