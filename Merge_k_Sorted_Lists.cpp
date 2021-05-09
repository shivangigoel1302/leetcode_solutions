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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto list: lists){
            if(list){
                pq.push({list->val,list});
            }

        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            auto x = pq.top().second;
            pq.pop();
            if(head == NULL){
                head = x;
                tail = x;
            }
            else{
                tail->next = x;
                tail = x;
            }
            if(x->next) {
                pq.push({x->next->val,x->next});
            }
        }
        return head;
    }
};
