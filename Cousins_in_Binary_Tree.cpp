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
    int finddepth(TreeNode* root, int x){
        if(root == NULL){
            return 0;
        }
        if(root->val == x) return 1;
        int l = finddepth(root->left,x);
        int r = finddepth(root->right, x);
       if(l +r) return l+r + 1;
        return 0;
    }
    TreeNode* findparent(TreeNode* root,int x){
        if(!root) return NULL;
        if(root->val == x) return NULL;
        if(root->left && root ->left->val == x) return root;
        if(root->right && root->right->val == x) return root;
        TreeNode* l = findparent(root->left,x);
        TreeNode* r = findparent(root->right,x);
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = finddepth(root,x);
        int d2 = finddepth(root,y);
        if(d1 != d2) return false;
       // cout<<d1<<" "<<d2<<" ";
        TreeNode* p1 = findparent(root,x);
        TreeNode* p2 = findparent(root,y);
        if(p1 == p2) return false;
        return true;
    }
};
