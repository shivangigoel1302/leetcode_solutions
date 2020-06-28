class Solution {
public:
    struct comp{
        bool operator()(int s1,int s2)
    {
        return to_string(s1)+to_string(s2)>to_string(s2)+to_string(s1);
    }

    }compare;
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0)
        {
            return "0";
        }
      sort(nums.begin(),nums.end(),compare);
        if(nums[0]==0)
        {
            return "0";
        }
          string str="";
        for(int i=0;i<nums.size();i++)
        {
            str+=to_string(nums[i]);
        }
        return str;
    }
};
