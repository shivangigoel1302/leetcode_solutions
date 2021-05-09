class Solution {
public:
    map<string,int>m;
    vector<int>cnt;
    int dfs(string &s){
        int maximum = 6;
        if(m.find(s)  != m.end()){
            return m[s];
        }
        string next = removeall(s);
        if(m.find(next)  != m.end()){
            return m[s] = m[next];
        }
        for(int i = 0; i < next.size()-1; i++){
            for(int j = 0 ; j < 26; j++){
                if(cnt[j] > 0){
                    cnt[j]--;
                    char ch = j + 'A';
                    string curr = ch + s.substr(i);
                    if(i){
                        curr = s.substr(0,i) + curr;
                    }
                    maximum = min(maximum,1 + dfs(curr));
                    cnt[j]++;
                }
            }
        }
        return m[s] = maximum;
    }
    string removeall(string &s){
       for(int i =1,j=0; i < s.size(); i++){
           if(s[i] == s[i-1]){
               continue;
           }
           if(i - j >= 3){
               string next = s.substr(0,j) + s.substr(i);
               return removeall(next);
           }
           j = i;
       }
       return s;
    }
    int findMinStep(string board, string hand) {
       cnt.resize(26,0);
        for(auto c: hand){
            cnt[c-'A']++;
        }
        board += '#';
        m["#"] = 0;
        int ans = dfs(board);
        return ans == 6 ?-1 : ans;
    }
};
