class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         if(k > arr.size()){
            return *max_element(arr.begin(),arr.end());
        }
        int count = 0;
        int m = arr[0],x=arr[0],i =1;
        while(count != k){
            arr.push_back(min(m,arr[i]));
            m = max(m,arr[i]);
            if(m == x){
                count++;
            }
            else{
                x= arr[i];
                count = 1;
            }
            i++;
        }
        return m;
    }
};
