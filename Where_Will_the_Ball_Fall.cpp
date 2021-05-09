class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>ans;
        for(int i = 0 ; i < n; i++){
            pair<int,int>ball = {-1,-1};
            int k = i;
            int j = 0;
            while(j < m && k < n){
                if(grid[j][k] == 1){
                    if(k + 1 < n && grid[j][k+1] == 1){
                        ball = {j,k+1};
                        j++;
                        k++;
                    }
                    else{
                       ball ={-1,-1};
                        break;
                    }
                }
                else if(grid[j][k] == -1){
                    if(k-1 >= 0 && grid[j][k-1] == -1){
                        ball = {j,k-1};
                        j++;
                        k--;
                    }
                    else{
                        ball ={-1,-1};
                        break;
                    }
                }
            }
            ans.push_back(ball.second);
        }
        return ans;
    }
};
