class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                nums[i]=-1;
        }
        int cursum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            cursum+=nums[i];
            if(mp.find(cursum)!=mp.end()){
                maxlen=max(maxlen,(i-mp[cursum]));
            }
            if(cursum==0)
                maxlen=i+1;
            if(mp.find(cursum)==mp.end())
            mp[cursum]=i;
        }
        return maxlen;
    }
};
