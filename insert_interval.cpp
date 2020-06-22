class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.size()==0)
        {
            return intervals;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
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
