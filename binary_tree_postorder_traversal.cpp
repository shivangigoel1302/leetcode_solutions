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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        unordered_set<TreeNode*>st;
        TreeNode*itr=root;
        while(!s.empty()||itr!=NULL)
        {
            if(itr!=NULL)
            {
                s.push(itr);
                st.insert(itr);
                itr=itr->left;
            }
            else
            {
                TreeNode*temp=s.top();
                s.pop();
                if(st.find(temp)!=st.end())
                {
                    st.erase(st.find(temp));
                    s.push(temp);
                    itr=temp->right;
                }
                else
                {
                    ans.push_back(temp->val);
                    itr=NULL;
                }
            }
        }
        return ans;
    }
};
