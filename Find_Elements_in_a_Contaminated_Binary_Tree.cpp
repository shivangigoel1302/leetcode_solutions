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
class FindElements {
public:
    void recover(TreeNode* root ){
        if(root == NULL) return;

        if(root->left){
            root->left->val = root->val * 2 + 1;
            recover(root->left);
        }
        if(root->right){
            root->right->val = root->val * 2 + 2;
            recover(root->right);
        }
    }
    TreeNode* root;
    FindElements(TreeNode* r) {
        r->val = 0;
        recover(r);
        root = r;
    }
     bool search(TreeNode* root, int val){
         if(root == NULL){
             return false;
         }
         if(root->val == val){
             return true;
         }
         bool l=search(root->left,val);
         bool r = search(root->right,val);
         return l || r;
     }
    bool find(int target) {
        return search(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
