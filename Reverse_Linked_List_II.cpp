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
    ListNode* left;
    bool stop;
    void recurse(int m ,int n , ListNode* right){
        if(n == 1){
            return;
        }
        right = right->next;
        if(m > 1){
            left = left->next;
        }
        recurse(m-1,n-1, right);
        if(right->next == left || left == right){
            stop = true;
            return;
        }
        if(!stop){
             int temp = right->val;

        right->val = left->val;
        left->val = temp;

        left = left->next;
        }

    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*right = head;
        left = head;
        stop = false;
        recurse(m,n,right);
        return head;
    }
};
