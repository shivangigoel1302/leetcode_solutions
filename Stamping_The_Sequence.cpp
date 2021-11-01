class Solution {
public:
    void movestamps(string &stamp, string &target, vector<int>&v){
        int n = stamp.size();
        int m = target.size();
        int j=0;
        int flag = 0;
        for(int i = 0; i < m; i++){
            if(target[i] == '?' || target[i] == stamp[j]){
                j++;
                if(target[i] != '?'){
                    flag = 1;
                }
            }
            else{
                if(target[i-j] != '?'){
                    i -= j-1;
                    j = flag = stamp[0] == target[i];
                }
                else{
                    i -= j;
                    j = flag = stamp[0] == target[i];
                }
            }
            if(j == stamp.size() && flag){
                while(j--){
                    target[i-j] = '?';
                }
                v.push_back(i-stamp.size() + 1);
                movestamps(stamp,target,v);
                return;
            }
            else if(j == stamp.size()){
                i -= j-1;
                j = 0;
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>v;
        movestamps(stamp,target,v);
        for(int i = 0; i < target.size(); i++){
            if(target[i] != '?'){
                vector<int>temp;
                return temp;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
