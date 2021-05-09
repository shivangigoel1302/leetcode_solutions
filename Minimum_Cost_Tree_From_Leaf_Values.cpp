class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int>s;
        int ans =  0;
        for(int i = 0 ; i < arr.size(); i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else{
                while(!s.empty() && s.top() < arr[i]){
                    int x = s.top();
                    s.pop();
                    ans += x* min(s.empty() ? INT_MAX:s.top(),arr[i]);
                }
                s.push(arr[i]);
            }
        }
        int a = s.top();
        s.pop();
        while(!s.empty()){
            int x = s.top();
             s.pop();
            ans += x* min(s.empty() ? INT_MAX: s.top(), a);
            a = x;
        }
        return ans;
    }
};
