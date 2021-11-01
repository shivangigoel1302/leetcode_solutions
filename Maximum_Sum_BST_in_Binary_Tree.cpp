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
    pair<int,char>helper(int &ans,TreeNode* root,int num,char c){
        if(!root){
            return {0,'*'};
        }
        pair<int,char>l = helper(ans,root->left,root->val,'l');
        pair<int,char>r = helper(ans,root->right,root->val,'r');
        if(l.second=='#'||r.second=='#')return {0,'#'};
        if(root->left && root->left->val >= root->val){
            return {0,'#'};
        }
        if(root->right && root->right->val <= root->val){
            return {0,'#'};
        }
        ans = max(ans,root->val + l.first + r.first);

        if(c == 'l'){
            if(root->right && root->right->val >= num){
                return {0,'#'};
            }
        }
        if(c == 'r'){
            if(root->left && root->left->val <= num){
                return {0,'#'};
            }
        }
        return {root->val + l.first + r.first,'*'};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(ans,root,INT_MAX,'p');
        return ans;
    }
};
