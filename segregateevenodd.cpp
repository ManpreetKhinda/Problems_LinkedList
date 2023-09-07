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
    node(int val){
        data=val;
        next=NULL;
    }
};

void segregateevenodd1(node*&head){
    node*evenstart=NULL;
    node*evenend=NULL;
    node*oddstart=NULL;
    node*oddend=NULL;
    node*currnode=head;

    while(currnode!=NULL){
        int val=currnode->data;
        if(val%2==0){
            if(evenstart==NULL){
                evenstart=currnode;
                evenend=evenstart;
            }
            else{
                evenend->next=currnode;
                evenend=evenend->next;
            }
        }
        else{
            if(oddstart==NULL){
                oddstart=currnode;
                oddend=oddstart;
            }
            else{
                oddend->next=currnode;
                oddend=oddend->next;
            }
        }
        currnode=currnode->next;
    } 
    if(oddstart==NULL||evenstart==NULL){
        return;
    }
    evenend->next=oddstart;
    oddend->next=NULL;
    head=evenstart;
}





void segregateevenodd(node*&head){
    node*tail=head;
    node*prev=NULL;
    node*curr=head;

    while(tail->next!=NULL){
        tail=tail->next;
    }
    node*end=tail;
    while(curr->data&1 && curr!=tail){
        end->next=curr;
        curr=curr->next;
        end->next->next=NULL;
        end=end->next;
    }
    if((curr->data)%2==0){
        head=curr;
        while(curr!=tail){
            if((curr->data)%2==0){
                prev=curr;
                curr=curr->next;

            }
            else{
                prev->next=curr->next;
                curr->next=NULL;
                end->next=curr;
                end=curr;
                curr=prev->next;
            }

        }
    }
    else{
        prev=curr;
    }
    if(end!=tail&&(tail->data)&2!=0){
        prev->next=tail->next;
        tail->next=NULL;
        end->next=tail;
        
    }
    return;


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
int main(){
    node*head=NULL;
    insertattail(head,17);
    insertattail(head,15);
    insertattail(head,8);
    insertattail(head,12);
    insertattail(head,10);
    insertattail(head,5);
    insertattail(head,4);
    insertattail(head,1);
    insertattail(head,17);
    insertattail(head,16);
    segregateevenodd(head);
    display(head);
}
