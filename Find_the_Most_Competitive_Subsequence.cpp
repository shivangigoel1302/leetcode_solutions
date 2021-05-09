class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>s;
        int remove = nums.size()-k;
        for(int i = 0 ; i < nums.size(); i++){
            while(remove >0 && !s.empty() && nums[i] < s.top()){
                s.pop();
                remove--;
            }
            s.push(nums[i]);
            if(remove == 0 && s.size() == k) break;
        }
        while(s.size() !=k ){
            s.pop();
        }
        vector<int>ans(k);
        int i = k-1;
        while(!s.empty()){
            ans[i] = s.top();
            i--;
            s.pop();
        }
        return ans;
    }
};
