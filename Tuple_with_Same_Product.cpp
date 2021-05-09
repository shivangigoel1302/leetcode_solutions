class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                m[nums[i]*nums[j]]++;
            }
        }
        for(auto i : m){
            ans += (i.second*(i.second -1));
        }
        ans *=4;
        return ans;
    }
};
