class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long int,long long int>>v;
        if(nums.size()==0)
        {
            return false;
        }
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)\
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(abs(v[j].first-v[i].first)<=t&&abs(v[j].second-v[i].second)<=k)
                {
                    return true;
                }
                if(abs(v[j].first-v[i].first)>t)
                {
                    break;
                }
            }
        }
        return false;
    }
};
