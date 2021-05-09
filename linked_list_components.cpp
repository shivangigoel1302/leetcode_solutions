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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int>s;
        for(int i = 0 ; i < G.size(); i++){
            s.insert(G[i]);
        }
        vector<bool>v;
        ListNode* temp = head;
        while(temp){
            if(s.find(temp->val) == s.end()){
                v.push_back(false);
            }
            else{
                v.push_back(true);
            }
            temp = temp->next;
        }
        int count = 0 ;
        for(int i = 0 ; i < v.size();){
            if(v[i] == true){
                int j = i;
                while(v[j] == true){
                    j++;
                }
                count++;
                i = j;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
