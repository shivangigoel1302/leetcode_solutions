/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*middle(ListNode*head)
    {
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reverse(ListNode*&n)
    {
        ListNode*prev=NULL;
        ListNode*t=n;
        while(t)
        {
            ListNode*ne=t->next;
            t->next=prev;
            prev=t;
            t=ne;
        }
        n=prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
        {
            return true;
        }
        if(head->next==NULL)
        {
            return true;
        }
        ListNode*mid=middle(head);
        ListNode*n=mid->next;
        mid->next=NULL;
        reverse(n);
        ListNode*temp=n;
        ListNode*temp2=head;
        while(temp&&temp2)
        {
            if(temp2->val!=temp->val)
            {
                return false;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        return true;
    }
};
