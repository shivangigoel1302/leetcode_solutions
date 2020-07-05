class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<char> symbolStack;
        int i = 0;

        while (i < s.length()) {
            char ch = s[i];

            if (ch == ' ') {
                i++; continue;
            }

            if (isdigit(ch)) {
                // process numbers
                string sNum;
                while (isdigit(s[i]))
                    sNum += s[i++];

                int num = stoi(sNum);

                if (numStack.empty() or symbolStack.top() == '+' or symbolStack.top() == '-') {
                    numStack.push(num);
                }
                else {
                    if (symbolStack.top() == '*')
                        numStack.top() = numStack.top() * num;
                    else
                        numStack.top() = numStack.top() / num;

                    symbolStack.pop();
                }
            }
            else {
                // process operators
                if (!symbolStack.empty() and (ch == '+' or ch == '-'))
                    compute(numStack, symbolStack);

                symbolStack.push(ch);
                i++;
            }
        }

        if (symbolStack.empty())
            return numStack.top();

        compute(numStack, symbolStack);

        return numStack.top();
    }

    void compute(stack<int>& numStack, stack<char>& symbolStack) {
        int num2 = numStack.top(); numStack.pop();
        int num1 = numStack.top(); numStack.pop();
        int symbol = symbolStack.top(); symbolStack.pop();

        if (symbol == '*')
            numStack.push(num1 * num2);
        else if (symbol == '/')
            numStack.push(num1 / num2);
        else if (symbol == '+')
            numStack.push(num1 + num2);
        else
            numStack.push(num1 - num2);
    }
};
