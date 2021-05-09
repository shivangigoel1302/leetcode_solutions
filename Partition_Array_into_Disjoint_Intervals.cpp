class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        stack<int>s;
        for(int i = A.size()-1; i >=0 ; i--){
            if(s.empty()){
                s.push(A[i]);
            }
            else{
                if(s.top() <= A[i]){
                    s.push(s.top());
                }
                else{
                    s.push(A[i]);
                }
            }
        }
        int j = 1;
        int maxleft = A[0];
        int ans = 1;
        while(s.size() > 1){
            s.pop();
            if(maxleft <= s.top()){
                return ans;
            }
            maxleft = max(maxleft,A[j]);
            j++;
            ans++;
        }
        return ans;
    }
};
