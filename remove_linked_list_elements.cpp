class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if(!head) return NULL; //List is empty

        ListNode *res=head, *prev=NULL, *temp=NULL;

        while(head){
            temp=head->next;
            if(head->val==val){
                if(prev) prev->next=head->next; //Connecting previous node to next.
                else res=head->next; //Avoiding the current node in result.
                delete head; //Deleting current node.
            }else prev=head; //Setting Previous node.
            head=temp;
        }

        return res;
    }
};
