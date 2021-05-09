class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int>ans(A.size(),-1);
        sort(A.begin(), A.end());
        for(int i = 0 ; i < B.size(); i++){
            auto l = upper_bound(A.begin(),A.end(),B[i]);
            if(l == A.end()){
                l = A.begin();
            }
            ans[i] = *l;
            A.erase(l);
        }
        return ans;
    }
};
