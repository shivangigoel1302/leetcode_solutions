void keypad(string digits,string& out,string phone[],vector<string>&ans,int i,int j)
{
    if(i==digits.size()&& !digits.empty())
    {
        ans.push_back(out);
        return;
    }
    int index=digits[i]-'0';
    for(int k=0;phone[index][k]!='\0';k++)
    {
        out[j]=phone[index][k];
        keypad(digits,out,phone,ans,i+1,j+1);
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string>ans;
        string phone[11]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string out(digits.size(),'*');
        keypad(digits,out,phone,ans,0,0);
        return ans;
    }
};
