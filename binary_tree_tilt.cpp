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
    vector<int>v;
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        v.push_back(abs(left-right));
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        helper(root);
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        return ans;
    }
};
