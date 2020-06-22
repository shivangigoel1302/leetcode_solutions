class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++)
        {
            for(int j=i+1;j<intervals.size();j++)
            {
                if(intervals[i][0]>intervals[j][0])
                {
                    swap(intervals[i],intervals[j]);
                }
            }
        }
        for(int l=0;l<intervals.size();)
        {
            int i=l+1;
            int right = intervals[l][1];
            while(i<intervals.size()&&right>=intervals[i][0])
            {
                right=max(right,intervals[i][1]);
                i++;
            }
            vector<int>v;
            v.push_back(intervals[l][0]);
            v.push_back(right);
            ans.push_back(v);
            l=i;

        }
        return ans;
    }
};
