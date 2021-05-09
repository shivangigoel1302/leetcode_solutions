class Solution {
public:
    int getparent(int val,vector<int>&parent){
        if(parent[val] == val){
            return val;
        }
       return parent[val] = getparent(parent[val],parent);
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<int>parent(M.size());
        for(int i = 0 ; i < parent.size(); i++){
            parent[i] = i;
        }
        for(int i = 0 ; i < M.size(); i++){
            for(int j = 0  ; j < M[0].size(); j++){
                if(M[i][j] == 1){
                    int srcparent = getparent(i,parent);
                    int destparent = getparent(j,parent);
                    if(srcparent != destparent){
                        parent[destparent] = parent[srcparent];
                    }
                }
            }
        }
      int count = 0;
        for(int i = 0 ; i < parent.size(); i++){
           if(parent[i] == i) count++;
        }
        return count;
    }
};
