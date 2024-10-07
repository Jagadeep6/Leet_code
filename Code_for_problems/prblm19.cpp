#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* remove_nth(ListNode* head, int n)
{
    ListNode* temp = head;
    ListNode* ahead = temp;
    ListNode* behind = temp;
    for(int i = 0; i < n; i++)
    {
        ahead = ahead-> next;
    }
    if(ahead == NULL)
    {
        temp = head-> next;
        return temp;
    }
    while(ahead -> next != NULL)
    {
        ahead = ahead->next;
        behind = behind -> next;
    }
    behind -> next = behind ->next -> next;
    return head;
    //  ListNode* temp=new ListNode();
    //     temp->next=head;

    //     ListNode* fast=temp;
    //     ListNode* slow=temp;

    //     for(int i=1;i<=n;i++){
    //          fast=fast->next;
    //     }

    //     while(fast->next!=NULL){
    //         fast=fast->next;
    //         slow=slow->next;
    //     }

    //     ListNode* gaya=slow->next;
    //     slow->next=slow->next->next;
    //     delete(gaya);
        
    //     return temp->next;
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp -> next = new ListNode(x);
        temp = temp-> next;
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << endl;
    ListNode* new_head = remove_nth(head, 1);
    temp = new_head;
    if(temp == NULL)
    {
        cout << "empty";
    }
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    return 0;
}