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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
   ListNode* h=NULL;
    Solution(ListNode* head) {
       h=head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int i=1;
        auto curr=h;
        auto ans=h;
        while(curr)
        {
            if(rand()%i==0)
            {
                ans=curr;
            }
            i++;
            curr=curr->next;
        }
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
