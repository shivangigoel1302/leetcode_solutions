class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<bool>odd(n,false);
        vector<bool>even(n,false);

        odd[n-1]=even[n-1] = true;
        map<int,int>m;
        m[A[n-1]] = n-1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--){
            auto it = m.lower_bound(A[i]);
            //cout<<A[i]<<" ";
            if(it != m.end()){
                //cout<<it->first<<" ";
                odd[i] = even[it->second];
                if(odd[i]){
                    ans++;
                }
                if(it->first == A[i]){
                    it++;
                }
            }
            it = m.upper_bound(A[i]);
            if(it != m.begin()){

                --it;
                //cout<<it->first<<" ";
                even[i] = odd[(it)->second];

            }
            //cout<<endl;
            m[A[i]] = i;
        }
        return ans;
    }
};
