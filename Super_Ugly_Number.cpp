class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<long long int>s;
        s.insert(1);
        n--;
        while(n--){
            auto it = s.begin();
            for(auto x : primes){
                s.insert(*it * x);
            }
           s.erase(it);
        }
        return *s.begin();
    }
};
