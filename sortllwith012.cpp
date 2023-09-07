#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void sortlist(node*head){
    int count[3]={0,0,0};
    node*ptr=head;
    while(ptr!=NULL){
        count[ptr->data]++;
        ptr=ptr->next;
    }
    int i=0;
    ptr=head;
    while(ptr!=NULL){
        if(count[i]==0){
            ++i;
        }
        else{
            ptr->data=i;
            --count[i];
            ptr=ptr->next;
        }

    }

}
