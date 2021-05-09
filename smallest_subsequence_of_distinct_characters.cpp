class Solution {
public:
    string smallestSubsequence(string s) {
         int a[27]={0};
       for(int i = 0 ; i < s.size(); i++){
           a[s[i] - 'a'] = i;
       }
       stack<pair<char,int>>st;
        vector<bool>visited(27);
        for(int i = 0 ; i < 26 ; i ++){
            visited[i] = false;
        }
        st.push({s[0],0});
        visited[s[0]-'a'] = true;
        for(int i = 1 ; i < s.size(); i++){

            while(!st.empty() && st.top().first-'a'  >=s[i]-'a'  &&!visited[s[i]-'a']&&  a[st.top().first -'a'] > i){

                visited[st.top().first-'a'] = false;
                st.pop();
            }

            if(visited[s[i]-'a']==false){

                st.push({s[i],i});
                visited[s[i]-'a'] = true;
            }
        }
        string ans="";
        while(!st.empty()){
            ans= st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};

