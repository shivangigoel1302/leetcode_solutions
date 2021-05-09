class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>temp(numRows);
        int i = 0 ;
        int n = s.size();
        while(i < n){
            for(int j = 0 ; j < numRows && i < n; j++,i++){
                temp[j] +=s[i];
            }
            for(int j = numRows-2; j>0 && i < n; j--,i++){
                temp[j] += s[i];
            }
        }
        string ans = "";
        for(int i = 0 ; i < numRows; i++){
            ans+=temp[i];
        }
        return ans;
    }
};
