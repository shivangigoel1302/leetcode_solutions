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
    int maxLevelSum(TreeNode* root) {
        int maxsum = root->val;
        int currlevel = 1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        int ans=1;
        while(!q.empty()){
            auto node = q.front();
            if(node == NULL){
                q.pop();
                if(sum > maxsum){
                    ans = currlevel;
                    maxsum = sum;
                }
                sum = 0;
                currlevel++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum += node->val;

                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
