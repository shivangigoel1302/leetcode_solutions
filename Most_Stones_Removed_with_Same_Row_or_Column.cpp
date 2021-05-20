class Solution {
public:
    int getparent(int i,vector<int>&root){
        if(i == root[i]){
            return i;
        }
        return root[i] = getparent(root[i],root);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>root(n);
        for(int i = 0 ; i < n; i++){
            root[i] = i;
        }
        for(int i = 0 ; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    int srcparent = getparent(i,root);
                    int destparent = getparent(j,root);
                    if(srcparent != destparent){
                        root[destparent] = srcparent;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            if(root[i] == i){
                cnt++;
            }
        }
        return n- cnt;
    }
};
