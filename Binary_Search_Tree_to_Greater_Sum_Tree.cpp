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
    int prev;
    TreeNode* gst(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        gst(root->right);
        if(prev == -1){
            prev = root->val;
            return root;
        }
        root -> val += prev;
        prev = root->val;
        gst(root->left);
        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
         prev = -1;
        return gst(root);
    }
};
