class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
       int m=s1.size(),n=s2.size();//finding size of given strings
        int t[m+1][n+1];//define a matrix/table of size (m+1)x(n+1)
        for(int i=0;i<m+1;i++)
        {
            t[i][0]=0;//Initialize first column
        }
        for(int j=1;j<n+1;j++)
        {
            t[0][j]=0; //Initialize first row
        }

        //now fill the table
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        //Now we want string, start from (m+1)th row and (n+1)th column in table t and traverse back by checking following condtions.
        string str="";
        int i=m,j=n;
        while(i>0&&j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                str.push_back(s1[i-1]);//both are equal, so we can insert any one.
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                {
                    str.push_back(s1[i-1]);//insert the one, where we are moving
                    i--;
                }
                else
                {
                    str.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i>0)//when string s1 remain
        {
            str.push_back(s1[i-1]);
            i--;
        }
        while(j>0)//when string s2 remain
        {
            str.push_back(s2[j-1]);
            j--;
        }
        reverse(str.begin(),str.end());//since we have traversed from bottom, we need t reerse the string.

        return str;
    }
};
