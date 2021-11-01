class Solution {
public:
    vector<int>rot ={0,1,8,2,5,6,9};
    int rotatedDigits(int n) {
        int ans = 0;
        helper(ans,0,n,false);
        return ans;
    }
    void helper(int &ans,int curr,int n,bool good){
        if(curr > n){
            return;
        }
        if(curr <= n && good){
            ans++;
        }
        for(int i = 0; i < rot.size(); i++){
            good = good || (rot[i] == 2 || rot[i] == 5 || rot[i] == 6 || rot[i] == 9);
            int newnumber = curr*10 + rot[i];
            if(newnumber == curr){
                continue;
            }
            helper(ans,newnumber,n,good);
        }
    }
};
