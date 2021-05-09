class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maximum = 0;
        int ans = 0;
        for(int i = 0 ; i < arr.size(); i++){
            maximum = max(maximum, arr[i]);
            if(maximum == i){
                ans++;
            }
        }
        return ans;
    }
};
