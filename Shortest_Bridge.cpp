class Solution {
private:
    void dfs(vector<vector<int>>& A,int i,int j,queue<pair<int,int>>& q){
        if(i < 0 || i>=A.size() || j<0 || j>= A[0].size() || A[i][j] != 1)
            return;
        q.push({i,j});
        A[i][j] = 10;
        dfs(A,i-1,j,q);
        dfs(A,i+1,j,q);
        dfs(A,i,j-1,q);
        dfs(A,i,j+1,q);
    }

public:
    int shortestBridge(vector<vector<int>>& A) {
        //two islands
        int m = A.size();
        int n = A[0].size();

        bool found = false;

        queue<pair<int,int>> q;
        for(int i = 0; i < m && !found; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] == 1){
                    dfs(A,i,j,q);
                    found = true;
                    break;
                }
            }
        }

        set<pair<int,int>> seen;

        int ans = 0;

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(auto d : dirs){
                    int i = x + d[0];
                    int j = y + d[1];
                    if(i <0 || i>=m || j<0 || j>= n || A[i][j] == 10)
                        continue;
                    if(A[i][j] == 1)
                        return ans;
                    A[i][j] = 10;
                    q.push({i,j});
                }

            }
            ans++;
        }

       return ans;

    }
};
