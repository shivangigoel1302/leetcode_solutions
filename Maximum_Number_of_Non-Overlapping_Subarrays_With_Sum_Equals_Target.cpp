class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        map<int,int>m;
        int pos = -1;
        int sum = 0;
        int ans = 0;
        m[0] = -1;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            if(m.count(sum - target) && pos<= m[sum-target]){
                ans++;
                pos = i;
            }
            m[sum] = i;
        }
        return ans;
    }
};
