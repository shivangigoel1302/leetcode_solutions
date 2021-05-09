class Solution {
public:
    // giving tle due to n^2 approach
    int value(vector<int>nums,int i){
        if(i -1 < 0 ){
            return 0;
        }
        return abs(nums[i] - nums[i-1]);
    }
    int maxValueAfterReverse(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int profit = 0;
        int lmax=-1,rmax=nums.size();
        int n = nums.size();
        for(int l= 1; l < n-1; l++){
            if(abs(nums[0] - nums[l+1]) - value(nums,l+1) > curr){
                curr = abs(nums[0] - nums[l+1]) -value(nums,l+1);
                cout<<curr<<" ";
                profit = abs(nums[0] - nums[l+1]);
                lmax = -1;
                rmax = l+1;
            }
        }
        for(int l = 1; l < nums.size()-1; l++){
            if(abs(nums[nums.size()-1] - nums[l-1]) - value(nums,l) > curr){
                curr = abs(nums[nums.size()-1] - nums[l-1]) - value(nums,l);
                profit = abs(nums[nums.size() - 1] -  nums[l-1]);
                lmax = l-1;
                rmax = nums.size();
            }
        }
        for(int l = 1; l < nums.size() - 2; l++){
            for(int r = l+1; r < nums.size()-1;r++){
                int na = abs(nums[r]-nums[l-1]);
                int nb = abs(nums[l]-nums[r+1]);
                if(na+ nb- value(nums,l)-value(nums,r+1) > curr){
                    lmax = l-1;
                    rmax = r+1;
                    curr = na+nb-value(nums,r+1)- value(nums,l);
                    profit = abs(na+nb);
                }
            }
        }
        cout<<lmax<<" "<<rmax;
        for(int i = 0 ; i < lmax;i++){
            ans += abs(nums[i] - nums[i+1]);
        }
        ans += profit;
        for(int i = lmax+1;i< rmax-1;i++){
            ans += abs(nums[i] - nums[i+1]);
        }
        for(int i = rmax; i < nums.size()-1;i++){
            ans += abs(nums[i]-nums[i+1]);
        }
        return ans;
    }
};
