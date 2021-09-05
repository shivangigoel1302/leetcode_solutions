class Solution {
public:
    int sum(int n){
        return (n*(n+1))/2;
    }
    int candy(vector<int>& ratings) {
        // int n = ratings.size();
        // vector<int>v(n,1);
        // for(int i = 1; i < n; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         v[i] += v[i-1];
        //     }
        // }
        // for(int i = n-2; i >=0; i--){
        //     if(ratings[i] > ratings[i+1] && v[i] <= v[i+1]){
        //         v[i] = v[i+1]+1;
        //     }
        // }
        // int sum = 0;
        // for(int i = 0; i < n; i++){
        //     sum += v[i];
        // }
        // return sum;

        int candy = 0,up = 0, down = 0;
        int prevslope = 0;
        int n = ratings.size();
        for(int i = 1; i < n; i++){
            int currslope = ratings[i] > ratings[i-1] ? 1: ratings[i] < ratings[i-1] ? -1: 0;
            if((prevslope < 0 && currslope >= 0) || (prevslope > 0 && currslope == 0)){
                candy += sum(up) + sum(down) + max(up,down);
                up = 0;
                down = 0;
            }
            if(currslope > 0){
                up++;
            }
            else if(currslope < 0){
                down++;
            }
            else{
                candy++;
            }
            prevslope = currslope;
        }
        candy += sum(up) + sum(down) + max(up,down) + 1;
        return candy;
    }
};
