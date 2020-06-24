/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                fast=fast->next;
                slow=slow->next;
                if(slow==fast)
                {
                    slow=head;
                    while(fast)
                    {
                        if(slow==fast)
                        {
                            return fast;
                        }
                         slow=slow->next;
                        fast=fast->next;
                    }
                }
            }
        }
        return NULL;
    }
};
