class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,vector<int>>m;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto p : m){
            int n = p.second.size();
            count += n*(n-1)/2;
        }
        return count;
    }
};
