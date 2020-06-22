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
TreeNode*helper(vector<int>& preorder,vector<int>& inorder,map<int,int>&m,int& index,int low,int high)
{
    if(low>high||low<0||low>inorder.size()||high>inorder.size()||index>=inorder.size()||high<0)
    {
        return NULL;
    }
    TreeNode*root=new TreeNode(preorder[index++]);
    int inindex=m[root->val];
   root->left= helper(preorder,inorder,m,index,low,inindex-1);
    root->right=helper(preorder,inorder,m,index,inindex+1,high);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        int index=0;
        return helper(preorder,inorder,m,index,0,inorder.size()-1);
    }
};
