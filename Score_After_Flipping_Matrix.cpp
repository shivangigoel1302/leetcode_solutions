class Solution {
public:
    void flip(char ch, vector<vector<int>>&A, int r, int c){
        if(ch == 'r'){
            for(int i = 0 ; i < (int)A[r].size(); i++){
               A[r][i] = 1 - A[r][i];
            }
        }
        else{
            for(int i = 0 ; i < A.size(); i++){
                A[i][c] = 1 - A[i][c];

            }
        }
        return;
    }
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        if(m == 1 && n == 1){
            return 1;
        }
         for(int i = 0; i < m;i++){
            if(A[i][0] == 0){
                flip('r',A,i,0);
            }
        }
        for(int i = 0 ; i < n ; i++){
            int cr = 0,cc=0;
            for(int j = 0; j < m;j++){
                cc += A[j][i] == 1?1:0;
            }
            if(m - cc > cc){
                flip('c',A,0,i);
            }
        }

        int ans = 0;
        for(int i = 0;i< m;i++){
            int curr = 0;
            int p = 1;
            for(int j = n-1;j>=0;j--){
                curr += p*A[i][j];
                p *= 2;
            }
            ans += curr;
        }
        return ans;
    }
};
