class Solution {
public:
    bool check(vector<int>bloomDay,int m , int k, int mid){
        int total = 0;
        int ans = 0;
        for(int i = 0 ; i < bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                total += 1;
            }
            else{
                if(total >= k){
                    ans++;
                }
                total = 0;
            }
            if(total >= k){
                ans++;
                total = 0;
            }
        }
        if(total >= k){
            ans++;
            total = 0;
        }
        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<m*k) return -1;
        int l = INT_MAX;
        int r = INT_MIN;
        int n = bloomDay.size();
        for(int i = 0 ; i < n ;i++){
            l = min(l,bloomDay[i]);
            r = max(r,bloomDay[i]);
        }
        while(l < r){
            int mid = (l+r)/2;
            if(check(bloomDay,m,k,mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
