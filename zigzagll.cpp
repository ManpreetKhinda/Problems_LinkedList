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

void zigzaglist(node*head){
    bool flag=true;
    node*curr=head;
    while(curr->next!=NULL){
        if(flag){
            if(curr->data > curr->next->data){
                swap(curr->data, curr->next->data);
            }
        }
        else{
            if(curr->data <curr->next->data){
                swap(curr->data, curr->next->data);
            }
        }
        curr=curr->next;
        flag!=flag;
    }

}