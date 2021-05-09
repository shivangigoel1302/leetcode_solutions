class Solution {
public:
    vector<int>used;
    vector<int>arr;
    int n1;
    bool dfs(int i, int n){
        if(n == 0){
            return true;
        }
        while(arr[i] != 0){
            i++;
        }
        for(int j = n1; j >=1; j--){
             if(used[j] == 1){
                 continue;
             }
            int k = j!=1 ? j:0;
            if(i + k < 2*n1-1 && arr[i+k] == 0){
                arr[i] = j;
                arr[i+k] = j;
                used[j] = 1;
                bool next = dfs(i + 1,n-1);
                if(next) return true;
                arr[i] = 0;
                arr[i+k]=0;
                used[j] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        used.resize(n+1,0);
        n1 = n;
        arr.resize(2*n-1,0);
        dfs(0,n);
        return arr;
    }
};
