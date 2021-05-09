class Solution {
public:
    int find(vector<int>arr, int val){
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] == val){
                return i;
            }
        }
        return -1;
    }
    void flip(vector<int>&arr,int index){
        int j = index;
        int i = 0;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        for(int valuetoSort = arr.size(); valuetoSort > 0 ; valuetoSort--){
            int index = find(arr,valuetoSort);
            if(index == valuetoSort-1){
                continue;
            }
            if(index != 0){
                ans.push_back(index+1);
                flip(arr,index);
            }
            ans.push_back(valuetoSort);
            flip(arr,valuetoSort-1);
        }
        return ans;
    }
};
