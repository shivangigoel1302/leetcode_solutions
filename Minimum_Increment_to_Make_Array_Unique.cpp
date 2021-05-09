class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int>count(100000,0);
        for(auto x: A){
            count[x]++;
        }
        int ans = 0;
        int taken = 0;
        for(int x = 0 ; x< count.size(); x++){
            if(count[x] >= 2){
                taken += count[x]-1;
                ans -= x*(count[x] -1);
            }
            else if(taken > 0 && count[x] == 0){
                taken --;
                ans += x;
            }
        }
        return ans;
    }
};
