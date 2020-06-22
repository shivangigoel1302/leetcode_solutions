class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        switch(ch)
        {
        case '{':
        case'(':
        case'[': st.push(ch);
        break;
        case '}':
            if(!st.empty()&&st.top()=='{')
                {
                    st.pop();
                }
                else{
                    return false;
                }
                break;
        case ')':
            if(!st.empty()&&st.top()=='(')
                {
                    st.pop();
                }
                else{
                    return false;
                }
                break;
        case ']':
            if(!st.empty()&&st.top()=='[')
                {
                    st.pop();
                }
                else{
                    return false;
                }

        }

    }
    if(st.empty()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};
