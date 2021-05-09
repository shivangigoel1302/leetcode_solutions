bool compareLen(const std::string& a, const std::string& b)
{
return (a.size() < b.size());
}
class Solution {
public:

int solve(int k,int j,vector<string> &words,vector<vector<int>> &dp)
{
    if(k <0 ) return 0;

    if(dp[k][j] !=-1) return dp[k][j];



    string x = "";

    for(int i = 0;i<words[k].size();i++)
    {
        if(i != j) x += words[k][i];
    }
    if(x.size() == 0) return 0;



    bool flag = false;
    int index = -1;

    for(int i = k-1;i>=0;i--)
    {
        if(x == words[i])
        {
            flag = true;
            index = i;
        }
    }


    int ans = 0;

    if(flag)
    {
        for(int i = 0;i<words[index].size();i++)
        {
             ans = max(ans,solve(index,i,words,dp));
        }
        dp[k][j] = ans+1;

    }
    else
    {
        dp[k][j] = 0;
    }
    return dp[k][j];

}


int longestStrChain(vector<string>& words) {

    sort(words.begin(), words.end(), compareLen);
    int j = words.size()-1;
    int ans = 0;
    vector<vector<int>> dp(words.size()+1,vector<int>(17,-1));
    int final_ans = 0;
    for(int k = words.size()-1;k>=0;k--)
    {
        for(int i = 0 ;i<words[k].size();i++)
        {
            ans = max(ans,solve(k,i,words,dp));
        }
        final_ans = max(final_ans,ans);
    }
    return final_ans+1;
}
};
