
class Solution {
public:
    void helper(int n,int &k,string &ans, vector<int>&fact,vector<int>&v){
        if(n == 1){
            ans += to_string(v[0]);
            return;
        }
        int index = (k/fact[n-1]);
        if(k%fact[n-1] == 0){
            index--;
        }
        ans += to_string(v[index]);
        v.erase(v.begin() + index);
        k -= fact[n-1]*index;
        helper(n-1,k,ans,fact,v);
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>fact{1,1,2,6,24,120,720,5040,40320,362880};
        vector<int>v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
        }
        helper(n,k,ans,fact,v);
        return ans;
    }
};
