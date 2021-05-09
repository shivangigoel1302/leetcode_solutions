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
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(height(root -> left), height(root -> right)) + 1;
    }
    void helper(TreeNode* root , int row, int start, int end, vector<vector<string>> &v){
        if(root == NULL)
            return;
        if(start <= end){
            int mid = (start + end) / 2;
            v[row][mid] = to_string(root -> val);
            helper(root -> left, row  + 1, start, mid - 1, v);
            helper(root -> right, row  + 1, mid + 1, end, v);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        vector<vector<string>> ans;
        for(int i = 0; i < h; i++){
            vector<string> v;
            for(int j = 0; j < pow(2, h) - 1; j++){
                string s = "";
                v.push_back(s);
            }
            ans.push_back(v);
        }
        helper(root, 0, 0, pow(2, h) - 1, ans);
        return ans;
    }
};
