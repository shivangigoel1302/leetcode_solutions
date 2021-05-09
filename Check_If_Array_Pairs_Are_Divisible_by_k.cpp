class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int remain[k];
        for(int i = 0 ; i < k ; i++){
            remain[i] = 0;
        }
        for(int i = 0 ; i < arr.size(); i++){
            remain[(arr[i]%k + k)%k] ++;
        }
        if(remain[0] %2 != 0){
            return false;
        }
        int pairs = remain[0] /2;
        for(int i = 1 ; i <=k/2 ; i++){
            if(remain[i] != remain[k-i]){

                return false;
            }
            pairs += remain[i]/2;
        }
        if(pairs = arr.size()/2) return true;
        return false;
    }
};
