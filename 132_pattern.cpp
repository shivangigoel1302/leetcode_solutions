class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int fin[nums.size()];
        fin[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            fin[i] = min (fin[i-1],nums[i]);
        }
        stack<int>s;
        for(int i = nums.size()-1; i>=0; i--){

                if(fin[i] < nums[i]){
                    while(!s.empty() &&( s.top()<=fin[i] )){
                        s.pop();
                    }
                    // if(s.empty() ){
                    //     return false;
                    // }
                    if(!s.empty() && s.top() <nums[i]){
                        return true;
                    }
                     s.push(nums[i]);
                }


        }
        return false;
    }
};
