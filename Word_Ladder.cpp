class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int level = 1;
        unordered_map<string,bool>m;
        for(auto w: wordList){
            m[w] = true;
        }
        set<string>visited;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string temp = q.front();
                q.pop();
                for(int i = 0 ; i < temp.size(); i++){
                    for(int j = 0; j < 26; j++){
                        char c = temp[i];
                        temp[i] = j + 'a';
                        if(visited.find(temp) == visited.end() && m[temp]){
                            if(temp == endWord){
                                return level+1;
                            }
                            m[temp] = false;
                            visited.insert(temp);
                            q.push(temp);
                        }
                        temp[i] = c;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
