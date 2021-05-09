/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void subtree(TreeNode* root, int dist , int K, vector<int>&v){
        if(root == NULL || dist > K){
            return;
        }
        if(dist == K){
            v.push_back(root->val);
        }
        else{
             subtree(root->left,dist+1,K,v);
        subtree(root->right,dist+1,K,v);
        }
    }
    int helper(TreeNode* root,TreeNode* target, int K,vector<int>&v){
        if(root == NULL){
            return -1;
        }
        if(root == target){
            subtree(root,0,K,v);
            return 1;
        }
        else{
           int L = helper(root->left,target,K,v);
            int R = helper(root->right,target,K,v);
            if(L != -1){
                if(L == K){
                    v.push_back(root->val);
                }
                    subtree(root->right,L+1,K,v);
                    return L+1;
                }
            else if(R != -1){
                    if (R == K){
                        v.push_back(root->val);
                    }
                    subtree(root->left,R+1,K,v);
                    return R+1;
                }
            else{
                return -1;
               }
            }
        }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int>v;
        helper(root, target, K,v);
        return v;
    }
};
