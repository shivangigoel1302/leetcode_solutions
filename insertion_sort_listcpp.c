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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next ==NULL){
            return head;
        }
        ListNode* n = head->next;
      ListNode* prev2 = head;
        ListNode*temp = n->next;
        while(n){
             ListNode* prev = NULL;
        ListNode* curr = head;
            while(curr && curr->val < n->val){
                prev = curr;
                curr = curr->next;
            }
            if(curr == n){
                if(temp){
                    temp = temp->next;
                }
                n = n->next;
                prev2 = prev2->next;
                continue;
            }
            if(prev){
                prev->next = n;
            }
            else{
                head = n;
            }
            n->next = curr;
            prev2->next = temp;
            n = temp;
            if(temp!=NULL){
                temp = temp->next;
            }
        }
        return head;
    }
};
