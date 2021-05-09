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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1 = list1;
        while( l1 && a > 1){
            l1 = l1->next;
            a--;
        }
        ListNode* l2= list1;
        while(b >= 0){
            l2 = l2->next;
            b--;
        }
        ListNode* x = l1->next;
        l1->next = list2;
        ListNode* temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = l2;
        delete x;
        return list1;
    }
};
