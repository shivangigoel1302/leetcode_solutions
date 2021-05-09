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
    void helper(TreeNode* & root,vector<TreeNode* >&v,vector<int>&to_delete){
       if(root==NULL){
           return;
       }
        for(int i=0;i<to_delete.size();i++){
            if(to_delete[i]== root->val){
                helper(root->left,v,to_delete);
                helper(root->right,v,to_delete);
                if(root->left){
                    v.push_back(root->left);
                }
                if(root->right){
                    v.push_back(root->right);
                }
                root = NULL;
                return;
            }
        }
        helper(root->left,v,to_delete);
        helper(root->right,v,to_delete);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode* >v;
        helper(root,v,to_delete);
        if(root!=NULL){
           v.push_back(root);
        }
        return v;
    }
};
