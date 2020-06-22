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
    bool isValidBST(TreeNode* root,long long int minval=-10000000000,long long int maxval=10000000000) {
        if(root==NULL)
        {
            return true;
        }
        // if(root->val==INT_MAX||root->val==INT_MIN)
        // {
        //     return true;
        // }
        if(root->val<maxval&&root->val>minval&& isValidBST(root->left,minval,root->val)&&isValidBST(root->right,root->val,maxval))
        {
            return true;
        }
        return false;
    }
};
