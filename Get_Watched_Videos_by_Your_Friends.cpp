class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int>q;
        vector<bool>visited(friends.size(),false);
        q.push(id);
        visited[id] = true;
        while(!q.empty() && level--){
            int s = q.size();
            while(s--){
                int x = q.front();

                q.pop();
                for(auto j : friends[x]){
                    if(!visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        unordered_map<string,int>m;
        while(!q.empty()){
            int x = q.front();
            for(int i =0 ; i < watchedVideos[x].size(); i++){
                m[watchedVideos[x][i]]++;
            }
            q.pop();
        }
        map<int,set<string>>fin;
        for(auto it: m){
            fin[it.second].insert(it.first);
        }
        vector<string>ans;
        for(auto it: fin){
            // sort(it.second.begin(),it.second.end());
            // for(auto st: it.second){
            //     ans.push_back(st);
            // }
            auto st = it.second.begin();
            while(st != it.second.end()){
                ans.push_back(*st);
                st++;
            }
        }
        return ans;
    }
};
