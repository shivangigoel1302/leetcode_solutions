class Solution {
public:
    int numberOfSubarrays(vector<int>& n, int k) {
        map<int,int>m;
        m[0] = 1;
        vector<int>nums(n.size(),0);
        if(n[0]%2 == 0){
            nums[0] = 0;
        }
        else{
            nums[0] = 1;
        }
        for(int i = 1 ; i < n.size(); i++){
            nums[i] = n[i]%2?1:0;
            nums[i] += nums[i-1];

        }
        int sum = 0;
        int count = 0;
        m[0] = 1;
        for(int i = 0 ; i < nums.size(); i++){
            if(m.find(nums[i] - k) != m.end()){
                count += m[nums[i] - k];
            }
            m[nums[i]]++;
        }
        return count;
    }
};
