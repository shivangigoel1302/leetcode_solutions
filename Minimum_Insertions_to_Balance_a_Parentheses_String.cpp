class Solution {
public:
    int minInsertions(string s) {
        int ans = 0 ;
        stack<int>p;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '('){
                p.push(s[i]);
            }
            else{
                if(s[i+1] == ')'){
                    if(p.empty()){
                        ans++;
                    }
                    else{
                        p.pop();

                    }
                    i++;
                }
                else{
                    ans++;
                    if(p.empty()){
                        ans++;
                    }
                    else{
                        p.pop();
                    }
                }
            }
        }
        while(!p.empty()){
            ans+=2;
            p.pop();
        }
        return ans;
    }
};
