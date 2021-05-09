class Solution {
public:
    int minOperations(int n) {
        int i = 1;
        int required = n;
        int operations = 0;
        while(i < n){
            operations+= required-i;
            i += 2;
        }
        return operations;
    }
};
