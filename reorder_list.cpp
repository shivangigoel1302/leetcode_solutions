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
ListNode* reverse(ListNode*node)
{
   ListNode*prev=NULL;
    while(node)
    {
        ListNode*temp=node->next;
        node->next=prev;
        prev=node;
        node=temp;
    }
    return prev;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL)
        {
            return;
        }
        ListNode*fast=head->next;
    ListNode*slow=head;
    while(fast&&fast->next)
     {
        fast=fast->next->next;
        slow=slow->next;
     }
     ListNode*node=slow->next;
        slow->next=NULL;
        fast=reverse(node);
        slow=head;
        while(slow&&fast)
        {
            ListNode*n1=slow->next;
            ListNode*n2=fast->next;
            slow->next=fast;
            fast->next=n1;
            slow=n1;
            fast=n2;
        }

    }
};
