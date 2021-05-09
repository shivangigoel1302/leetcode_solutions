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
    int sum = 0;
    void helper(TreeNode* root, int num){
        if(root->val == 1){
            num = num <<1;
            num = num | 1;
        }
        else{
            num = num <<1;
        }
        if(!root->left && !root->right){
           sum += num;

            return;
        }
        if(root->left){
            helper(root->left,num);
        }
        if(root->right){
            helper(root->right,num);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
       helper(root,0);
        return sum;
    }
};
