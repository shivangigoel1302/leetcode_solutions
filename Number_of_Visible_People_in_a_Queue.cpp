class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        vector<int>ans(heights.size(),0);
        s.push(heights[heights.size()-1]);
        for(int i = heights.size()-2; i >=0; i--){
            int cnt = 1;
            while(!s.empty() && s.top() < heights[i]){
                s.pop();
                cnt++;
            }
            if(s.empty()){
                cnt--;
            }
            ans[i] = cnt;
            s.push(heights[i]);
        }
        return ans;
    }
};
