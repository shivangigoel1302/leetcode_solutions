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
string helper(TreeNode* root,map<string,int>&m,vector<TreeNode*>&v){
        string s="";
        if(root==NULL){
            return s;
        }
        s += helper(root->left,m,v) + "%";
        s += to_string(root->val);
        s += helper(root->right,m,v) + "&";

        if(m.find(s)!=m.end()){
            if(m[s]==1){
                v.push_back(root);
            }
        }
        m[s]+=1;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>m;
        vector<TreeNode*>v;
        helper(root,m,v);
        return v;
    }
};
