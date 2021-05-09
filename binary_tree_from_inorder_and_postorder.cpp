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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int s,int e,int &i){
        if(s > e){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[i]);
        // if(s==e){
        //     return root;
        // }
        int key = postorder[i--];
        int j = -1;
        for(int k = s ; k <= e; k++){
            if(key == inorder[k]){
                j = k;
                break;
            }
        }
         root->right = helper(inorder,postorder,j+1,e,i);
        root->left = helper(inorder,postorder,s,j-1,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size()-1;
        return helper(inorder,postorder,0,n,n);
    }
};
