class Solution {
public:
    char getchar(int count){
        if(count == 0){
            return '*';
        }
        else if(count == 1){
            return '/';
        }
        else if(count == 2){
            return '+';
        }
        else{
            return '-';
        }
    }
    int eval(int a, int b , char ch){
        if(ch == '/'){
            return b/a;
        }
        else if(ch == '*'){
            return a*b;
        }
        else if(ch == '+'){
            return a+b;
        }
        else{
            return b-a;
        }
    }
    int prec(char ch){
        if(ch == '/' || ch == '*'){
            return 2;
        }
        else if(ch == '+' || ch == '-'){
            return 1;
        }
        return -1;
    }
    int clumsy(int N) {
        stack<int>num;
        stack<char>sign;
        int count = 0;
        while(N){
            num.push(N);
            count = count%4;
            while(!sign.empty() && prec(getchar(count)) <= prec(sign.top())){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.top() = eval(a,b,sign.top());

                sign.pop();
            }
            sign.push(getchar(count));
            count++;
            N--;
        }
        sign.pop();
        while(!sign.empty()){
            int a = num.top();
            num.pop();
            int b = num.top();

            num.top() = eval(a,b,sign.top());

            sign.pop();
        }
        return num.top();
    }
};
