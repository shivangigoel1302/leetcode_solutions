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
    bool checkIncreasing(vector<int>v){
        if(v.size() == 1){
            if(v[0]%2 !=1){
                return false;
            }
            return true;
        }
        for(int i = 0 ; i < v.size() - 1 ; i++){
            if(v[i]%2!=1 || v[i+1]%2 != 1){
                return false;
            }
            if(v[i] >= v[i+1]){
                return false;
            }
        }
        return true;
    }
       bool checkDecreasing(vector<int>v){
            if(v.size() == 1){
            if(v[0]%2 !=0){
                return false;
            }
            return true;
        }
        for(int i = 0 ; i < v.size() - 1 ; i++){
            if(v[i]%2!=0 || v[i+1]%2 != 0){
                return false;
            }
            if(v[i] <= v[i+1]){
                return false;
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        int level = 0;
        while(!q.empty()){
            TreeNode* first = q.front();
            if(first == NULL){
                q.pop();
                if(level%2==0){
                    if(!checkIncreasing(v)){
                        return false;
                    }
                }
                else{
                   if(!checkDecreasing(v)){
                       return false;
                   }
                }
                if(!q.empty()){
                    q.push(NULL);
                }
                level++;
                v.clear();
            }
            else{
                v.push_back(first->val);
                q.pop();
                if(first->left){
                    q.push(first->left);
                }
                if(first->right){
                    q.push(first->right);
                }
            }
        }
        return true;
    }
};
