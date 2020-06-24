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
void fun(string &s,vector<string>&v,TreeNode*root)
{

     if(root==NULL)
    {
        return;
    }
    s+=to_string(root->val);
    if(root->left==NULL &&root->right==NULL)
    {
        v.push_back(s);
        s.pop_back();
        return;
    }
    fun(s,v,root->left);
    fun(s,v,root->right);
     s.pop_back();
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        string s;
        int sum=0;
        vector<string>v;
        fun(s,v,root);
        for(int i=0;i<v.size();i++)
        {
            int x=stoi(v[i]);
          sum=sum+x;
        }
        return sum;
    }
};
