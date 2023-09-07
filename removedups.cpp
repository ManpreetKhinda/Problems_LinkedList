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

void removedups(node* head){
    node*ptr1, *ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->data==ptr2->next->data){
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
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
    node*curr=head;
    node*index=NULL;
    while(curr!=NULL){
        index=curr->next;
        while(index!=NULL){
            if(curr->data==index->data){
                curr->next=index->next;
                free(index);
                index=curr->next;
            }
            else{
                index=index->next;
            }
        }
        curr=curr->next;
    }
}
void removeDuplicates(node* head){
    unordered_set<int> us;
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL){
        if(us.find(curr->data)!=us.end()){
            prev->next=curr->next;
            delete(curr);
        }
        else{
            us.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }
}