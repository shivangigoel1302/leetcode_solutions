class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int>ans={1};
        while(ans.size() < N){
            vector<int>temp;
            for(auto i : ans){
                if(i*2-1 <=N){
                    temp.push_back(i*2-1);
                }
            }
            for(auto i : ans){
                if(i*2 <= N){
                    temp.push_back(i*2);
                }
            }
            ans = temp;
        }
        return ans;
    }
};
