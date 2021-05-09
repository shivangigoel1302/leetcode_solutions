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
   TreeNode* insertinbst(int val , TreeNode* &root){
        if(root == NULL){
            TreeNode* n = new TreeNode(val);
            root = n;
            return root;
        }
        if(val <= root->val){
            root->left = insertinbst(val,root->left);
        }
       else{
           root->right = insertinbst(val,root->right);
       }
       return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0 ;i < preorder.size(); i++){
            insertinbst(preorder[i],root);
        }
        return root;
    }
};
