class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n,0);
        int dead = 0;
        int i = 0;
        while(dead < n-1){
            int count = 0;

            while(count < k){
                if(v[i] == 0){
                    count++;
                }
                i = (i + 1)%n;
            }
          // cout<<j<<" ";
            v[(i-1 + n)%n] = 1;
            dead++;
            while(v[i] == 1){
                //cout<<i<<" ";
                i = (i+1)%n;
            }
            //cout<<endl;
        }
        for(int i = 0 ; i < n; i++){
            if(v[i] == 0){
                return i+1;
            }
        }
        return 0;
    }
};
