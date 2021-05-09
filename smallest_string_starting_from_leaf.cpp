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
    void dfs(TreeNode* root, string s,string&ans){
        if(root == NULL){
           return;
        }
        s += (char)(root->val +97);
        if(!root->right && !root->left){
            reverse(s.begin(),s.end());
            if(ans==""){
                ans = s;
            }
            else if(ans > s){
                    ans = s;
                }
        }
        dfs(root->left,s,ans);
        dfs(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
       string s="",ans="";
        dfs(root,s,ans);
        return ans;
    }
};
