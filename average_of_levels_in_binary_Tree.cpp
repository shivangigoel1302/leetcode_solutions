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
    vector<double> averageOfLevels(TreeNode* root) {
        int count = 0;
        double sum = 0;
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f= q.front();
            if(f== NULL){
                q.pop();
                if(count!=0){

                double avg=sum/count;
                ans.push_back(avg);
                sum=0;
                count=0;
                }
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=f->val;
                count++;
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return ans;
    }
};
