class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i = 0 ; i < s.size(); i++){
            if(!st.empty() && st.top().first == s[i]){
                st.push({s[i],st.top().second+1});
            }
            else{
                st.push({s[i],1});
            }
            if(!st.empty() && st.top().second >=k){
                int duplicates = k;
                while(!st.empty() && duplicates--){
                    st.pop();

                }
            }
        }
        string str = "";
        while(!st.empty()){
            str = st.top().first + str;
            st.pop();
        }
        return str;
    }
};
