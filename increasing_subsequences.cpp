class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>v, int i, vector<int>nums,set<vector<int>>&s){
        if(i >= nums.size()){
            //cout<<"hi"<<" ";
            if(v.size() >=2){
                if(s.find(v) == s.end()){
                    ans.push_back(v);
                    s.insert(v);
                }
            }
            return;
        }
        if(v.empty() || nums[i] >= v.back()){
            v.push_back(nums[i]);
            helper(v,i+1,nums,s);

            v.pop_back();
        }
        helper(v,i+1,nums,s);
        v.pop_back();
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
       set<vector<int>>s;
        helper(v,0,nums,s);
        return ans;
    }
};
