class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> u;
        return helper(root,k,u);
    }
    bool helper(TreeNode* root,int target,unordered_map<int,int> &u)
    {
        if(root==NULL)
            return false;
        if(u.find(target-(root->val))!=u.end())
           return true;
           u[root->val]++;
           return helper(root->left,target,u) || helper(root->right,target,u);
    }
};
