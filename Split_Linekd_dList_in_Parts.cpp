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
    int findlen(ListNode* root){
        ListNode* curr = root;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = findlen(root);
        int splitlen = length/k;

        int remain = length%k;

        vector<ListNode*>ans;
        ListNode* start = root;
        while(k > 0){
            int len = splitlen + (remain >0 ? 1 : 0);

            len--;
            ListNode* temp = root;
            ans.push_back(root);
            while(len-- && temp){
                temp = temp->next;
            }
            if(temp){
                ListNode* n = temp->next;
                temp->next = NULL;
                root = n;
            }
            remain--;
            k--;
        }
        return ans;
    }
};
