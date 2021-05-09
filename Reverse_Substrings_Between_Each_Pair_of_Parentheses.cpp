class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        int p[n];
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                p[st.top()] = i;
                p[i] = st.top();
                st.pop();
            }
        }
        int direction = 1;
        string ans = "";
        for(int i = 0 ; i < n ; i+=direction){
            if(s[i] == '(' || s[i] == ')'){
                i = p[i];
                direction *= -1;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};
