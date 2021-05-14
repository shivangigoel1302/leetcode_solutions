class Solution {
public:
    int ar[101][101][101];
    int findmove(string s, int i, int j){
        int l = i;
        int r = j;
        int count = 0;
        while(l <= r){
            if(s[l] != s[r]){
                count++;
            }
            l++;
            r--;
        }
        return count;
    }
    int helper(vector<vector<int>>&dp,string s, int k,int i,int j){
        if(i > j){
            if(k == 0){
                return 0;
            }
            return 1e6;
        }
        if(j-i+1 == k){
            ar[i][j][k] = 0;
            return 0;
        }
        if(j-i+1 < k){
            return 1e6;
        }
        if(k == 1){
            return ar[i][j][k]= dp[i][j];
        }
        if(ar[i][j][k] != -1){
            return ar[i][j][k];
        }
        int temp = INT_MAX;
        for(int l = i; l <= j; l++){
           int a = helper(dp,s,1,i,l);
           int b = helper(dp,s,k-1,l+1,j);
            temp = min(temp,a+b);
        }
        return ar[i][j][k]=temp;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        memset(ar,-1,sizeof(ar));
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp[i][j] = findmove(s,i,j);
            }
        }
        return helper(dp,s,k,0,s.size()-1);
    }
};
