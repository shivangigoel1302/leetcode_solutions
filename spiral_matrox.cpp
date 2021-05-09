class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
         vector<int>ans;
        if(m==0){
            return ans;
        }
        int n = matrix[0].size();
        int r= 0, c=0;

        while(r<m && c < n){
            for(int i = c ; i < n; i++){
                ans.push_back(matrix[r][i]);
            }
            r++;
            for(int i = r; i < m ; i ++){
                ans.push_back(matrix[i][n-1]);
            }
            n--;
            if(r < m){
                for(int i = n-1 ; i>= c;i--){
                    ans.push_back(matrix[m-1][i]);
                }
                m--;
            }
            if(c < n){
                for(int i = m-1 ; i>=r ;i--){
                    ans.push_back(matrix[i][c]);
                }
                c++;
            }
        }
        return ans;
    }
};
