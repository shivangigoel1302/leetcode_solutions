class Solution {
public:
    int m = 1e9+7;
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(),A.end());
        long long ans = 0;
        int n = A.size();
        vector<long long>pow(n,0);
        pow[0] = 1;
        for(int i  = 1; i < n ; i++){
            pow[i] = (pow[i-1]*2 )%m;
        }
        for(int i = 0  ; i< n ; i++){
            ans = (ans + (pow[i] - pow[n-i-1])*A[i])%m;
            ans %= m;
        }
        ans %=m;
        return ans;
    }
};
