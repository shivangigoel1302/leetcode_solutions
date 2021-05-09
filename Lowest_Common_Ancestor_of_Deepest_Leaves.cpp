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
    TreeNode* result ;
     int maxDepth = INT_MIN;
    int helper(TreeNode* root, int depth){
        if(root == NULL){
            return depth;
        }
        int left = helper(root->left,depth+1);
        int right = helper(root->right,depth+1);
        if(left == right){
            if(left>= maxDepth){
                result = root;
                maxDepth = left;
            }
        }
        return max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         result = NULL;

        helper(root,0);
        return result;
    }
};
