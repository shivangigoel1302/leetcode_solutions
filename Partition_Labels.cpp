// bool compare(pair<int,int>p1,pair<int,int>p2){
//     return p1.first < p2.first;
// }
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int n = S.size();
        for(int i = 0; i < n ; i++){
            if(first[S[i]-'a'] == -1){
                first[S[i]-'a'] = i;
            }
        }
        for(int i = n-1; i >=0 ;i--){
            if(last[S[i]-'a'] == -1){
                last[S[i]-'a'] = i;
            }
        }
        vector<pair<int,int>>intervals;
        for(int i = 0 ; i < 26; i++){
            if(first[i] != -1 && last[i] != -1){
                intervals.push_back({first[i],last[i]});
            }
        }
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>merged;

        int i = 0;

        cout<<endl<<endl;
        while(i < intervals.size()){
            int right = intervals[i].second;
            int j = i+1;
            while(j < intervals.size() && right >= intervals[j].first){
                right = max(right,intervals[j].second);
                j++;
            }
            merged.push_back({intervals[i].first,right});

            i = j;
        }
        vector<int>ans;
        for(int i = 0 ; i < merged.size(); i++){
            int d = merged[i].second - merged[i].first + 1;
            ans.push_back(d);
        }
        return ans;
    }
};
