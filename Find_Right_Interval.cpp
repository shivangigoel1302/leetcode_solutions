class Solution {
public:
    \
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>>v;
        for(int i = 0 ; i < intervals.size(); i++){
            v.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        sort(v.begin(),v.end());
        int l = 0;
        int h = v.size()-1;
        bool found = false;
        vector<int>ans;
        for(int i = 0 ; i < intervals.size(); i++){
            int target = intervals[i][1];
            l = 0;
            h= v.size() -1;
            found  = false;
            while(l <= h){
                int mid = (l+h)/2;
                if(v[mid].first.first == target){
                    found = true;
                    ans.push_back(v[mid].second);
                   break;
                }
                else if(v[mid].first.first > target){
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(found == false){
                if(l == v.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(v[l].second);
            }
            }


        }
        return ans;

    }
};
