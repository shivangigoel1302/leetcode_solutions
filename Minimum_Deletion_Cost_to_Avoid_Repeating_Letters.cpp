class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        stack<int>st;
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(!st.empty() && s[st.top()] == s[i]){
                while(!st.empty() && cost[st.top()] <= cost[i] && s[st.top()] == s[i]){
                    ans += cost[st.top()];
                    st.pop();
                }
                if(!st.empty() && cost[st.top()] > cost[i] && s[st.top()] == s[i]){
                    ans += cost[i];
                    continue;
                }
            }
            st.push(i);
        }
        return ans;
    }
};
