class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       vector<int>v;
        if(digits.size()==1&&digits[0]!=9)
       {
           v.push_back(digits[0]+1);
            return v;
       }
    if(digits.size()==1&&digits[0]==9)
    {
        v.insert(v.begin(),0);
        v.insert(v.begin(),1);
        return v;
    }
        int i=digits.size()-2;
        int n=digits.size();
        int a=(digits[n-1]+1)%10;
        v.insert(v.begin(),a);
        int carry=(digits[n-1]+1)/10;
        while(carry&&i>=0)
        {
            a=(digits[i]+carry)%10;
            carry=(digits[i]+carry)/10;
             v.insert(v.begin(),a);
            i--;
        }
        if(carry!=0)
        {
            v.insert(v.begin(),carry);
        }
        while(i>=0)
        {
             v.insert(v.begin(),digits[i]);
            i--;
        }
        return v;
    }
};
