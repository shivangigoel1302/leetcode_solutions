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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp && temp->val < x){
             prev = temp;
            temp = temp->next;
         }
        ListNode* prev2= prev;
        ListNode* n = temp;
        while(n){
            if(n->val < x){
                 ListNode* temp2 = n->next;
                 n->next = temp;
                if(prev){
                    prev->next = n;
                     prev = prev->next;
                }
                else{
                    head = n;
                    prev = head;
                }
              prev2->next = temp2;
              n = temp2;

            }
            else{
                prev2= n;
            n = n->next;

           }
        }

        return head;
    }
};
