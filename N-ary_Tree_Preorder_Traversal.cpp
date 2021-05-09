/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>v;
        stack<Node* >s({root});
        while(!s.empty()){
            auto p=s.top();
            s.pop();
            if(p==NULL){
                continue;
            }
            v.push_back(p->val);
            for(int i=p->children.size()-1;i>=0;i--){
                s.push(p->children[i]);
            }
        }
        return v;
    }
};
