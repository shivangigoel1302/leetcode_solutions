class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int  x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        queue<pair<int,int>>q;
        int count = 0;
        int curr = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    count++;
                    curr++;
                }
                else if(grid[i][j] == 1) count++;
            }
        }
        q.push({-1,-1});
        int ans = 0;
        while(!q.empty()){
           auto f = q.front();
            q.pop();
            //ans++;
            if(f.first == -1 && f.second == -1){
                //ans++;
                if(!q.empty()){
                    ans++;
                    q.push({-1,-1});
                }
                continue;
            }
            //cout<<f.first<<" "<<f.second<<endl;
            for(int i = 0 ; i < 4 ; i++){
                int r = f.first + x[i];
                int c = f.second + y[i];
                if(  r< grid.size() && r >=0 && c < grid[0].size() && c >=0){
                    if(grid[r][c] == 1){
                        //cout<<r<<","<<c<<" ";
                        curr++;
                        q.push({r,c});
                        grid[r][c] = 2;
                    }
                }
            }
        }
        if(curr != count) return -1;
        return ans;
    }
};
