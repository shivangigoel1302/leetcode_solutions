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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        while(!q.empty())
        {
            TreeNode*r=q.front();
            if(r==NULL)
            {
                ans.push_back(v);
                q.pop();
                v.erase(v.begin(),v.end());
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                v.push_back(r->val);
                q.pop();
                if(r->left)
                {
                    q.push(r->left);
                }
                if(r->right)
                {
                    q.push(r->right);
                }
            }
        }
        return ans;
    }
};
