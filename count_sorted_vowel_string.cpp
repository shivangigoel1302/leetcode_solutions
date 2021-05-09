class Solution {
public:
    int countVowelStrings(int n) {
        int a[6]={0};
        a[5] = 1;
        while(n>0){
            for(int i = 5;i>0 ; i--){
                a[i-1] = a[i-1] + a[i];
            }
            n--;
        }
        int sum = 0;
        for(int i = 1 ; i < 6 ; i++){
            sum+=a[i];
        }
        return sum;
    }
};
