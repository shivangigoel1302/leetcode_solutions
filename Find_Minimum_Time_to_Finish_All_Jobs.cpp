class Solution {
public:
    int minload = INT_MAX;
    int currload = 0;
    vector<int>worker;
    void helper(int left, int i,vector<int>&jobs,int k){
        if(i >= jobs.size()){
            minload = min(minload,currload);
            return;
        }
        for(int j = min(left+1,k-1); j>= 0; j--){
            int temp = currload;
            worker[j] += jobs[i];
            currload = max(currload,worker[j]);
            if(currload < minload){
                helper(max(left,j),i+1,jobs,k);
            }
            worker[j] -= jobs[i];
            currload = temp;
        }
        return;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        worker.resize(k,0);
        helper(-1,0,jobs,k);
        return minload;
    }
};
