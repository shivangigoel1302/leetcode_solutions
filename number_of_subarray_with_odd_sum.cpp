class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd =0, even = 0;
        int ans = 0;
        int mod = 1e9+7;
        if(arr[0] %2 ==0){
            even++;
        }
        else{
            odd++;
            ans++;
        }
        for(int i = 1 ; i < arr.size(); i++){
            arr[i] = arr[i]+ arr[i-1];
            if(arr[i]%2 ==1){
                ans++;
                odd++;
                ans += even;
            }
            else{
                even++;
                ans += odd;
            }
            ans%=mod;
        }
        return ans;
    }
};
