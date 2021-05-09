class Solution {
public:
    bool check(string s1, string s2, vector<int>count1,vector<int>count2){
        sort(s1.begin(),s1.end());
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(count2[s1[i]-'a'] - cnt > 0){
                cnt++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        vector<int>count1(26,0);
        for(int i = 0 ; i < s1.size(); i++){
            count1[s1[i] - 'a']++;
        }
        for(int i = 1 ;i < 26; i++){
            count1[i] = count1[i-1] + count1[i];
        }
          vector<int>count2(26,0);
        for(int i = 0 ; i < s2.size(); i++){
            count2[s2[i] - 'a']++;
        }
        for(int i = 1 ;i < 26; i++){
            count2[i] = count2[i-1] + count2[i];
        }
        if(check(s1,s2,count1,count2)){
            return true;
        }
        if(check(s2,s1,count2,count1)){
            return true;
        }
        return false;
    }
};
