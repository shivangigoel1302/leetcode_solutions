class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string temp ="";
        string ans = "";
        if(path[path.size() -1] != '/'){
            path +="/";
        }
        for(int i = 1 ; i < path.size(); i++){
            if(path[i] == '/'){
                if(temp == "" || temp =="."){

                }
                else if(temp == ".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }
                else{
                    s.push(temp);
                }
                temp = "";
            }
            else{
                temp += path[i];
            }
        }
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        if(ans.size() == 0){
            ans += "/";
        }
        return ans;
    }
};
