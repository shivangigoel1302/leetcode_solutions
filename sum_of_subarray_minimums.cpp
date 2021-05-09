class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        int mod = 1000000007;
        vector<int>prev(arr.size());
        for(int i = 0 ; i < arr.size(); i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            prev[i] = s.empty()?-1:s.top();

            s.push(i);
        }
        stack<int>st;
        int n = arr.size();
        vector<int>next(arr.size());
         for(int i = arr.size()-1 ; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            next[i] = st.empty()?n:st.top();

            st.push(i);
        }
        long long ans = 0;
        for(int i = 0 ; i < arr.size(); i++){
            ans += (long long)(i - prev[i])*(next[i] - i)%mod * arr[i]%mod;
            //cout<<(i - prev[i])*(next[i] - i)%mod*arr[i]%mod<<" ";
            ans %= mod;
        }
        return (int)ans;
    }
};
