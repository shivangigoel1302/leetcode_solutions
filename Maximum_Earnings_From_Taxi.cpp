class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> memo(rides.size(), -1);
        sort(rides.begin(), rides.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
        });
        return earnings(rides, memo, 0);
    }

private:
    long long earnings(const vector<vector<int>> &rides, vector<long long> &memo, int i) {
        if (i >= rides.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int next_i = index_of_next_ride(rides, i);
        long long a = earnings(rides, memo, next_i) + (rides[i][1] - rides[i][0] + rides[i][2]); // Take this passenger
        long long b = earnings(rides, memo, i + 1); // -or- Skip to the next passenger
        memo[i] = max(a, b);
        return memo[i];
    }

    int index_of_next_ride(const vector<vector<int>> &rides, int i) {
        int L = i + 1;
        int R = rides.size() - 1;
        int n = rides.size();
        while (L <= R) {
            int mid = (L + R) / 2;
            if (rides[mid][0] >= rides[i][1]) {
                n = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return n;
    }
};
