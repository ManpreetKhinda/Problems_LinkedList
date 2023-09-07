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

vi a={4,3,7,8,2,6,1};
int n=a.size();
void zigzag(vi &a,int n){
    sort(a.begin(),a.end());
    for(int i=1;i<n-1;i+=2){
        swap(a[i],a[i+1]);
    }
}
void zigzag2(vi &a,int n){
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(flag){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
            }

        }
        else{
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
        flag=!flag;
    }

}
void zigzaglist(node*head){
    bool flag=true;
    node*current=head;
    while(current->next!=NULL){
        if(flag){
            if(current->data>current->next->data){
                swap(current->data,current->next->data);
            }
        }
        else{
            if(current->data<current->next->data){
                swap(current->data,current->next->data);
            }
        }
        current=current->next;
        flag!=flag;
    }

}


int main(){
    zigzag(a,n);
    for(auto i:a){
        cout<<i<<" ";
    }
    

}