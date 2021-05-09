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
    int ans = INT_MAX;
    int min1;
    bool found;
    void dfs(TreeNode* root){
        if(root){
            if(min1 < root->val && root->val <= ans){
                found = true;
                ans = root->val;
            }
            else if(min1 == root->val){
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val;
        found = false;
        dfs(root);

        return found == true? ans: -1;
    }
};
