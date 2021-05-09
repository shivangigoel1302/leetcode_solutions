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
    struct compare{
    bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        }
};
    map<int,vector<vector<int>>>m;
    void dfs(TreeNode* root, int col , int h){
        if(!root){
            return;
        }
        m[col].push_back({h,root->val});
        dfs(root->left,col-1,h+1);
        dfs(root->right,col+1,h+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>ans;
        for(auto i: m){
            vector<int>temp;
            auto curr = i.second;
            sort(curr.begin(),curr.end(),compare());
            for(auto v: curr){
                temp.push_back(v[1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
