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
    void helper(TreeNode*& root,int target){
        if(root==NULL){
            return ;
        }
        helper(root->left,target);
        helper(root->right,target);
        if(root->val==target){
            if(!root->left && !root->right){
                TreeNode* n= new TreeNode();
                n= NULL;
                root=n;
                return;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper( root, target);
        return root;
    }
};
