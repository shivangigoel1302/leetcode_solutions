class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int>m;
        int bulls=0,cows=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                m[secret[i]]++;
            }
        }
        for(int i=0;i<guess.size();i++)
        {
            if(m[guess[i]]>=1&&guess[i]!=secret[i])
            {
                cows++;
                m[guess[i]]--;
            }
        }
        string s=to_string(bulls)+"A"+to_string(cows)+"B";
        return s;
    }
};
