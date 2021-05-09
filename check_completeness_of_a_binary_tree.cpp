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

    bool isCompleteTree(TreeNode* root) {
      vector<TreeNode*>v;
      queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* f = q.front();
            if(f==NULL){
                q.pop();
                v.push_back(f);
            }
            else{
                q.pop();
                v.push_back(f);
                q.push(f->left);
                q.push(f->right);
            }
        }
        int i=0;
        for(;i<v.size();i++){
            if(v[2*i+1]==NULL){
                i=2*i+1;
                break;
            }
            if(v[2*i+2]==NULL){
                i=2*i+2;
                break;
            }
        }
        while(i<v.size()){
            cout<<" hi";
            if(v[i]!=NULL){
                return false;
            }
            i++;
        }
        return true;
    }
};
