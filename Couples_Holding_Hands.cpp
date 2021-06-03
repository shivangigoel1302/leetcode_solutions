class Solution {
public:
//     map<vector<int>,int>dp;
//     int helper(vector<int>&row,unordered_map<int,int>&m,int i){
//         if(i == row.size()){
//             return 0;
//         }
//         if(dp.find(row) != dp.end()){
//             return dp[row];
//         }
//         int temp = INT_MAX;
//         if(abs(row[i] - row[i+1]) == 1 && min(row[i],row[i+1])%2 == 0){

//         }
//         int idx;
//         if(row[i+1]%2 == 0){
//             int idx = m[row[i+1] + 1];

//         }
//         else{
//             int idx = m[row[i+1] - 1];
//         }
//         swap(row[idx],row[i]);
//         m[row[i]] = i;
//         m[row[idx]] = idx;
//         temp = min(temp,1+ helper(row,m,i+2));
//         swap(row[idx],row[i]);
//         m[row[i]] = i;
//         m[row[idx]] = idx;
//         if(row[i]%2 == 0){
//             idx = m[row[i]+1];
//         }
//         else{
//             idx = m[row[i] -1];
//         }
//         swap(row[idx],row[i+1]);
//         m[row[i+1]] = i+1;
//         m[row[idx]] = idx;
//         temp = min(temp,1+ helper(row,m,i+2));
//         swap(row[idx],row[i+1]);
//         m[row[i+1]] = i+1;
//         m[row[idx]] = idx;
//         return dp[] = temp;
//     }
    void swap(vector<int>&row,int i,int j,unordered_map<int,int>&m){
        int temp = row[j];
        row[j] = row[i];
        row[i] = temp;
        m[row[i]] = i;
        m[row[j]] = j;
        return;
    }
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int>m;

        for(int i = 0; i < row.size(); i++){
            m[row[i]] = i;
        }
//         return helper(row,m,0);
        int swaps = 0;
        for(int i = 0; i < row.size(); i+=2){
            int first = row[i];
            int second = first ^1;
            if(row[i+1] != second){
                swaps++;
                swap(row,i+1,m[second],m);
            }
        }
        return swaps;
    }
};
