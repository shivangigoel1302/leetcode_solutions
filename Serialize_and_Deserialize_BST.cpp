/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(string &s, TreeNode* root){
        if(root == NULL){
            return;
        }
        s += to_string(root->val) +'#';
        preorder(s,root->left);
        preorder(s,root->right);
    }
    string serialize(TreeNode* root) {
        string s = "";
        preorder(s,root);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* buildbst(int a, TreeNode* &root){
        if(root == NULL){
            TreeNode* temp = new TreeNode(a);
            root = temp;
            return root;
        }
        if(a < root->val){
            root->left = buildbst(a,root->left);
            return root;
        }
        else{
            root->right = buildbst(a,root->right);
            return root;
        }
        return root;
    }
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        string curr = "";
        for(auto c: data){
            if(c == '#'){
                 int a = stoi(curr);
                buildbst(a,root);
                curr = "";
                continue;
            }
           curr += c;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
