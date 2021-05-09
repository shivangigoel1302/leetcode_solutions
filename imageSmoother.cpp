class Solution {
public:
    int getavg(int i, int j , vector<vector<int>>& M){
        int sum = M[i][j];
        int count = 1;
        if(j-1>=0){
            sum+=M[i][j-1];
            count++;
        }
        if(j+1<M[i].size()){
            sum+=M[i][j+1];
            count++;
        }
        if(i-1>=0){
            if(j-1>=0){
                sum+=M[i-1][j-1];
                count++;
            }
            if(j+1<M[i].size()){
                sum+=M[i-1][j+1];
                count++;
            }
            sum+=M[i-1][j];
            count++;
        }
        if(i+1 < M.size()){
            if(j-1>=0){
                sum+=M[i+1][j-1];
                count++;
            }
            if(j+1<M[i].size()){
                sum+=M[i+1][j+1];
                count++;
            }
            sum+=M[i+1][j];
            count++;
        }
        return sum/count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>>ans;
        for(int i = 0 ; i < M.size(); i++){
            vector<int>v;
            for(int j = 0 ; j < M[i].size(); j++){
                int avg = getavg(i,j,M);
                v.push_back(avg);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
