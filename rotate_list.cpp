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
int length(ListNode*head)
{
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       int l=length(head);
        if(head==NULL)
       {
           return NULL;
       }
        if(head->next==NULL)
        {
            return head;
        }
        k=k%l;
        while(k>0)
        {
            ListNode*temp=head;
          while(temp->next->next!=NULL)
         {
            temp=temp->next;
         }
         ListNode*temp1=head;
         while(temp1->next!=NULL)
         {
            temp1=temp1->next;
         }
          temp->next=NULL;
            temp1->next=head;
            head=temp1;
            k--;
        }
        return head;
    }
};
