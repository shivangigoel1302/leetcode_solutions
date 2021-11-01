class Solution {
public:
    bool issubstring(string n,string&p, vector<int>&removable,int mid){

        for(int k = 0; k < mid; k++){
            n[removable[k]] = '#';
        }
        int i = 0,j=0;
        while(i < n.size() && j < p.size()){
            if(n[i] == p[j]){
                j++;
            }
            i++;
        }
        if(j == p.size()){
            return true;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0,r= removable.size();
        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(issubstring(s,p,removable,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
