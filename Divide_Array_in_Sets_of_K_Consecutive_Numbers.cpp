class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        map<int,int>m;
        for(int i = 0 ; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second){
                int x = i.second;
                for(int j = 1; j < k; j++){
                    if(m[j + i.first] < x){
                        return false;
                    }
                    else{
                        m[j+i.first] -=x;
                    }
                }
            }
        }
        return true;
    }
};
