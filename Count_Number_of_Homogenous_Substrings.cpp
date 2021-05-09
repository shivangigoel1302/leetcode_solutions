class Solution {
public:
    int countHomogenous(string s) {
        long long int i = 0;
        int n = s.size();
        long long count = 0;
        int mod = 1e9+7;
        while(i < n){
            char c = s[i];
            long long int j = i;
            while(j < n && s[j] == c){
                j++;
            }
            long long int temp = ((j-i)*(j-i+1)/2)%mod;
            temp %= mod;
            count = (count +temp)%mod;
            count %= mod;
            i = j;
        }
        return count%mod;
    }
};
