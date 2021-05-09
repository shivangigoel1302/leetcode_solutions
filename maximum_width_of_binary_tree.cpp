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
   typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,ull>> q;
        q.push({root,1});
       ull ans = 0;
        while(!q.empty()){
       ull left = q.front().second;
            ull right = left;
            int size = q.size();
            for(int i = 0 ; i < size ; ++i){
                auto node = q.front().first;
                right = q.front().second;
                q.pop();
                if(node -> left)
                    q.push({node -> left, right * 2});
                if(node -> right)
                    q.push({node -> right, right * 2 + 1});
            }
            ans = max(ans,right +1 - left);
        }

        return (int)ans;
    }
};
