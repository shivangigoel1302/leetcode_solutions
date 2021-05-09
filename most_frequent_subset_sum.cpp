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
    int helper(map<int,int>&m,TreeNode* root){
         if(root==NULL){
             return 0;
         }
        int left=helper(m,root->left);
        int right=helper(m,root->right);
        m[root->val+left+right]+=1;
        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        vector<int>v;
        helper(m,root);
        int maxFreq=-1;
        for(auto i:m){
           if(i.second > maxFreq){
               v.clear();
               v.push_back(i.first);
               maxFreq=i.second;
           }
     else if(i.second==maxFreq){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
