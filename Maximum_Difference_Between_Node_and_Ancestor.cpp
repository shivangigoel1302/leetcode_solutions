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
    vector<int>helper(TreeNode* root, int&ans){
        if(root == NULL){
            return {};
        }
        vector<int>left = helper(root->left,ans);
        vector<int>right = helper(root->right,ans);
        int a = root->val;
        for(int x:left){
            if(abs(x-a) >ans){
                ans = abs(x-a);
            }
        }
         for(int x:right){
            if(abs(x-a) >ans){
                ans = abs(x-a);
            }
             left.push_back(x);
        }
       left.push_back(root->val);
        return left;
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
    }
};
