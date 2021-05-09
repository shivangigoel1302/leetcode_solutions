class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        pair<int,int>p1={INT_MAX/3,INT_MAX/3};
        pair<int,int>p2={INT_MAX/3,INT_MAX/3};
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]%3 == 1){
                if(nums[i] < p1.first){
                    p1.second = p1.first;
                    p1.first = nums[i];
                }
                else if (nums[i] < p1.second){
                    p1.second = nums[i];
                }
            }
            else if(nums[i]%3 ==2){
                if(nums[i] < p2.first){
                    p2.second = p2.first;
                    p2.first = nums[i];
                }
                else if(nums[i] < p2.second){
                    p2.second = nums[i];
                }
            }
            sum += nums[i];
        }
        if(sum%3 == 0) return sum;
        int m = sum;
        if(sum%3 == 1){
             m = min(m,min(p1.first,p2.first + p2.second));
        }
        else if(sum%3 ==2){
            m = min(m,min(p1.first+p1.second,min(p2.first,p1.first+p2.first+p2.second)));
        }
        return sum - m;
    }
};
