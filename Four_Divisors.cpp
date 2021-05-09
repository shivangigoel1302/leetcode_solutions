class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int n = nums[i];
            int totalcount = 1;
            int totalsum = 1;
            for(int j = 2; j*j <= n; j++){
                int count = 0;
                int curr = 1;
                int currsum = 1;
                while(n % j == 0){
                    count++;
                    curr*=j;
                    currsum += curr;
                    n =n/j;
                }
                totalsum *= currsum;
                totalcount*=(count+1);
            }
           if(n > 1){
               totalsum*=(n+1);
               totalcount *= 2;
           }
            if(totalcount == 4){
                sum += totalsum;
            }
        }
        return sum;
    }
};
