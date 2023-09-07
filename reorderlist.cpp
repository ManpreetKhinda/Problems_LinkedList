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

void reorder(node*head){
    node*p=head;
    vector<node*> v;
    int l,i;
    while(p!=NULL){
        v.push_back(p);
        p=p->next;
    }
    l=v.size();
    p=head;
    rep(i,0,l/2){
        if(i!=0){
            p->next=v[i];
            p=p->next;
        }
        p->next=v[l-i-1];
        p=p->next;
    }
    if(l%2==1){
        p->next=v[i];
        p=p->next;
    }
    p->next=NULL;

}
