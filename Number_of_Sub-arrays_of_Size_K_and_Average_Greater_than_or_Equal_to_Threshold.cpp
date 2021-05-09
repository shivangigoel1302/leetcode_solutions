class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int req = k*threshold;
        int sum = 0;
        int count= 0;
        for(int i = 0 ; i < k ; i++){
            sum += arr[i];
        }
        for(int i = k ;i < arr.size(); i++){
            if(sum >= req){
                count++;
            }
            sum += arr[i];
            sum -= arr[i-k];
        }
        if(sum >=req){
            count++;
        }
        return count;
    }
};
