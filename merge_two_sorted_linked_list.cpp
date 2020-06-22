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
ListNode* mergelinkedlist(ListNode*l1,ListNode*l2)
{
   if(!l1)
   {
       return l2;
   }
    else if(!l2)
    {
        return l1;
    }
    ListNode*newhead=NULL;
    if(l1->val<=l2->val)
    {
        newhead=l1;
        newhead->next=mergelinkedlist(l1->next,l2);
    }
    if(l2->val<l1->val)
    {
        newhead=l2;
        newhead->next=mergelinkedlist(l1,l2->next);
    }
    return newhead;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode*ans=mergelinkedlist(l1,l2);
        return ans;
    }
};
