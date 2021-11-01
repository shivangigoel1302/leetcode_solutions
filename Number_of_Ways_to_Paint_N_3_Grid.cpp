class Solution {
public:
    vector<string>v;
    vector<vector<int>>compat;
    string s;
    void generate(){
        if(s.size() == 3){
            v.push_back(s);
            return;
        }
        if(s.empty()){
            for(int i = 0; i < 3; i++){
                s += i + '0';
                generate();
                s.pop_back();
            }
        }
        else{
            for(int i = 0; i < 3; i++){
                if(i + '0' == s.back()){
                    continue;
                }

                s += i + '0';
                generate();
                s.pop_back();
            }
        }
        return;
    }
    int numOfWays(int n) {
        generate();
        int mod = 1e9+7;
        compat.resize(12);
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                for(int k = 0; k < 3;k++){
                    if(v[i][k] == v[j][k]){
                        break;
                    }
                    if(k == 2){
                        compat[i].push_back(j);
                    }
                }
            }
        }

        vector<vector<long long>>dp(n,vector<long long>(12,0));
        for(int i = 0; i < 12; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 12; j++){
                for(int k = 0; k < compat[j].size(); k++){
                    dp[i][j] = (dp[i][j] + dp[i-1][compat[j][k]])%mod;
                }
                dp[i][j]%= mod;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 12; i++){
            ans += dp[n-1][i];
        }
        return ans %mod;

        // long long c2=6,c3=6;
        // int mod = 1e9+7;
        // for(int i = 1; i < n; i++){
        //     long long temp = c3;
        //     c3 = (2*c2 + 2*c3)%mod;
        //     c2 = (2*temp + 3*c2)%mod;
        // }
        // return (c3+c2)%mod;
    }
};
