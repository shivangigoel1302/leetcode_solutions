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
    vector<int> postorder(Node* root) {
        vector<int>v;
        stack<Node*>s;
        if(root==NULL){
            return v;
        }
        s.push(root);
        while(!s.empty()){
            Node* p=s.top();
            v.push_back(p->val);
            s.pop();
            for(int i=0;i<p->children.size();i++){
                s.push(p->children[i]);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
