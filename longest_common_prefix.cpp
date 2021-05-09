class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0){
            return "";
        }
        string ans = strs[0];
        for(int i = 0 ; i < n ; i++){
            int size = ans.size();
            for(int j = 0 ; j < ans.size(); j++){
                if(strs[i][j] != ans[j]){
                    ans = ans.substr(0,j);
                }
            }
        }
        return ans;
    }
};
