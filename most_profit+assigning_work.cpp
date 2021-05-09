class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, curMax = 0, m = (int)worker.size(), n = (int)difficulty.size();
    // sort difficuty-profit and worker
    sort(worker.begin(), worker.end());
    vector<pair<int, int>> diffProf(n);
    for (int i = 0; i < n; i++){
        diffProf[i].first = difficulty[i];
        diffProf[i].second = profit[i];
    }
    sort(diffProf.begin(), diffProf.end());
    // two-pointer traversing, i for worker, j for diffProf
    int i = 0, j = 0;
    while (i < m) {
        while (j < n && worker[i] >= diffProf[j].first)
        {
            curMax = max(curMax, diffProf[j].second);
            j++;
        }
        res += curMax;
        i++;
    }
    return res;
    }
};
