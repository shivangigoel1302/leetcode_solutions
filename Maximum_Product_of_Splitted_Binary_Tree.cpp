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
    int mod = 1000000007;
    int total;
    void traverse(TreeNode* root,long long int &ans){
        if(root == NULL){
            return;
        }
        traverse(root->left,ans);
        traverse(root->right,ans);
        ans = max(ans, ( (long long)(total-root->val) *  (long long)(root->val)));
        return;
    }
    int update(TreeNode* &root){
        if(root == NULL){
            return 0;
        }
        int left = update(root->left);
        int right = update(root->right);
        root->val += left + right;
        return root->val;
    }
    int maxProduct(TreeNode* root) {
         total = update(root);
      long long int ans = 0;
        traverse(root,ans);
        return ans%mod;
    }
};
