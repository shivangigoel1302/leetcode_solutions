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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>v;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        s1.push(root);
        while(!s1.empty())
        {
            auto p=s1.top();
            s1.pop();

            v.push_back(p->val);
            if(p->left)
            {
               s2.push(p->left);
            }
            if(p->right)
            {
                s2.push(p->right);
            }

            if(s1.empty())
            {

                    ans.push_back(v);

                v.erase(v.begin(),v.end());
                while(!s2.empty())
                {
                    auto n=s2.top();
                    s2.pop();

                    v.push_back(n->val);
                    if(n->right)
                    {
                        s1.push(n->right);
                    }
                    if(n->left)
                    {
                        s1.push(n->left);
                    }
                }
                if(v.size()!=0)
                {
                    ans.push_back(v);

                }

                v.erase(v.begin(),v.end());
            }
        }
        return ans;
    }
};
