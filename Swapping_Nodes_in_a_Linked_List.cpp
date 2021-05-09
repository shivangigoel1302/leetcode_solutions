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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*n=head;
        ListNode*s=head;
        while(k > 1){
            n=n->next;
            s=s->next;
            k--;
        }
        n = n->next;
        ListNode* end = head;
        while(n){

            n=n->next;
            end = end->next;
        }
        int temp = s->val;
        s->val = end->val;
        end->val = temp;
        return head;
    }
};
