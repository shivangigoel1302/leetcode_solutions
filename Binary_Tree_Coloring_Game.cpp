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
    bool ans = false;
    int compare(TreeNode* root, int x , int n){
        if( root == NULL){
            return 0;
        }
        int l = compare(root->left,x,n);
        int r = compare(root->right,x,n);
        if(root->val == x){
            int a = n - l - r - 1;
            int d = max(a,max(l,r));
            if(d > (n/2)){
                ans = true;
            }
            else{
                ans = false;
            }
        }
        return l + r + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        compare(root,x,n);
        return ans;
    }
};
