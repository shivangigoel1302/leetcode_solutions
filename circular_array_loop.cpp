class Solution {
public:
    bool isCycle(int i ,vector<int>& nums){
        unordered_set<int>s;
        vector<int>v;
        int n = nums.size();
        bool forward = false;
        bool backward = false;
        if(nums[i] > 0 ){
            forward = true;
        }
        else{
            backward= true;
        }
        int start = i;
        while(s.find(i) == s.end() && s.size()<= nums.size() ){
            s.insert(i);

            int index = nums[i] + i;
             if(index > 0){
                index = index%n;
            }
            else if(index< 0){
                index = n - (-index)%n;
            }
            if(nums[index] > 0 && backward){
                return false;
            }
            if(nums[index] < 0 && forward ){
                return false;
            }
            i = index;
        }

        if(s.size()>1 && start == i){
            return true;
        }
        return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() ==1){
            return false;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(isCycle(i,nums)){
                return true;
            }
        }
        return false;
    }
};
