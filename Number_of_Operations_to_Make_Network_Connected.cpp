class Solution {
public:
    void dfs(int i, vector<int>v[],int &e, int &ver, int parent,vector<bool>&visited){
        visited[i] = true;
        e += v[i].size();
        ver++;

        for(auto nbr : v[i]){
            if(nbr == parent){
                continue;
            }

            if(!visited[nbr]){

                dfs(nbr,v,e,ver,i,visited);
            }

        }

        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>v[n];
        for(auto a : connections){
            v[a[0]].push_back(a[1]);
            v[a[1]].push_back(a[0]);
        }
        vector<bool>visited(n,false);
        int components = 0;
        int extra = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                components++;
                int edges = 0,vertices = 0;
                dfs(i,v,edges,vertices,-1,visited);

                 extra += edges/2 - vertices + 1;
            }
        }
        if(components == 1){
            return 0;
        }
        if(extra >= components - 1){
            return components - 1;
        }
        return -1;
    }
};
