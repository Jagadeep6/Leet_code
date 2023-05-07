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

ListNode* merge_sorted_list(ListNode* a, ListNode* b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    ListNode* ptr = a;
    if(a-> val > b-> val)
    {
        ptr = b;
        b = b->next;
    }
    else
    {
        a = a->next;
    }
    ListNode* curr = ptr;
    while(a and b)
    {
        if(a-> val < b-> val)
        {
            curr -> next = a;
            a = a->next;
        }
        else
        {
            curr -> next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    if(!a)
    {
        curr -> next = b;
    }
    else
    {
        curr->next = a;
    }

    return ptr;
}

ListNode* mergek(vector<ListNode*> lists)
{   
    ListNode* merge = NULL;
    if(lists.size() > 2)
    {
        merge = merge_sorted_list(lists[0], lists[1]);
        for(int i = 2; i < lists.size(); i++)
        {
            merge = merge_sorted_list(merge, lists[i]);
        }           
    }
    else
    {
        if(lists.size() == 0) return 0;
        else if(lists.size() == 1) return lists[1];
        else
        {
            return merge = merge_sorted_list(lists[0], lists[1]);
        }
    }

    return merge;
}
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
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

    cin >> x;
    ListNode* head_b = new ListNode(x);
    temp = head_b;
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp -> next = new ListNode(x);
        temp = temp-> next;
    }
    temp = head_b;
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << endl;

    ListNode* merged = merge_sorted_list(head, head_b);
    temp = merged;
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }

    return 0;

}