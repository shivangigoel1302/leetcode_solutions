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
    ListNode*temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void deleteatend(ListNode*head)
{
    ListNode*temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    ListNode*n=temp->next;
    temp->next=NULL;
    delete n;

}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=length(head);
        if(l==1)
        {
            return NULL;
        }
        int pos=l-n;
        if(pos==0)
        {
            ListNode*temp=head;
    head=head->next;
   delete temp;
            return head;
        }
        if(pos==l-1)
        {
            deleteatend(head);
            return head;
        }
        else
        {
            int p=1;
            ListNode*temp=head;
            while(p<pos)
            {
                temp=temp->next;
                p++;
            }
            ListNode*n=temp->next;
            temp->next=n->next;
            delete n;
            return head;
        }
    }
};
