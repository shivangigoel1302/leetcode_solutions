class Solution {
public:
    vector<vector<int>>dp;
    bool helper(string s1,string s2,int i , int j , string s3, int k){
        if((i != s1.size() || j != s2.size()) && k == s3.size()){
            return false;
        }
        if(k == s3.size()){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j] == 1? true:false;
        }
        if(s3[k] == s1[i]){
            bool next = helper(s1,s2,i+1,j,s3,k+1);
            if(next){
                dp[i][j] = 1;
                return true;
            }
        }
        if(s3[k] == s2[j]){
            bool next = helper(s1,s2,i,j+1,s3,k+1);
            if(next){
                dp[i][j] = 1;
                return true;
            }
        }
        dp[i][j]= 0;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,0,0,s3,0);
    }
};
