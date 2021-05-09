class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long sum = 0;
        for(int i = 0 ; i < wall[0].size(); i++){
            sum += wall[0][i];
        }
        //vector<int>line(sum+1,0);
        unordered_map<int,int>m;
        for(int i = 0 ; i < wall.size(); i++){
            int width = 0;
            for(int j = 0 ; j < wall[i].size()-1; j++){
                width += wall[i][j];
                m[width]++;
            }
            //cout<<line[width]<<" ";
            //line[0]++;
        }
        int maxline = INT_MIN;
        for(auto i : m){
            maxline = max(maxline,i.second);
        }
        if(maxline == INT_MIN){
            return wall.size();
        }
        return wall.size() - maxline;
    }
};
