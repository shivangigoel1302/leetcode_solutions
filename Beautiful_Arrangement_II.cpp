class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans(n);
        int i = 0;
        for(int j = 1; j <= n-k-1; j++){
            ans[i++] = j;
        }
        int l = n-k;
        int r = n;
        int flag = 1;
        while(l <= r){
            if(flag){
                ans[i++] = l++;
            }
            else{
                ans[i++] = r--;
            }
            flag ^= 1;
        }
        return ans;
    }
};
