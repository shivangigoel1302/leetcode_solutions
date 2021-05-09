class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001]={0};
        for(int x: nums){
            count[x]++;
        }
        int avoid = 0,use=0,prev=-1;
        for(int k = 0 ; k < 10001; k++){
            if(count[k] > 0){
                int m = max(avoid,use);
                if(k-1 != prev){
                    use = count[k]*k + m;
                    avoid = m;
                }
                else{
                    use = count[k]*k + avoid;
                    avoid = m;
                }
                prev = k;
            }
        }
        return max(avoid,use);
    }
};
