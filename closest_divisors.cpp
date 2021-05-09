class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n = sqrt(num) + 1;
        while(n ){
            if((num + 2) % n <= 1){
                return {n,(num+2)/n};
            }
            n--;
        }
        return {};
    }
};
