class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int fullsum = 0;
        int mod=1000000007;
        for(int i = 0 ; i < arr.size(); i++){
            fullsum += arr[i];
        }
        fullsum%=mod;
        long long int pre = 0;
        long long int sum = 0;
        for(int i = 0;i <= arr.size()-1;i++){
            sum += arr[i];
            pre = max(pre,sum);
        }
        int suf = 0;
        sum = 0;
        for(int i = arr.size()-1; i>=0;i--){
            sum += arr[i];
            suf = max((long long)suf,sum);
        }
        int opt3 = arr[0];
        int maxsum = arr[0];
        for(int i = 1; i<= arr.size()-1; i++){
            maxsum = max(arr[i],arr[i] + maxsum);
            opt3 = max(opt3,maxsum);
        }
        if(k == 1){
            return opt3%mod;
        }
        long long int c1 = pre + suf;
        long long int c2 = c1 + fullsum*(k-2)%mod;
        long long int c3 = (fullsum*k)%mod;
        long long int c4 = opt3;
        long long ans = max(c1,max(c2,max(c3,c4)));
        return ans%mod;
    }
};
