class Solution {
public:
    int helper(string&s, char a, char b){
        stack<char>st;
        int count=0;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && s[i] == b && st.top() == a){
                count++;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return count;
    }
    int maximumGain(string s, int x, int y) {
        if(x > y){
            int ca = helper(s,'a','b');
            int cb = helper(s,'b','a');
            return ca*x+cb*y;
        }
        else{
            int ca = helper(s,'b','a');
            int cb = helper(s,'a','b');
            return ca*y+cb*x;
        }
        return 0;
    }
};
