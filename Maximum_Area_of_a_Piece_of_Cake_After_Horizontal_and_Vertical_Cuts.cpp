class Solution {
public:
    int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        int maxh = max(horizontalCuts[0],h-horizontalCuts[m-1]);
        int maxw = max(verticalCuts[0],w-verticalCuts[n-1]);
        for(int i = 1 ; i < m ; i++){
            maxh = max(maxh,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i = 1; i < n; i++){
            maxw = max(maxw,verticalCuts[i] - verticalCuts[i-1]);
        }
        maxh = maxh%mod;
        maxw = maxw%mod;
        return (long)maxh*maxw%mod;
    }
};
