class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
        {
            return "0";
        }
        long long int n=numerator;
        long long int d=denominator;
        bool isneg=false;
         if(n<0 && d<0){
            n=abs(n);
            d=abs(d);
        }
        else if(n<0) {
            isneg = true;
            n = abs(n);
        }
        else if(d<0) {
            isneg = true;
            d = abs(d);
        }
        long long int q=n/d;
        long long rem=n%d;
        string ans=to_string(q);
        if(rem==0)
        {
            if(isneg)
            {
                return "-"+ans;
            }
            return ans;
        }
        map<int,int>m;
        string str="";
        int count=1;
        while(rem!=0)
        {
            rem=rem*10;
            str+=to_string(rem/d);
            rem=rem%d;
            if(m.find(rem)!=m.end())
            {
                str=str.substr(0,m[rem])+"("+str.substr(m[rem])+")";
                break;
            }
            m[rem]=count;
            count++;
        }
         if(isneg)  return "-"+ans+"."+str;
        return ans+"."+str;
    }
};
