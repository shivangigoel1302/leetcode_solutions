class Solution {
public:
    int findparent(int val,vector<int>&parent){
        if(parent[val] == val){
            return val;
        }
        return parent[val] = findparent(parent[val],parent);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int>parent(n);
        for(int i =0 ; i < n ; i++){
            parent[i] = i;
        }
        for(int i = 0 ; i < allowedSwaps.size(); i++){
            int pi = findparent(allowedSwaps[i][0],parent);
            int pe = findparent(allowedSwaps[i][1],parent);
            if(pi != pe){
                parent[pi] = pe;
            }
        }
        map<int,vector<int>>m;
        int hamming = 0;
        for(int i = 0 ; i < n ; i++){
            int p = findparent(i,parent);
            m[p].push_back(i);
        }
        for(auto i : m){
            map<int,int>v1;
            for(int j = 0 ; j < i.second.size(); j++){
                v1[source[i.second[j]]]++;
            }
            for(int j =0 ; j < i.second.size(); j++){
                if(v1[target[i.second[j]]] <= 0){
                    hamming++;
                }
                else{
                    v1[target[i.second[j]]]--;
                }
            }
        }
        return hamming;
    }
};
