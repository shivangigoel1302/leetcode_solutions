class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>v;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry=0;
        for(int i=0;i<min(num1.size(),num2.size());i++)
        {
            int n1=num1[i]-'0';
            int n2=num2[i]-'0';
            int sum=n1+n2+carry;
            v.push_back(sum%10);
            carry=sum/10;
        }
        if(num1.size()>num2.size())
        {
            int i=num2.size();
            while(i<num1.size())
            {
                int sum=carry+num1[i]-'0';
            v.push_back(sum%10);
                carry=sum/10;
                i++;
            }
        }
        else if(num1.size()<num2.size())
        {
            int i=num1.size();
            while(i<num2.size())
            {
                int sum=carry+num2[i]-'0';
            v.push_back(sum%10);
                carry=sum/10;
                i++;
            }
        }
        while(carry)
        {
            v.push_back(carry%10);
            carry=carry/10;
        }
        string str="";
        for(int i=v.size()-1;i>=0;i--)
        {
            str+=v[i]+'0';
        }
        return str;
    }
};
