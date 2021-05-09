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
    int prev=INT_MIN;
    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        helper(root->right);
        if(prev==INT_MIN){
            prev=root->val;
        }
        else{
            root->val=root->val+prev;
            prev=root->val;
        }
        helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};
