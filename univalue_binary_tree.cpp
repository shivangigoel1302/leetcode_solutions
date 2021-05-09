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
    bool isEqual(TreeNode* root, int parent){
        if(root==NULL){
            return true;
        }
        if(root->val!=parent){
            return false;
        }
        return isEqual(root->left,parent) && isEqual(root->right,parent);
    }
    bool isUnivalTree(TreeNode* root) {
      int parent = root->val ;
        if(isEqual(root,parent)){
            return true;
        }
        return false;
    }
};
