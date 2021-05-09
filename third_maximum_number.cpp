class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        auto start=s.begin();
        if(s.size()<3)
        {
            advance(start,s.size()-1);
            return *start;
        }
        else
        {
            int pos=s.size()-3;
           advance(start,pos);
            return *start;
        }
    }
};
