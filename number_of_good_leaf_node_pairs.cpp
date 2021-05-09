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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, distance, res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int d, int& cnt){
        if(!root) return {};
        if(!root->left && !root->right) return vector<int>{0};
        auto v1 = dfs(root->left, d, cnt), v2 = dfs(root->right, d, cnt);
        for(auto& x:v1) x++;
        for(auto& x:v2) x++;
        for(int i=0, j=int(v2.size())-1;i<v1.size() && j>=0;i++){
            while(j>=0 && v1[i]+v2[j]>d) j--;
            cnt += j+1;
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        return v1;
    }
};
