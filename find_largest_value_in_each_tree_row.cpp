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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        if(root==NULL){
            return v;
        }
        int maxVal=INT_MIN;
        while(!q.empty()){
            TreeNode*f=q.front();
            if(f==NULL)
            {
                v.push_back(maxVal);
                maxVal=INT_MIN;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                maxVal=max(maxVal,f->val);
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return v;
    }
};
