class Solution {
public:
    int minDifference(vector<int>& nums) {
        int min1,min2,min3,min4 ,max1,max2,max3,max4;
        min1 = min2 = min3 = min4 = INT_MAX;
        if(nums.size() <= 3)return 0;
        max1= max2= max3 = max4 = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > max1){
                max4 = max3;
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max4 = max3;
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3){
                max4 = max3;
                max3 = nums[i];
            }
            else if(nums[i] > max4){
                max4 = nums[i];
            }
            if(nums[i] < min1){
                min4 = min3;
                min3 = min2;
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min4 = min3;
                min3 = min2;
                min2 = nums[i];
            }
            else if(nums[i] < min3){
                min4 = min3;
                min3 = nums[i];

            }
            else if(nums[i] < min4){
                min4 = nums[i];
            }
        }
        // cout<<min1<<" "<<min2<<" "<<min3<<" "<<min4<<endl;
        // cout<<max1<<" "<<max2<<" "<<max3<<" "<<max4;
        int a = max1 - min4;
        int b = max4 - min1;
        int c = max2- min3;
        int d = max3- min2;
        return min(min(a,b),min(c,d));
    }
};
