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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        int a = k;
        ListNode* temp = head;
        while(temp!= NULL && a >1){
            temp = temp->next;
            a--;
        }
        if(temp == NULL){
            return head;
        }
        while (current != NULL && count < k)
       {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
       }

       if (next != NULL){
          head->next = reverseKGroup(next, k);
       }
    return prev;
    }
};
