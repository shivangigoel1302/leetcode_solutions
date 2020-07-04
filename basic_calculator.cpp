class Solution {
public:
    int calculate(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int currval=0;
        int currnum=0;
        int op=1;
        stack<pair<int,int>>st;
        for(auto c:s)
        {
            if(c>='0'&&c<='9')
            {
                currnum=currnum*10;
                currnum+=c-'0';
            }
            else
            {
                if(currnum!=0)
                {
                    if(op==0)
                    {
                        currval=currnum;
                    }
                    else
                    {
                        currval+=currnum*op;
                    }
                    currnum=0;
                }
                if(c=='+')
                {
                    op=1;
                }
                if(c=='-')
                {
                    op=-1;
                }
                else if(c=='(')
                {
                    st.push(make_pair(currval,op));
                    currval=0;
                    op=0;
                }
                else if(c==')')
                {
                    pair<int,int>p=st.top();
                    st.pop();
                    int temp=p.first+p.second*currval;
                    currval=temp;
                }
            }
        }
        if(currnum)
        {
            if(op==0)
            {
                currval=currnum;
            }
            else
            {
                currval+=currnum*op;
            }
        }
        return currval;
    }
};
