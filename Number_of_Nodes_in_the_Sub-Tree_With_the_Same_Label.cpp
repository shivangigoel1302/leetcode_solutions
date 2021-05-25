class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&ans,vector<int>&count,string& l,int i){
        if(ans[i] == 0){
            ans[i] = 1;
            for(auto j : adj[i]){
                vector<int>count1(26,0);
                if(ans[j] != 0){
                    continue;
                }
                dfs(adj,ans,count1,l,j);
                for(int k = 0; k < 26; k++){
                    count[k] += count1[k];
                }
            }
            count[l[i]-'a']++;
            ans[i] = count[l[i]-'a'];
        }
        return;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>count(26,0);
        vector<int>ans(n,0);
        vector<int>adj[n];
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj,ans,count,labels,0);
        return ans;
    }
};
