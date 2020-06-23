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
    int sum;
    int sumfunc(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=sumfunc(root->left);
        int right=sumfunc(root->right);
        int without=max(max(left,right)+root->val,root->val);
        int with=max(without,left+right+root->val);
        sum=max(sum,with);
        return without;
    }
    int maxPathSum(TreeNode* root) {
       sum=INT_MIN;
        sumfunc(root);
        return sum;
    }
};
