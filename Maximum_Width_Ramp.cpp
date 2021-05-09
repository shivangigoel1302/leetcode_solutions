class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        int lmin[n],rmax[n];
        lmin[0] = A[0];
        for(int i = 1; i <n ; i++){
            lmin[i] = min(lmin[i-1],A[i]);
        }
        rmax[n-1] = A[n-1];
        for(int i = n-2; i>=0 ;i--){
            rmax[i] = max(rmax[i+1],A[i]);
        }
        int ans = 0;
        int i = 0;
        int j =0;
        while(i < n&& j < n){
            if(lmin[i] <= rmax[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
