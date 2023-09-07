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
string s1="";
string s2="";


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
string genearator(node* head){
    while(head!=NULL){
        s1+=to_string(head->data);
        head=head->next;

    }
}
int main(){
    
}