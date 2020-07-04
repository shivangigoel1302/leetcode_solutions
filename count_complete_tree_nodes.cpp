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
    void search(TreeNode*root,int&count)
    {
        if(root->left)
        {
            count++;
            search(root->left,count);
        }
        else
        {
            return;
        }
        if(root->right)
        {
            count++;
            search(root->right,count);
        }
        else
        {
            return;
        }
    }
    int countNodes(TreeNode* root) {
        int count=1;
        if(root==NULL)
        {
            return 0;
        }
        search(root,count);
        return count;
    }
};
