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
    bool ans;
    int length(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=length(root->left);
        int r=length(root->right);
        if(abs(l-r)>1)
        {
            ans=false;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
      ans=true;
        if(root==NULL)
        {
            return true;
        }
        length(root);
        return ans;
    }
};
