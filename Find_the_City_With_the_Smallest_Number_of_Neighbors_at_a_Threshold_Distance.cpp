class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int sz = n-1;

        vector<vector<int>>matrix(sz+1,vector<int>(sz+1,INT_MAX));
        for(int i = 0; i < edges.size(); i++){
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int k = 0; k <= sz; k++){
            for(int i = 0; i <= sz; i++){
                for(int j = 0; j <= sz; j++){
                    if(i != j && i!=k && matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        // for(int i = 0; i <= sz; i++){
        //     for(int j = 0; j <= sz; j++){
        //         cout<<matrix[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
        int min=INT_MAX,ans = -1;
        for(int i = 0; i <= sz; i++){
            int cnt = 0;
            for(int j = 0; j <= sz; j++){
                if(matrix[i][j] <= distanceThreshold){
                    // cout<<j<<" ";
                    cnt++;
                }
            }

            if(cnt <= min){
                min = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
