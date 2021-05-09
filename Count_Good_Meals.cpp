class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < deliciousness.size(); i++){
            m[deliciousness[i]]++;
        }
        long long int ans = 0;
        unordered_set<int>st;
        for(auto a: m){
            for(int i = 0 ; i <22; i++){
                int b = pow(2,i)- a.first;
                if(st.count(b) != 0){
                    ans += a.second * m[b];
                }
                else if(b==a.first){
                    ans += (long long int)a.second*(a.second -1)/2;
                }
            }
            st.insert(a.first);
        }
        return ans%1000000007;
    }
};
