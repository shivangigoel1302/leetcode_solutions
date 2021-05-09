class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
       sort(arr.begin(),arr.end());
        int m = (arr.size()-1)/2;
        int median = arr[m];
        int i = 0;
        int j = arr.size()-1;
        vector<int>ans(k,0);
        int curr = 0;
        while(i <=j && curr < k){
            while(i < j && curr < k && abs(arr[i] - median) > abs(arr[j] - median)){
                ans[curr++] = arr[i];
                i++;
            }
            while(j >= i && curr <k && abs(arr[i] - median) <= abs(arr[j] - median)){
                ans[curr++] = arr[j];
                j--;
            }
        }
        return ans;
    }
};
