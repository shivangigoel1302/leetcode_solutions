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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        ListNode* temp = head;
        while(temp!= NULL){
            ListNode* n = temp->next;
            int val = 0;
            while(n!= NULL && n->val <= temp->val){
                n= n->next;
            }
            if(n) v.push_back(n->val);
            else{
                v.push_back(0);
            }
            temp = temp->next;
        }
        return v;
    }
};
