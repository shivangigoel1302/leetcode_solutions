class Solution {
public:
    string geta(string curr, int a){
        for(int i = 0; i < curr.size(); i++){
            if(i%2){
                int c = curr[i]-'0';
                c = (c+a)%10;
                char ch = c +'0';
                curr[i] = ch;
            }
        }
        return curr;
    }
    string getb(string curr, int b){
        reverse(curr.begin(),curr.end());
        reverse(curr.begin(),curr.begin() + b);
        reverse(curr.begin()+b,curr.end());
        return curr;
    }
    string findLexSmallestString(string s, int a, int b) {
        set<string>visited;
        queue<string>q;
        vector<string>v;
        q.push(s);
        visited.insert(s);
        b%=(s.size());
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            v.push_back(curr);
            string temp1 = geta(curr,a);
            if(visited.find(temp1) == visited.end()){
                q.push(temp1);
                visited.insert(temp1);

            }
            string temp2 = getb(curr,b);
            if(visited.find(temp2) == visited.end()){
                q.push(temp2);
                visited.insert(temp2);

            }
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};
