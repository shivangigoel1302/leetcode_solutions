class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>m;
        int n = matrix.size();
        int ans = 0;
        int mn = matrix[0].size();
        for(int i = 0 ; i < n; i++){
            string ones = "";
            string zeroes = "";
            for(int j = 0 ; j < mn ; j++){
                if(matrix[i][j] == 0){
                    zeroes += to_string(j);
                }
                else{
                    ones += to_string(j);
                }
            }
            m[ones]++;
            m[zeroes]++;
            ans = max(ans,max(m[ones],m[zeroes]));
        }
        return ans;
    }
};
