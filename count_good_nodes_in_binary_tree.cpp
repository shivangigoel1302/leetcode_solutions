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
    void helper(TreeNode* root, vector<int>v, int & count){
        if(root == NULL){
            return;
        }
        if(v.size() == 0) {
            count++;
        }
        else{
            if(root->val >= v[v.size() -1]){
                count++;
            }
        }
        v.push_back(root->val);
        sort(v.begin(),v.end());
        helper(root->left,v,count);
        helper(root->right,v,count);
        int index = lower_bound(v.begin(),v.end(),root->val -1) - v.begin();
        v.erase(v.begin() + index);
        return;

    }
    int goodNodes(TreeNode* root) {
        vector<int>values;
        int count = 0;
        helper(root,values,count);
        return count;
    }
};
