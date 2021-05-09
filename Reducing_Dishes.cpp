class Solution {
public:

    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        for(int i = 0; i < n-1; i++){
            int temp = 0;
            int k = 1;
            for(int j = i ; j < n; j++){
                temp += (k++)*satisfaction[j];
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
