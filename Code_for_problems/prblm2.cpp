#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sol = new ListNode();
        ListNode* temp = sol;
        int car = 0;
        while(l1 != NULL or l2 != NULL or car != 0)
        {
            int sum = 0;
            if(l1 != NULL)
            {
                sum += l1 -> val;
                l1= l1-> next; 
            }
            if(l2 != NULL)
            {
                sum += l2 -> val;
                l2 = l2-> next;
            }
            sum += car;
            car = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp -> next = node;
            temp = temp -> next;
        }

        return sol->next;
    }
};

int main()
{

}