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
   TreeNode* helper(vector<int>nums,int start,int end){
       if(start>end){
           return NULL;
       }

       int max=INT_MIN;
        int index=-1;
        for(int i=start;i<=end;i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        TreeNode* root= new TreeNode(nums[index]);

        TreeNode* left = helper(nums,start,index-1);
        TreeNode* right = helper(nums,index+1,end);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};
