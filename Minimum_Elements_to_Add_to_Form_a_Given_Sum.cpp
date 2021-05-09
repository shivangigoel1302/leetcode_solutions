class Solution {
public:
    int minElements(vector<int>& nums,long long int limit,long long int goal) {
        long long int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        long long int req = abs(goal - sum);
        long long int num = min(req,limit);
        long long int count = 0;
        while(req > 0){
            while( req - num >= 0){
                count += (req/num);
                req -= (req/num)*num;
            }
            num = min(req,limit);
        }
        return count;
    }
};
