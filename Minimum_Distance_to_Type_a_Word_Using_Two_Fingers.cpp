class Solution {
public:
    unordered_map<char,int>m;
     int dp[28][28][301];
    int getdist(char c,char b){
        if(c == 'a'){
            return 0;
        }
        int x1 = m[c]/6;
        int x2 = m[b]/6;
        int y1 = m[c]%6;
        int y2 = m[b]%6;
        return abs(x1-x2) + abs(y1-y2);
    }
    int helper(string word,char f1,char f2,int i){
        if(i == word.size()){
           return 0;
        }
              int a = f1 == 'a' ? 27 : f1 -'A';
        int b = f2 == 'a' ? 27 : f2-'A';
     if(dp[a][b][i] != -1){
         return dp[a][b][i];
     }
        int opt1 = getdist(f1,word[i]) + helper(word,word[i],f2,i+1);
        int opt2 = getdist(f2,word[i]) + helper(word,f1,word[i],i+1);

        return dp[a][b][i]= min(opt1,opt2);
    }
    int minimumDistance(string word) {

        char c ='A';
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6 && c <= 'Z'; j++){
                m[c++] = i*6 + j;
            }
        }
        memset(dp,-1,sizeof(dp));
       return helper(word,word[0],'a',1);
    }
};
