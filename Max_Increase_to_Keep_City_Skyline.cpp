class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>top(grid[0].size(),0);
        vector<int>right(grid.size(),0);
        for(int i = 0 ; i < grid.size(); i++){
            int maximum = 0;
            for(int j = 0 ; j < grid[0].size(); j++){
                maximum = max(maximum,grid[i][j]);
            }
            right[i]=(maximum);
        }
         for(int i = 0 ; i < grid[0].size(); i++){
            int maximum = 0;
            for(int j = 0 ; j < grid.size(); j++){
                maximum = max(maximum,grid[j][i]);
            }
            top[i]=(maximum);
        }
        int sum = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                int minimum = min(right[i],top[j]);

                sum += minimum - grid[i][j];
            }

        }
        return sum;
    }
};
