/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string>v;
    void paths(vector<string>&v,string s,TreeNode*root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->right==NULL&&root->left==NULL)
        {
            if(s.size()==0)
            {
                s+=to_string(root->val);
            }
            else
            {
                s+="->"+to_string(root->val);
            }
            v.push_back(s);
        }
         if(s.size()==0)
            {
                s+=to_string(root->val);
            }
            else
            {
                s+="->"+to_string(root->val);
            }

        paths(v,s,root->left);
        paths(v,s,root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
       paths(v,s,root);
        return v;
    }
};
