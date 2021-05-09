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
    map<int,vector<TreeNode*>>m;
    vector<TreeNode*> allPossibleFBT(int N) {
        if(m.find(N) != m.end()){
            return m[N];
        }
        if(N==1){
            vector<TreeNode*>v;
            TreeNode* n = new TreeNode(0);
            v.push_back(n);
            m[1] = v;
            return v;
        }
        vector<TreeNode*>v;
        if(N%2 == 1){
            for(int x = 0 ; x < N ; x++){
                int y = N-1-x;
                for(TreeNode* left : allPossibleFBT(x)){
                    for(TreeNode* right : allPossibleFBT(y)){
                        TreeNode* n = new TreeNode(0);
                        n->left = left;
                        n->right = right;
                        v.push_back(n);
                    }
                }
            }
            m[N] = v;
        }
        return m[N];
    }
};
