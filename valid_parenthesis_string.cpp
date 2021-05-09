class Solution {
public:
    bool checkValidString(string s) {
      stack<char>st;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
      while(!st.empty()){
          st.pop();
      }
         for(int i = s.size()-1 ; i >= 0; i--){
            if(s[i] == '('){
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return true;
    }
};
