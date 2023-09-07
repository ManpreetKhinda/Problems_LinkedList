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
void insertathead(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
        
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertattail(node*&head, int val){
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    node*n =new node(val);
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteathead(node*&head){
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node*todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}
void deletion(node*&head, int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    node*temp=head;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}
void display(node*head){
    node*temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=head);
    cout<<endl;
}
///Put even postion nodes after odd position nodes
void evenafterodd(node*&head){
    node*odd=head;
    node*even=head->next;
    node*evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;



    }
    odd->next=evenstart;
    if(odd->next!=NULL){
        even->next=NULL;    
    }
    
}