class Solution {
public:
    long long getsum(long long int ele,long long int val){
        long long ans = 0;
        ans = ele*val - (ele*(ele + 1))/2;
        return ans;
    }
    int maxValue(int n, int index, int maxSum) {

       long long int l = 1,r = maxSum;
        long long int ans = INT_MIN;
        while(l <= r){
            long long int mid = (l+r)/2;
            long long int left = getsum(min((long long)index,mid-1),mid);
             left += max((long long)0,index - mid + 1);
            long long int right = getsum(min((long long)n-index-1,mid-1),mid);
            right += max((long long)0,n - index - mid);
            if(left + right + mid <= maxSum){
                ans = max(ans,mid);
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
