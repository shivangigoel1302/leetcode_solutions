class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int,vector<int>>lang;
        for(int i = 0 ; i < languages.size(); i++){
            for(auto l : languages[i]){
                lang[l].push_back(i+1);
            }
        }
        unordered_set<int>s;
        for(int i = 0 ; i< friendships.size(); i++){
            int x = friendships[i][0];
            int y = friendships[i][1];
            int flag = 0;
            for(auto l: languages[x-1]){
                for(auto f : lang[l]){
                    if(f == y){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    break;
                }
            }
            if(flag == 0){
                s.insert(x);
                s.insert(y);
            }
        }
        vector<int>freq(n+1,0);
        auto it = s.begin();
        while(it != s.end()){

            for(auto l : languages[*it-1]){
                freq[l]++;
            }
            it ++;
        }
        int maxfreq = INT_MIN;
        for(int i = 0; i < n+1; i++){
            maxfreq = max(maxfreq, freq[i]);
        }
        int ans = s.size() - maxfreq;
        return ans;
    }
};
