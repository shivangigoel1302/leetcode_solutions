class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        vector<vector<int>>newmat(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(matrix[i][j] == 0){
                    newmat[i][j] = 0;

                    q.push({i,j});
                }
            }
        }
        int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newr = p.first + dir[i][0];
                int newc = p.second + dir[i][1];
                if(newr >=0 && newr < r && newc >=0 && newc <c){
                    if(newmat[p.first][p.second] + 1 < newmat[newr][newc]){
                        newmat[newr][newc] =  newmat[p.first][p.second] + 1;
                        q.push({newr,newc});
                    }
                }
            }
        }
        return newmat;
    }
};
