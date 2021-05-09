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
    bool helper(TreeNode*& root, int limit, int sum){
        if(root == NULL) return false;
        if(!root->left && !root->right){
            sum += root->val;
            if ( sum < limit){
                root = NULL;
                return false;
            }
            return true;
        }
        bool l = helper(root->left,limit,sum + root->val);
        bool r = helper(root->right,limit,sum+root->val);

        if(!l && !r){
            root = NULL;
            return false;
        }
        return true;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        helper(root,limit,0);
        return root;
    }
};
