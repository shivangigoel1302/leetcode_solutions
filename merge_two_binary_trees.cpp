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
    TreeNode* mergeTrees(TreeNode* t, TreeNode* s) {
         if(t==NULL && s==NULL || t!=NULL && s==NULL){
             return t;
         }
        if(t == NULL && s != NULL){
            TreeNode* temp= new TreeNode(s->val);
            temp->left = mergeTrees(    NULL,s->left);
            temp-> right= mergeTrees(NULL,s->right);
            return temp;
        }
        t->val= t->val + s->val;
        t->left = mergeTrees(t->left, s->left);
        t->right = mergeTrees(t->right, s->right);
        return t;
    }
};
