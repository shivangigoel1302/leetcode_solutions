class Solution {
public:
    bool ksum(vector<int>&buckets,int i, vector<int>&nums,int sum){
        if(i == nums.size()){
            return true;
        }
        for(int j = 0; j < buckets.size(); j++){
            if(buckets[j] + nums[i] > sum){
                continue;
            }
            buckets[j] += nums[i];
             if(i == nums.size()-1){
            return true;
        }
            if(ksum(buckets,i+1,nums,sum)){
                return true;
            }
            buckets[j] -= nums[i];
            if(buckets[j] == 0){
                return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        if(sum %k != 0){
            return false;
        }
        sum/=k;
        vector<int>buckets(k,0);
        return ksum(buckets,0,nums,sum);

    }
};
