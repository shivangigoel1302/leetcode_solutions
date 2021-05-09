class Solution {
public:
    int fib(int N) {
        if(N==0 || N ==1){
            return N;
        }
        int temp = fib(N-1) + fib(N-2);
        return temp;
    }
};
