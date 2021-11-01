class Solution {
public:
     long long findWastedSpace(vector<int>&packages, vector<int>&boxes, long long &neededSpace){
        long long i, j = -1, k;
        long long totalSpace = 0;
        const long long mod = 1e9 + 7;
        for(i = 0; i < boxes.size(); i++){
            vector<int>::iterator it = upper_bound(packages.begin(), packages.end(), boxes[i]);
            if(it == packages.begin()){
                continue;
            }
            --it;
            k = it - packages.begin();
            totalSpace += (long long)boxes[i] * (long long)(k - j);
            j = k;
            if(j == packages.size() - 1){
                break;
            }
        }
        long long sz = packages.size() - 1;
        const long long maxVal = 1e18;
        long long waste = totalSpace - neededSpace;
        return j < sz ? maxVal : waste;
    }

    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        long long i, j;
        const long long mod = 1e9 + 7;
        const long long maxVal = 1e18;
        sort(packages.begin(), packages.end());
        for(i = 0; i < boxes.size(); i++){
            sort(boxes[i].begin(), boxes[i].end());
        }
        long long minWasted = 1e18;
        long long neededSpace = 0;
        for(i = 0; i < packages.size(); i++){
            neededSpace += packages[i];
        }
        for(i = 0; i < boxes.size(); i++){
            minWasted = min(minWasted, findWastedSpace(packages, boxes[i], neededSpace));
        }
        return minWasted == maxVal ? -1 : minWasted % mod;
    }
};
