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
     vector<TreeNode* >helper(int start,int end){
         vector<TreeNode* >ans;
         if( start > end){
             ans.push_back(NULL);
             return ans;
         }
         for(int i=start; i <= end; i++){
            vector<TreeNode* >Left= helper(start,i-1);
            vector<TreeNode* >Right= helper(i+1,end);
             for(int l=0;l<Left.size();l++){
                 TreeNode* leftNode = Left[l];
                 for(int r=0;r < Right.size(); r++){
                     TreeNode* rightNode= Right[r];
                     TreeNode* root=new TreeNode(i);
                     root->left = leftNode;
                     root->right = rightNode;
                     ans.push_back(root);
                 }
             }
         }
         return ans;
     }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode* >v;
            return v;
        }
       return helper(1,n);
    }
};
