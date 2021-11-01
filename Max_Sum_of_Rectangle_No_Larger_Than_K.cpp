class Solution {
public:
    int solve(vector<int>&v,int K){
        int temp = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            int sum = 0;
            for(int j = i; j < v.size(); j++){
                sum += v[j];
                if(sum <= K && sum > temp){
                    temp = sum;
                }
            }
        }
        return temp;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        for(int i = 0; i < m; i++){
            vector<int>col(n,0);
            for(int j = i; j < m; j++){
                for(int k = 0; k < n; k++){
                    col[k] += matrix[j][k];
                }
                ans = max(ans,solve(col,K));
            }

        }
        return ans;
    }
};
