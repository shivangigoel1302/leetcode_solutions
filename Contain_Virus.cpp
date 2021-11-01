class Solution {
    int numWalls = 0;
    unordered_set<int> adjZeroCells;
    int currIt = 1;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
public:
    void getInfo(vector<vector<int>>& mat, int i, int j) {
        mat[i][j] = currIt+1;
        for(int d = 0; d < 4; d++) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if(x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size()) continue;
            if(mat[x][y] == 0) {
                adjZeroCells.insert(x*mat[0].size()+y);
                numWalls++;
            } else if(mat[x][y] == currIt) getInfo(mat, x, y);
        }
    }
    void wallOff(vector<vector<int>>& mat, int i, int j) {
        mat[i][j] = -1;
        for(int d = 0; d < 4; d++) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if(x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size()) continue;
            if(mat[x][y] == currIt) wallOff(mat, x, y);
        }
    }
    void spreadVirus(vector<vector<int>>& mat, int i, int j) {
        mat[i][j] = currIt+1;
        for(int d = 0; d < 4; d++) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if(x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size()) continue;
            if(mat[x][y] == 0) mat[x][y] = currIt+1;
            else if(mat[x][y] == currIt) spreadVirus(mat, x, y);
        }
    }

    int containVirus(vector<vector<int>>& mat) {
        int ans = 0;
        while(true) {
            int bi,bj;
            int maxNewlyInf = INT_MIN;
            int bestNumWalls;
            for(int i = 0; i < mat.size(); i++) {
                for(int j = 0; j < mat[0].size(); j++) {
                    if(mat[i][j] != currIt) continue;
                    numWalls = 0;
                    adjZeroCells.clear();
                    getInfo(mat, i, j);
                    int newlyInf = adjZeroCells.size();
                    if(newlyInf > maxNewlyInf) {
                        maxNewlyInf = newlyInf;
                        bi = i;
                        bj = j;
                        bestNumWalls = numWalls;
                    }
                }
            }
            currIt++;
            if(maxNewlyInf == INT_MIN) return ans;
            wallOff(mat,bi,bj);
            ans += bestNumWalls;

            for(int i = 0; i < mat.size(); i++) {
                for(int j = 0; j < mat[0].size(); j++) {
                    if(mat[i][j] != currIt) continue;
                    spreadVirus(mat, i, j);
                }
            }
            currIt++;
        }

        return ans;
    }
};
