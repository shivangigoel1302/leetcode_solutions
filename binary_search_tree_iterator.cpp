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
class BSTIterator {
public:
    queue<int>q;
    void fillqu(TreeNode*root,queue<int>&q)
    {

        if(root==NULL)
        {
            return;
        }
        fillqu(root->left,q);
        q.push(root->val);
        fillqu(root->right,q);
    }
    BSTIterator(TreeNode* root) {

       fillqu(root,q);
    }

    /** @return the next smallest number */
    int next() {
        int top=q.front();
        q.pop();
        return top;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!q.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
