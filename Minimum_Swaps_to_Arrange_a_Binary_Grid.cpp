class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int>arr(m,-1);
        for(int i = 0; i < m ;i++){
            int j = m-1;
            while(j >=0 && grid[i][j] == 0){
                j--;
            }
            if(j != -1){
                arr[i] = j;
            }
        }
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        for(int i = 0 ; i < temp.size(); i++){
            if(temp[i] > i) return -1;
        }
        int count = 0;
        for(int i = 0 ; i< m ; i++){
            int j = i;
            while(j < m && arr[j] > i){
                j++;
            }
            count += j-i;
            if(j < arr.size()){
                int k = j;
                while(k > i){
                    swap(arr[k],arr[k-1]);
                    k--;
                }
            }
        }
        return count;
    }
};
