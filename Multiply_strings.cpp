class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string s(n1+n2,'0');
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int sum=(num1[i]-'0')*(num2[j]-'0')+(s[i+j+1]-'0');
                s[i+j+1]=sum%10+'0';
                s[i+j]+=sum/10;
            }
        }
        for(int i=0;i<n1+n2;i++)
        {
            if(s[i]!='0')
            {
                return s.substr(i);
            }
        }
        return "0";
    }
};
