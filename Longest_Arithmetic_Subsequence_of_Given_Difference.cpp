class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int>dp(arr.size(),1);
        int ans = 1;
        unordered_map<int,int>m;
        for(int i = 0 ; i < arr.size(); i++){
            if(m.find(arr[i] - difference) != m.end()){
                m[arr[i]] = max(m[arr[i]],m[arr[i] - difference] + 1);
            }
            else{
                m[arr[i]] = 1;
            }
            ans = max(ans,m[arr[i]]);
        }
        return ans;
    }
};
