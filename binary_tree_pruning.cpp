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
    bool helper(TreeNode* &root){
        if(root == NULL){
            return false;
        }
        bool left = helper(root->left);
        bool right = helper(root->right);
       bool actual = left || right || root->val == 1;
        if(!actual){
            root = NULL;
            return false;
        }
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
