class Solution {
public:
    int lengthOfLastWord(string s) {
int count=0;
        if(s.size()==0)
        {
            return 0;
        }
        while(!s.empty()&&s.back()==' ')
        {
            s.pop_back();
        }
        int i=s.size()-1;
        while(i>=0)
        {
            if(s[i]!=' ')
            {
                 count++;
            }
            if(s[i]==' ')
            {
                return count;
                break;
            }
            i--;
        }
        return count;
    }
};
