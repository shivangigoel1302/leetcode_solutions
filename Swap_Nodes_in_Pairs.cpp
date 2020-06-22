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
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL||head->next==NULL)
            return head;
        ListNode* prev=NULL;ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            ListNode * temp=curr->next->next;
            ListNode * t=curr->next;
            t->next=curr;
            if(prev!=NULL){
                prev->next=t;
            }
            else{
                head=t;
            }
            prev=curr;
            curr=temp;
            prev->next=curr;
        }
        return head;
    }
};
