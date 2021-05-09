class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size()-2; i++){
            int t = target - arr[i];
            int l = i+1;
            int r = arr.size()-1;
            while(l < r){
                if(arr[l] + arr[r] < t){
                    l++;
                }
                else if(arr[l] + arr[r] > t){
                    r--;
                }
                else if(arr[l] != arr[r]){
                    int x = l;
                    while(arr[x] == arr[l]){
                        x++;
                    }
                    int y = r;
                    while(arr[y] == arr[r]){
                        y--;
                    }
                   ans += (x-l)*(r-y)%mod;
                    ans%=mod;
                    l = x;
                    r = y;
                }
                else{
                    ans += (r-l+1)*(r-l)/2;
                    ans %= mod;
                    break;
                }
            }
        }
        return ans;
    }
};
