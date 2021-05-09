class Solution {
public:
    int bulbSwitch(int n) {
        long long int ans = 0;
        long long int i = 1;
        while(i*i <= n){
            ans++;
            i++;
        }
        return ans;
    }
};
