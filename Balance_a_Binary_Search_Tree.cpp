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
    void inorder(vector<TreeNode* >&nodes,TreeNode* root){
        if(root == NULL) return;
        inorder(nodes,root->left);
        nodes.push_back(root);
        inorder(nodes,root->right);
        return;
    }
    TreeNode* getnode(vector<TreeNode* > nodes, int s, int e){
        if(s > e) return NULL;
        if( s== e){
            return nodes[s];
        }
        int mid = s+ (e - s + 1)/2;
        nodes[mid]->left = getnode(nodes,s,mid-1);
        nodes[mid]->right = getnode(nodes,mid+1,e);
        return nodes[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(nodes,root);
        for(auto node:nodes)
            node->left=node->right=nullptr;
        int mid = nodes.size()/2;
        TreeNode* newroot = nodes[mid];
        newroot->left = getnode(nodes,0,mid-1);
        newroot->right = getnode(nodes,mid + 1, nodes.size()-1);
         return newroot;
    }
};
