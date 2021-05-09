class Solution {
public:
    void findans(int &ans,vector<bool>visited,int n, int i){
        if(i > n){
            ans++;
            return;
        }
        for(int j = 1; j <= n; j ++){
            if(visited[j] == true){
                continue;
            }
            if(j % i == 0 || i %j == 0){
                visited[j] = true;
                findans(ans,visited,n,i+1);
                visited[j] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>visited(n+1,false);
        int ans = 0;
        findans(ans,visited,n,1);
        return ans;
    }
};
