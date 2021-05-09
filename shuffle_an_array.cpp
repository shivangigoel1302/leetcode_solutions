class Solution {
public:
    vector<int>a;
    Solution(vector<int>& nums) {
        a=nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>temp=a;
        vector<int>ans;
        while(temp.size()!=0)
        {
            int ran=rand()%temp.size();
            ans.push_back(temp[ran]);
            int last=temp[temp.size()-1];
            temp[ran]=last;
            temp.pop_back();
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
