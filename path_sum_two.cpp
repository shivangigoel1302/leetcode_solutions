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
void path(vector<int>&v,vector<vector<int>>&ans,TreeNode*root,int curr,int sum)
{
    if(root==NULL)
    {
        return;
    }
    curr+=root->val;

    v.push_back(root->val);
    if(curr==sum && root->right==NULL&&root->left==NULL)
    {
        ans.push_back(v);
        v.pop_back();
        return;
    }
    path(v,ans,root->left,curr,sum);
    path(v,ans,root->right,curr,sum);
    v.pop_back();
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>v;
        vector<vector<int>>ans;
        path(v,ans,root,0,sum);
        return ans;
    }
};
