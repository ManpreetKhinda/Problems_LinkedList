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

class node
{
public:
    int data;
    node *next;
    // node(int val)
    // {
    //     data = val;
    //     next = NULL;
    // }
};

node *createlist(int *arr, int n)
{
    node *head = NULL;
    node *p;
    int i;
    rep(i, 0, n)
    {
        if (head == NULL)
        {
            head = p = new node();
        }
        else
        {
            p->next = new node();
            p = p->next;
        }
        p->data = arr[i];
    }
    return head;
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
int main()
{
    int arr1[] = {10, 5, 12, 7, 11};
    node *head = createlist(arr1, sizeof(arr1) / sizeof(arr1[0]));
    display(head);
    return 0;
}
