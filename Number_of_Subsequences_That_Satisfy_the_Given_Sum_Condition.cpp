class Solution {
public:
    int mod = 1e9 + 7;
    int exp(long long x,long long y){
        if( y == 0) return 1;
        long long t = exp(x,y/2);
        t = t* t;
        t =t%mod;
        if(y%2 == 1){
            return (x*t)%mod;
        }
       return t;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int l = i;
            int h = nums.size()-1;
            int index = -1;
            while(l <= h){
                int mid = (l+h)/2;
                if(nums[i] + nums[mid] <= target){
                    index = mid;
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
            if (index == -1) break;
            long long int diff = index - i;
            ans += (exp(2,diff));
            ans = ans%mod;
        }
        return ans;
    }
};
