class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {

        constexpr int kMod = 1e9 + 7;

        int rowN = grid.size();
        int colN = grid[0].size();

        vector<vector<long>> dp_max (rowN, vector<long>(colN));
        vector<vector<long>> dp_min (rowN, vector<long>(colN));

        dp_max[0][0] = dp_min[0][0] = grid[0][0];

        for (int col = 1; col < colN; col++)
        {
            dp_max[0][col] = dp_min[0][col] = dp_min[0][col-1] * grid[0][col];
        }

        for (int row = 1; row < rowN; row++)
        {
            dp_max[row][0] = dp_min[row][0] = dp_min[row-1][0] * grid[row][0];
        }

        for (int row = 1; row < rowN; row++)
        {
            for (int col = 1; col < colN; col++)
            {
                if (grid[row][col] >= 0)
                {
                    dp_max[row][col] = max(dp_max[row-1][col], dp_max[row][col-1]) * grid[row][col];
                    dp_min[row][col] = min(dp_min[row-1][col], dp_min[row][col-1]) * grid[row][col];
                }
                else
                {
                    dp_max[row][col] = min(dp_min[row-1][col], dp_min[row][col-1]) * grid[row][col];
                    dp_min[row][col] = max(dp_max[row-1][col], dp_max[row][col-1]) * grid[row][col];
                }
            }
        }

        return (dp_max[rowN-1][colN-1] < 0) ? -1 : dp_max[rowN-1][colN-1] % kMod;
    }
};
