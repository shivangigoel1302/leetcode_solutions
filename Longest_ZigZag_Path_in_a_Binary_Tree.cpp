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
    pair<int,int>helper(int &ans, TreeNode* root){
        if( root == NULL){
            return {0,0};
        }
        if(!root->right && !root->left){
            return {1,1};
        }
        auto left = helper(ans,root->left);
        auto right = helper(ans,root->right);
        int x = left.second +1;
        int y = right.first + 1;
        ans = max(ans,max(x,y));
        return {x,y};
    }
    int longestZigZag(TreeNode* root) {
        int ans = 1;
        helper(ans,root);
        return ans-1;
    }
};
