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
    int ans=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    int helper(TreeNode* root, int h, int c){
       if(c==h){
           ans=root->val;
           return ans;
       }
        if(root->right){
            helper(root->right,h,c+1);
        }
        if(root->left){
            helper(root->left,h,c+1);
        }
        return ans;
    }
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        int ans=helper( root, h,1);
        return ans;
    }
};
