class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sumodd = 0,sumeven = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(i%2 == 0){
                sumeven += nums[i];
            }
            else{
                sumodd += nums[i];
            }
        }
        int ans = 0;
        int newodd = 0,neweven = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(i%2 == 1){
                if(neweven + sumodd - nums[i] == newodd + sumeven){
                    ans++;
                }
                newodd += nums[i];
                sumodd -= nums[i];
            }
            else{
                if(newodd + sumeven - nums[i] == neweven + sumodd){
                    ans++;
                }
                neweven += nums[i];
                sumeven -= nums[i];
            }
        }
        return ans;
    }
};
