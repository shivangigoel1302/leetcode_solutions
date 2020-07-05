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
    int kthSmallest(TreeNode* root, int k) {
        stack<pair<TreeNode*,int>>s;
        int val=0;
        s.push({root,1});
        while(k>0)
        {
            auto p=s.top();
            s.pop();
            if(p.first==NULL)
            {
                continue;
            }
            else if(p.second==1)
            {
                s.push({p.first->right,1});
                s.push({p.first,2});
                s.push({p.first->left,1});
            }
            else if(p.second==2)
            {
                k--;
                 val=p.first->val;
            }
        }
        return val;
    }
};
