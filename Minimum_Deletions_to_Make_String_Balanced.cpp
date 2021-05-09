
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n = s.size()-1;
        int move = 0;
        for(int i = n ; i >=0 ; i--){
            if(!st.empty() && st.top() < s[i]){
                st.pop();
                move++;
            }
            else{
                st.push(s[i]);
            }
        }
        return move;
    }
};
