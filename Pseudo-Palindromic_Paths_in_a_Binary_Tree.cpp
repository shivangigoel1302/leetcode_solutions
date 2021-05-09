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
    int count ;
    map<int,int>m;
    void dfs(TreeNode* root){
        if(!root) return;
        m[root->val]++;
        if(!root->left && !root->right){
            int odd = 0;
            for(auto it : m){
                if(it.second%2 == 1){
                    odd++;
                }
            }
            if(odd <=1) count++;
        }
        dfs(root->left);
        dfs(root->right);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)  return 0;
        if(!root->right && !root->left){
            return 1;
        }
        count = 0;
        dfs(root);
        return count;
    }
};
