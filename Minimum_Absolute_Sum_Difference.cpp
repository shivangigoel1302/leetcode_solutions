class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sorted(nums1.begin(),nums1.end());
        sort(sorted.begin(),sorted.end());
        int mod = 1e9+7;
        vector<int>mindiff(sorted.size(),INT_MAX);
        for(int i = 0; i < sorted.size(); i++){
            auto it = upper_bound(sorted.begin(),sorted.end(),nums2[i]);
            if(it != sorted.end()){
                mindiff[i] = min(mindiff[i],abs(*it - nums2[i]));
            }
            if(it != sorted.begin()){
                it--;
                mindiff[i] = min(mindiff[i],abs(*it - nums2[i]));
            }
        }
        long long sum = 0;
        long long maxdiff = 0;
        for(int i = 0; i < sorted.size(); i++){
            long long int curr = abs(nums1[i] - nums2[i]);
            sum += curr;
            sum %= mod;
            if(curr > mindiff[i]){
                maxdiff = max(maxdiff, (long long)curr - mindiff[i]);
            }
        }
        sum -= maxdiff;
        if(sum < 0){
            sum += mod;
        }
        return (int)sum;
    }
};
