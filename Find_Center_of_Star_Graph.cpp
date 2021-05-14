class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int v = 0;
        for(auto it: edges){
            v = max(v,max(it[0],it[1]));
        }
        vector<int>indegree(v+1,0);
        for(auto it: edges){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        for(int i = 1; i <= v; i++){
            if(indegree[i] == v-1){
                return i;
            }
        }
        return -1;
    }
};
