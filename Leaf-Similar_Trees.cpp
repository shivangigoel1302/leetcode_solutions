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

    void leaf(TreeNode* root,vector<int>&v){
        if(root == NULL) return;
        if(!root->left && !root->right){
            v.push_back(root->val);
            return;
        }
        leaf(root->left,v);
        leaf(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        leaf(root1,v);
        vector<int>v2;
       leaf(root2,v2);
        if(v.size() != v2.size()) return false;
        for(int i = 0 ; i < v.size(); i++){
            if(v[i] != v2[i]) return false;
        }
        return true;
    }
};
