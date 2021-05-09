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
    int totalCamera = 0;
    unordered_set<TreeNode* >s;
    void findMin( TreeNode* root, TreeNode* parent){
        if(root == NULL){
            return;
        }
        findMin(root->left, root);
        findMin(root->right, root);
        if( (parent == NULL && s.find(root) == s.end() ) || s.find(root->left) == s.end() || s.find(root->right) == s.end()){
            totalCamera++;
            s.insert(root);
            s.insert(root->left);
            s.insert(root->right);
            s.insert(parent);
        }

    }
    int minCameraCover(TreeNode* root) {
         s.insert(NULL);
        if(!root->left && !root->right&& root!=NULL){
            return 1;
        }
        findMin(root, NULL);
        return totalCamera;
    }
};
