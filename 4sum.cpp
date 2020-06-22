class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>>ans;
        set<vector<int>>seen;
        if(nums.size()<4)
        {
            return ans;
        }
        sort(begin(nums), end(nums));
        for(int i=0;i<nums.size();i++)
        {
            for(int k=i+1;k<nums.size();k++)
            {
                int l=k+1;
                int h=nums.size()-1;
                while(l<h)
                {
                    int sum=nums[i]+nums[k]+nums[l]+nums[h];
                    if(sum<target)
                    {
                        l++;
                    }
                    else if(sum>target)
                    {
                        h--;
                    }
                    else
                    {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        v.push_back(nums[h]);
                        if(seen.find(v)==seen.end())
                        {
                            ans.push_back(v);
                            seen.insert(v);
                        }
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
