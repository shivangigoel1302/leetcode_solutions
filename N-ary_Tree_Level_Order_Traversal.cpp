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
    vector<vector<int>>v;
    void level(Node*root,int l)
    {
        if(root==NULL)
        {
            return ;
        }
        v.push_back({});
        v[l].push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            level(root->children[i],l+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        level(root,0);
        vector<vector<int>>final;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()!=0)
            {
                final.push_back(v[i]);
            }
        }
        return final;
    }
};
