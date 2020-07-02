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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode*p=q.front();
            q.pop();
            if(p==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if(q.front()==NULL)
                {
                    v.push_back(p->val);
                }
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
        }
        return v;
    }
};
