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
class CBTInserter {
public:
    TreeNode* head;
    CBTInserter(TreeNode* root) {
        head = root;
    }

    int insert(int v) {
        queue<TreeNode*>q;
        q.push(head);
        while(!q.empty()){
            auto front = q.front();
            if(!front->left){
                TreeNode* n = new TreeNode(v);
                front->left = n;
                return front->val;
            }
            else if(!front->right){
                TreeNode* n = new TreeNode(v);
                front->right = n;
                return front->val;
            }
            else{
                q.push(front->left);
                q.push(front->right);
            }
            q.pop();
        }
        return head->val;
    }

    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
