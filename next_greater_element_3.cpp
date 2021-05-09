class Solution {
public:
    bool outOfInt(string nums){
        string max = "2147483647";
        if(nums.size() >= 10){
            return true;
        }
        if(nums.size() <= 9){
            return false;
        }
        for(int i = 0 ; i < 10 ; i++){
            if(nums[i] > max[i]){
                return true;
            }
            else if(nums[i] < max[i]){
                return false;
            }
        }
        return false;
    }
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        for(int i = nums.size()-1 ; i >0 ;i--){
            if(nums[i] > nums[i-1]){
                int minindex = i;
                int diff = INT_MAX;
                for(int j = i ; j < nums.size(); j++){
                    if(nums[j] - nums[i-1] <= diff && nums[j] - nums[i-1] > 0){
                        minindex = j;
                        diff = nums[minindex] - nums[i-1];
                    }
                }
                swap(nums[i-1],nums[minindex]);
                reverse(nums.begin()+i,nums.end());
                if(outOfInt(nums)) return -1;
                n = stoi(nums);
                return n;
            }
        }
        return -1;
    }
};
