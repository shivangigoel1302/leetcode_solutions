class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& word) {
        deque<vector<string>>paths;
        unordered_set<string>visited;
        int level = 1;
        vector<vector<string>>ans;
        paths.push_back({beginWord});
        unordered_set<string>wordList(word.begin(),word.end());
        int minLevel = INT_MAX;
        while(!paths.empty()){
            vector<string>curr = paths.front();
            paths.pop_front();
            if(curr.size() > level){
                for(auto w: visited){
                    //auto it = wordList.find(w);
                    wordList.erase(w);
                }
                visited.clear();
                if(curr.size() > minLevel){
                    break;
                }
                else{
                    level = curr.size();
                }
            }
            string temp = curr.back();
            for(int i = 0 ; i < temp.size(); i++){
                for(int j = 0 ; j < 26; j++){
                    char c = temp[i];
                    temp[i] = j +'a';
                    if( wordList.find(temp) != wordList.end()){
                        visited.insert(temp);
                        vector<string>newpath = curr;
                        newpath.push_back(temp);
                        if(temp == endWord){
                            ans.push_back(newpath);
                            minLevel = level;
                        }
                        else{
                            paths.push_back(newpath);
                        }
                    }
                    temp[i] = c;
                }
            }
        }
        return ans;
    }
};
