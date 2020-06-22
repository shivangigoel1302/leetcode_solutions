class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            int j=i-1;
            int key=nums[i];
            while(j>=0&&key<nums[j])
            {
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
    }
};
