class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<int>s;
        int count = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(s.find(nums[i])!=s.end()){
                continue;
            }
            for(int j = i+1 ; j <nums.size(); j++ ){
                if(nums[j] - nums[i] > k){
                    break;
                }
                if(nums[j] - nums[i] == k && s.find(nums[i])==s.end()){
                    count++;
                    s.insert(nums[i]);
                }
            }
        }
        return count;
    }
};
