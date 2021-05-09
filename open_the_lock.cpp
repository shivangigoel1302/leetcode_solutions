class Solution {
public:
    vector<string>getstatus(string s){
        vector<string>ans;
        for(int i = 0 ;i < s.size(); i++){
            string temp=s;
            if(temp[i] == '9') temp[i]= '0';
            else{
                temp[i]++;
            }
            ans.push_back(temp);
            temp = s;
            if(temp[i] == '0') temp[i] = '9';
            else{
                temp[i]--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string>s;
        for(int i = 0 ; i< deadends.size(); i++){
            s.insert(deadends[i]);
        }
        if(s.find("0000")!= s.end()){
            return -1;
        }
        if(target == "0000"){
            return 0;
        }
        map<string,int>m;
        queue<string>q;
        q.push("0000");
        m["0000"] = 0;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(string temp : getstatus(curr)){
                if(s.find(temp) != s.end() || m.find(temp) != m.end()){
                    continue;
                }
                q.push(temp);
                m[temp] = m[curr] +1;
                if(temp == target){
                    return m[temp];
                }
            }
        }
        return -1;
    }
};
