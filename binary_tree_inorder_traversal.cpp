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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<pair<TreeNode*,int>>s({{root,1}});
        while(!s.empty())
        {
            auto p= s.top();
            s.pop();
            TreeNode* node=p.first;
            int count=p.second;
            if(node==NULL)
            {
                continue;
            }
            else if(count==1)
            {
                s.push({node->right,1});
                s.push({node,2});
                s.push({node->left,1});
            }
            else if(count==2)
            {
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};
