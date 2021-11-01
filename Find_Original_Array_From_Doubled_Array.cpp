class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int>v;
        if(n%2 == 1){
            return v;
        }
        int l = 0;
        int r = n/2;
        sort(changed.begin(),changed.end());
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(!q.empty() && q.front()*2 == changed[i]){
                q.pop();
            }
            else{
                v.push_back(changed[i]);
                q.push(changed[i]);
            }
        }
        if(v.size() > n/2){
            v.clear();
            return v;
        }
        return v;
    }
};
