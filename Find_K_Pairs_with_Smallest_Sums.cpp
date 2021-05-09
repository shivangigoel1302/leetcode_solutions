class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.first+a.second>=b.first+b.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() ==0 || nums2.size() == 0|| k == 0){
            return {};
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i = 0 ; i < nums1.size(); i++){
            for(int j = 0 ; j < nums2.size(); j++){
                pq.push({nums1[i],nums2[j]});
            }
        }
        vector<vector<int>>ans;
        int size = min(k,int(pq.size()));
        for(int s=0;s<size;s++){
            pair p = pq.top();
            pq.pop();
            vector<int>v;
            v.push_back(p.first);
            v.push_back(p.second);
            ans.push_back(v);
        }
        return ans;
    }
};
