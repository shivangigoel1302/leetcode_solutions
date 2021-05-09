class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<pair<int,int>>q;
        for(int i =1 ; i <=9 ; i++){
            q.push({i,i});
        }
        vector<int>ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                if(n == 1){
                    ans.push_back(f.first);
                    continue;
                }
                for(int i = 0; i <= 9; i++){
                    if(abs(f.second - i) == k){
                        q.push({f.first*10 + i,i});
                    }
                }
            }
            n--;
        }
        return ans;
    }
};
