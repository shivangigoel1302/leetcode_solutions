class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0 ;
        int r = arr.size() -1;
        while(l+1 < arr.size() && arr[l]<=arr[l+1]){
            l++;
        }
        while(r-1>=0 && arr[r-1] <= arr[r]){
            r--;
        }
        int ans = min(r,(int)arr.size()-l-1);
        if(ans == 0){
            return 0;
        }
        for(int i = 0 ; i < l+1 ; i++){
            int lb = lower_bound(arr.begin() + r,arr.end(), arr[i]) - arr.begin();
            ans= min(ans,lb-i-1);
        }
        return ans;
    }
};
