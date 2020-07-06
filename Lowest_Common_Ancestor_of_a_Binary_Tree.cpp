/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*ans;
    bool lca(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(root==NULL)
        {
            return false;
        }
        int left=lca(root->left,p,q)?1:0;
        int right=lca(root->right,p,q)?1:0;
        int mid=(root==p||root==q)?1:0;
        if(mid+left+right>=2)
        {
            ans=root;
        }
        return (mid+left+right)>0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return ans;
    }
};
