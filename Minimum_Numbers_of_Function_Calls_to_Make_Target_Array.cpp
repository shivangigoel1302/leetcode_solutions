class Solution {
public:
    bool hasnonzero(vector<int>&nums){
        for(auto c : nums){
            if(c!=0){
                return true;
            }
        }
        return false;
    }
    int oddnums(vector<int>& nums){
        int count = 0 ;
        if(nums.size() == 0){
            return 0;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]%2 == 1){
                count++;
                nums[i]--;
            }
        }
        return count;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0 ;
        while(hasnonzero(nums)){
            int oddcount = oddnums(nums);
            if(oddcount){
                ans+=oddcount;
            }
            else{
                for(int i = 0 ; i < nums.size(); i++){
                    nums[i]= nums[i]/2;
                }
                ans++;
            }
        }
        return ans;
    }
};
