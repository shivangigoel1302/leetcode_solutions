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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode*header=head;
        ListNode*prev=NULL;
        while(head!=NULL&&head->next)
        {
            prev=head;
            head=head->next;
            while(prev->val==head->val)
            {
                prev->next=head->next;
                if(head->next)
                {
                    head=head->next;
                }
                else
                {
                    break;
                }
            }
        }
        return header;
    }
};
