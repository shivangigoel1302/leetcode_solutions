class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,bool>words;
        for(auto word: bank){
            words[word] = true;
        }
        if(words.find(end) == words.end()){
            return -1;
        }
        if(start.size() == 0 || end.size()== 0 || bank.size() == 0){
            return -1;
        }
        queue<string>q;
        q.push(start);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string current = q.front();
                q.pop();
                for(int i = 0 ; i < current.size(); i++){
                    char temp = current[i];
                    for(auto c: "ACGT"){
                        if(c == temp) continue;
                        current[i] = c;
                        if(current == end) return count+1;
                        if(words.find(current) != words.end()){
                            words.erase(current);
                            q.push(current);
                        }
                    }
                    current[i] = temp;
                }
            }
            count++;
        }
        return -1;
    }
};
