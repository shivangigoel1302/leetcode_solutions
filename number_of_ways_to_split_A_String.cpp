class Solution {
public:
   long mod = 1e9 + 7;
    int numWays(string s) {
        long long int count = 0;
        long long int n = s.size();
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '1') count++;
        }
        if(count%3 != 0){
            return 0;
        }
        if(count == 0){
            return (int)((((n-1)*(n-2))/2)%mod);
        }
        long long int count1=0;
        long long int count2= 0;
        int sum = 0;
        for(int i = 0 ; i < n; i++){
            sum += s[i]-'0';
            if(sum == count/3) count1++;
            if(sum == 2*(count/3)) count2++;
        }
        return (count1*count2)%mod;
    }
};
