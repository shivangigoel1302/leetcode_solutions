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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        ListNode* oddhead = head;
        ListNode* odd = head;
        ListNode* evenhead = head->next;
        ListNode* even = head->next;
        while(even && odd){
            odd->next = even->next;
            if(odd->next){
                 even->next = odd->next->next;
                 odd = odd->next;
            }
           else{
               even->next = odd->next;
           }
            even = even->next;
        }
        odd->next = evenhead;
        return oddhead;
    }
};
