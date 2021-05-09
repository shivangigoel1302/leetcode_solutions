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

    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
      int result=0;
       for(int i=0 ; i < root->children.size() ; i++){
              int ans=maxDepth(root->children[i]);
              result=max(ans,result);
          }
       return result+1;
    }
};
