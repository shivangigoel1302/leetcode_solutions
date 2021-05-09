class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>stores(n+1,0);
        int maximum = INT_MIN;
        vector<int>v;
        for(int i = 1 ; i < rounds.size(); i++){
            if(rounds[i] > rounds[i-1]){
                for(int j = rounds[i-1] ; j < rounds[i]; j++){
                    stores[j]++;
                    if(stores[j] >maximum){
                        maximum = stores[j];
                    }
                }
            }
            else{
                for(int j = 1 ; j < rounds[i] ; j++){
                    stores[j]++;
                    if(stores[j] >maximum){
                        maximum = stores[j];
                    }
                }
                for(int j = rounds[i-1] ;j <=n ; j++){
                    stores[j]++;
                    if(stores[j] >maximum){
                        maximum = stores[j];
                    }
                }
            }
        }
        stores[rounds[rounds.size() -1]]++;
        if(stores[rounds[rounds.size() -1]] >maximum){
                        maximum = stores[rounds[rounds.size() -1]];
                    }
        for(int i = 1 ; i < stores.size(); i++){
            if(stores[i] == maximum){
                v.push_back(i);
            }
        }
        return v;
    }
};
