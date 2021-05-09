class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int M = grid.size() * 3;
        int N = grid[0].size() * 3;
        vector<vector<int>> newGrid(M, vector<int>(N, 0));
        for (int i = 1, ii = 0; i < M; i += 3, ii++) {
            for (int j = 1, jj = 0; j < N; j += 3, jj++) {
                if (grid[ii][jj] == 1) {
                    newGrid[i][j] = newGrid[i][j + 1] = newGrid[i][j - 1] = 1;
                }
                if (grid[ii][jj] == 2) {
                    newGrid[i][j] = newGrid[i - 1][j] = newGrid[i + 1][j] = 1;
                }
                if (grid[ii][jj] == 3) {
                    newGrid[i][j - 1] = newGrid[i + 1][j] = newGrid[i][j] = 1;
                }
                if (grid[ii][jj] == 4) {
                    newGrid[i][j + 1] = newGrid[i + 1][j] = newGrid[i][j] = 1;
                }
                if (grid[ii][jj] == 5) {
                    newGrid[i][j] =  newGrid[i - 1][j] = newGrid[i][j - 1] = 1;
                }
                if (grid[ii][jj] == 6) {
                    newGrid[i][j] =  newGrid[i - 1][j] = newGrid[i][j + 1] = 1;
                }
            }
        }
        queue<vector<int>> cellsQ;
        cellsQ.push({1, 1});
        newGrid[1][1] = 0;
        while (!cellsQ.empty()) {
            vector<int> cur = cellsQ.front();
            cellsQ.pop();
            if (cur[0] == M - 2 && cur[1] == N - 2) {
                return true;
            }
            // Check Neighbours
            for (vector<int> &dir : dirs) {
                int nx = cur[0] + dir[0];
                int ny = cur[1] + dir[1];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && newGrid[nx][ny] == 1) {
                    cellsQ.push({nx, ny});
                    newGrid[nx][ny] = 0;
                }
            }
        }
        return false;
    }
};
