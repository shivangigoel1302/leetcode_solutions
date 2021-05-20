/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void traversal(TreeNode* t1, TreeNode* t2, TreeNode* target){
        if(t1 == NULL){
            return;
        }
        if(ans!= NULL){
            return;
        }
        if(t1 == target){
            ans = t2;
            return;
        }
        traversal(t1->left,t2->left,target);
        traversal(t1->right,t2->right,target);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* t1 = original;
        TreeNode* t2 = cloned;
        ans = NULL;
        traversal(t1,t2,target);
        return ans;
    }
};
