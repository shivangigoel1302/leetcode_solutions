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
    TreeNode*first;
        TreeNode*second;
    TreeNode*prev;
    void traverse(TreeNode*root)
    {
        if(root==NULL)
        {
            return;
        }
        traverse(root->left);
        if(prev->val>root->val && first==NULL)
        {
            first=prev;
        }
        if(prev->val>root->val && first!=NULL)
        {
            second=root;
        }
        prev=root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
      prev=new TreeNode(INT_MIN);
        first=NULL;
        second=NULL;
        traverse(root);
        swap(first->val,second->val);
    }
};
