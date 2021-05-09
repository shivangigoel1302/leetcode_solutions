class Solution {
public:
    void helper(string s, int start, vector<string>&currentlist, vector<vector<string>>&result){
        if(start >= s.size()){
            result.push_back(currentlist);
        }
        for(int end = start ; end < s.size(); end++){
            if(isPalindrome(s,start,end)){
                currentlist.push_back(s.substr(start,end-start +1));
                helper(s,end+1, currentlist, result);
                currentlist.pop_back();
            }
        }
    }
    bool isPalindrome(string s , int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>currentlist;
        vector<vector<string>>result;
        helper(s,0,currentlist,result);
        return result;
    }
};
