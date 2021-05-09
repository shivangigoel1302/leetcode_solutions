class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size() == 0){
            return false;
        }
        if(arr.size() == 1){
            return true;
        }
        int difference = arr[1] - arr[0];
        int n = arr.size();
        for(int i = 2 ; i < n ; i++){
            if(arr[i] - arr[i-1] != difference){
                return false;
            }
        }
        return true;
    }
};
