class Solution {
public:
    vector<vector<int>>ans;
    void getsubset(vector<int>&nums, int i , vector<int>&v,set<vector<int>>&s){
        if(i == nums.size()){
            if(s.find(v) == s.end()){
                ans.push_back(v);
                s.insert(v);
            }
            return;
        }
        v.push_back(nums[i]);
        getsubset(nums,i+1,v,s);
        v.pop_back();
        getsubset(nums,i+1,v,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        set<vector<int>>s;
        getsubset(nums,0,v,s);
        return ans;
    }
};
