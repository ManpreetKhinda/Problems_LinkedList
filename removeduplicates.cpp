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
void removeduplicate(node * head){
    node*ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL&& ptr1->next!=NULL){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->data==ptr2->next->data){
                dup=ptr2->next;
                ptr2->next=dup->next;
                delete(dup);
            }
            else{
                ptr2=ptr2->next;
            }

        }
        ptr1=ptr1->next;
    }
}

void sortlist(node*head){
    node*current=head;
    node*index=NULL;
    while(current!=NULL){
        index=current->next;
        while(index!=NULL){
            if(current->data==index->data){
                current->next=index->next;
                free(index);
                index=current->next;
            }
            else{
                index=index->next;
            }
        }
        current=current->next;
    }
}

void removedups(node*head){
    unordered_set<int> seen;
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL){
        if(seen.find(curr->data)!=seen.end()){
            prev->next=curr->next;
            delete(curr);
        }
        else{
            seen.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }


}

