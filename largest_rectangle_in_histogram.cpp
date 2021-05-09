class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        vector<int>left(heights.size());
        vector<int>right(heights.size());
        stack<int>s;
        s.push(0);
        int n = heights.size();
        left[0]=0;
        for(int i = 1; i < heights.size(); i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                left[i] = heights[i] * i;
            }
            else{
                left[i] = heights[i] * (i-1-s.top());
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(n-1);
        right[n-1] = 0;
        for(int i = n-2 ; i >=0 ; i--){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                right[i] = heights[i] * (n-i-1);
            }
            else{
                right[i] = heights[i] * (s.top() - i - 1);
            }
            s.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, left[i] +right[i] + heights[i]);
        }
        return ans;
    }
};
