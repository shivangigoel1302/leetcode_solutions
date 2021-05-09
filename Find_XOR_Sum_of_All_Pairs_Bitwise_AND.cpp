class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = 0;
        for(int i = 0 ; i < arr1.size(); i++){
            x = x ^ arr1[i];
        }
        int ans = 0;
        for(int i = 0 ; i < arr2.size(); i++){
            ans = ans ^ (x & arr2[i]);
        }
        return ans;
    }
};
