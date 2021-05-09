class MyLinkedList {
     struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            data=0;
            next=NULL;
            prev=NULL;
        }
        Node(int val)
        {
            data=val;
            next=NULL;
            prev=NULL;
        }
    };
    Node* head;
    Node* tail;
    int size;
   // Node* Index[1000];
public:

    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        tail=head;
        size=0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>size-1)
            return -1;
        Node* temp;
        temp=head;
        for(int i=0;i<index;i++)
            temp=temp->next;
        return temp->data;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(tail==NULL)
        {
            Node* newNode=new Node(val);
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        Node* newNode=new Node(val);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(tail==NULL)
        {
            Node* newNode=new Node(val);
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        Node* newNode=new Node(val);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        if(index==size)
            addAtTail(val);
        else if(index==0)
            addAtHead(val);
        else
        {
            Node* temp;
            temp=head;
            for(int i=0;i<index-1;i++)
            temp=temp->next;
            Node* nextNode;
            nextNode=temp->next;
            Node* newNode=new Node(val);
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next=nextNode;
            nextNode->prev=newNode;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0){
            Node* temp;
            temp=head;
            head=head->next;
            delete(temp);
            size--;
        }
        else if(index>=size)
            return;
        else if(index==size-1)
        {
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete(temp);
            size--;
        }
        else
        {
            Node* temp;
            temp=head;
            for(int i=0;i<index-1;i++)
            {
                temp=temp->next;
            }
            Node* nextNode;
            nextNode=temp->next;
            temp->next=nextNode->next;
            temp->next->prev=temp;
            delete(nextNode);
            size--;

        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
