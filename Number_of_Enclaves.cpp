class Solution {
public:
    void dfs(vector<vector<int>>&A,int i, int j){
        if(i < 0 || i >= A.size() || j <0 || j >=A[0].size() || A[i][j] == 0){
            return;
        }
        A[i][j] = 0;
        dfs(A,i+1,j);
        dfs(A,i-1,j);
        dfs(A,i,j+1);
        dfs(A,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for(int i = 0 ; i < m ; i++){
            if(A[i][0] == 1){
                dfs(A,i,0);
            }
            if(A[i][n-1] == 1){
                dfs(A,i,n-1);
            }
        }
        for(int i = 0 ; i< n ; i++){
            if(A[0][i] == 1){
                dfs(A,0,i);
            }
            if(A[m-1][i] == 1){
                dfs(A,m-1,i);
            }
        }
        int count = 0;
        for(int i = 1 ; i < m-1; i++){
            for(int j = 1 ; j < n-1 ; j++){
                if(A[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
