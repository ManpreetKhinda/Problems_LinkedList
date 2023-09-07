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
void makecycle(node*&head,int pos){
    node*temp=head;
    node*startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

void removeloop(node*head){
    if(head==NULL){return; }
    node*fast=head;
    node*slow=head;
    while(fast &&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)break;
    }
    if(slow==head &&fast==head){
        while(slow->next!=fast){
            slow=slow->next;
        }
        slow->next=NULL;
        return;
    }
    if(slow==fast){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
bool isLoop(node*&head){
    if(!head)return false;
    node*fast=head->next;
    node*slow=head;
    while(fast!=slow){
        if(!fast||!fast->next)return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;

}

bool detectcycle(node* &head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL &&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

