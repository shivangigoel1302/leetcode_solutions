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
    string helper( TreeNode* t){
        string s="";
        if(t==NULL){

            return "";
        }
         if(t->left==NULL && t->right==NULL){
             return s+to_string(t->val)+"";
         }
        if(t->right==NULL){
            return s+to_string(t->val)+ "(" + helper(t->left) + ")";
        }
        return s+to_string(t->val) + "(" +helper(t->left) + ")(" + helper(t->right) + ")";
    }
    string tree2str(TreeNode* t) {

       return helper( t);
    }
};
