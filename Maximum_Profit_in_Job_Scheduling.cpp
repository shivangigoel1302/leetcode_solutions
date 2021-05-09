class Solution {
public:
    int dp[100000];
    int solve(vector<vector<int>>&v,int i){
        if(i >= v.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = solve(v,i+1);
        int idx = -1;
        int l = i;
        int r = v.size()-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(v[mid][0] < v[i][1]){
                l = mid+1;
            }
            else{
                idx = mid;
                r = mid-1;
            }
        }
        if(idx == -1){
            ans = max(ans,v[i][2]);
        }
        else{
            ans = max(ans,v[i][2] + solve(v,idx));
        }
        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int> > a;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<s.size();i++){
            a.push_back({s[i],e[i],p[i]});
        }
        sort(a.begin(),a.end());
        return solve(a,0);
    }
};
