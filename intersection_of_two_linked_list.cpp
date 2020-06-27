/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode*head)
{
    int count=1;
    ListNode*temp=head;
    while(temp->next)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        int l1=length(headA);
        int l2=length(headB);
        int ahead=l2-l1;
        ListNode*slow;
        ListNode*fast;
        if(ahead>0)
        {
            slow=headB;
           fast=headA;
            while(ahead)
            {
                slow=slow->next;
                ahead--;
            }
        }
        else
        {
         slow=headA;
           fast=headB;
            while(ahead<0)
            {
                slow=slow->next;
                ahead++;
            }
        }
        while(slow!=NULL)
        {
            if(slow==fast)
            {
                return slow;
            }
            slow=slow->next;
            fast=fast->next;

        }
        return NULL;
    }
};
