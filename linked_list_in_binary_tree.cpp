/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool comparefunc(ListNode* head,TreeNode* root){
        if(root == NULL && head == NULL){
            return true;
        }
        if(head == NULL ){
            return true;
        }
        if(root == NULL){
            return false;
        }
        return root->val == head->val &&(comparefunc(head->next,root->left)|| comparefunc(head->next,root->right)) ;

    }
    void dfs(ListNode* head, TreeNode* root, bool &truth){
       if(root == NULL){
           return;
       }
        truth = truth || comparefunc(head,root);
        dfs(head,root->left,truth);
        dfs(head,root->right,truth);
        return ;

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool truth = false;
        dfs(head,root,truth);
        return truth;
    }
};
