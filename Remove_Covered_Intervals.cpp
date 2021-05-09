bool compare(vector<int>v1,vector<int>v2){
    if(v1[0] == v2[0]){
        return v1[1] >v2[1];
    }
    return v1[0] < v2[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int count = 0;
        for(int i = 0 ; i < intervals.size();){
            //cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            int right = intervals[i][1];
            int j = i+1;
            while(j < intervals.size() && right >= intervals[j][1]){
                j++;
            }
            count += 1;
            i = j;
        }
        return count;
    }
};
