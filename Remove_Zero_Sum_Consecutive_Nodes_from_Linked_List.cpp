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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int runsum = 0;
        auto dummy = ListNode(0,head);
        ListNode* curr = head;
        while(curr){
            runsum += curr->val;
            ListNode* check = &dummy;
            int checksum = runsum;
            while(check != curr){
                if(checksum == 0){
                    check->next = curr->next;
                    break;
                }
                check = check->next;
                checksum -= check->val;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
