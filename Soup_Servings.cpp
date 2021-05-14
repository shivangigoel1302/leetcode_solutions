class Solution {
public:
    vector<vector<double>>dp;
    double soup(int a,int b){
        if(a == 0&& b == 0){
            return 0.5;
         }
        if(a == 0 && b != 0){
            return 1;
        }
        if(a != 0 && b == 0){
            return 0;
        }
        if(dp[a][b] != -1){
            return dp[a][b];
        }
        double op1 = soup(a-min(100,a),b);
        double op2 = soup(a-min(75,a),b-min(25,b));
        double op3 = soup(a-min(a,50),b-min(50,b));
        double op4 = soup(a-min(25,a),b-min(b,75));
        return dp[a][b] = (op1+op2+op3+op4)/4;
    }
    double soupServings(int N) {
        if(N > 5000){
            return 1;
        }
        dp.resize(N+1,vector<double>(N+1,-1));
        return soup(N,N);
    }
};
