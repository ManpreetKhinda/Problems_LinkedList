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
    node*next;
    node*prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(node*&head, int val){
    node*n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
void insertattail(node*&head, int val){
    if(head==NULL){
        insertathead(head,val);
    }
    node*n=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void deleteathead(node*&head){
    node*todelete=head;
    head=head->next;
    head->prev=NULL;
    
    delete todelete;
}
void deletion(node*&head, int pos){
    if(pos==1){
        deleteathead(head);
        return ;
    }
    node*temp=head;
    int count =1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    

    delete temp;
}

node*reverserec(node*&head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*newhead=reverserec(head->next);
    
    head->prev=head->next;
    head->next->next=head;
    head->next=NULL;
    newhead->prev=NULL;
    
    return newhead;

}

void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
