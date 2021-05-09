/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;
        Node* prev = new Node(0);
        Node* current = prev;
        map<Node*, Node*>m;
        while(it){
            current ->next = new Node(it->val);
            m[it] = current-> next;
            it = it->next;
            current = current->next;
        }
        it = head;
        current = prev->next;
        while(it){
            if(it->random){
                current->random = m[it->random];
            }
            it = it->next;
            current = current->next;
        }
        return prev->next;
    }
};
