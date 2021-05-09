/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node*head1=NULL;
        Node*tail=NULL;
    void insertattail(Node*&head,Node*&tail,int data)
    {
        if(head==NULL)
        {
            Node* n=new Node(data);
            head=n;
            tail=n;
            return;
        }
        Node*n=new Node(data);
        tail->next=n;
        n->prev=tail;
       tail=n;
    }
    void flat(Node*temp)
    {

        if(temp==NULL)
        {
            return;
        }
        insertattail(head1,tail,temp->val);
        if(temp->child)
        {
            flat(temp->child);
        }
        flat(temp->next);
    }
    Node* flatten(Node* head) {
        flat( head);
        return head1;
    }
};
