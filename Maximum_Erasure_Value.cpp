class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j = 0;
        int i = 0;
        map<int,int>m;
        int ans = 0;
        int cursum = 0;
        while(i < nums.size()){
            m[nums[i]]++;
            while(j < i && m[nums[i]] > 1){
                m[nums[j]]--;
                cursum -= nums[j];
                j++;
            }
            cursum += nums[i];
            ans = max(ans,cursum);
            i++;
        }
        return ans;
    }
};
