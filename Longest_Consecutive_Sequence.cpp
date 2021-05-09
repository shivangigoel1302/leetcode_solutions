class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int>s;
        for(int i = 0 ; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0 ;i < nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){
                int currnum = nums[i];
                int count = 1;
                while(s.find(currnum + 1) != s.end()){
                    currnum +=1;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
