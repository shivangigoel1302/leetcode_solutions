class Solution {
public:

    vector<int> powerfulIntegers(int x, int y, int bound) {
         int a = x== 1? bound : log(bound)/log(x);
         int b = y == 1? bound : log(bound)/log(y);
        set<int>s;
        vector<int>ans;
        for(int i = 0 ; i<= a; i++){
            for(int j = 0 ; j <= b ; j++){
                long long sum = pow(x,i) + pow(y,j);
                if(sum <= bound){
                    s.insert(sum);
                }
                if(y == 1){
                    break;
                }
            }
            if(x == 1){
                break;
            }
        }
       auto it = s.begin();
        while(it != s.end()){
            long long z = *it;
            ans.push_back(z);
            it++;
        }
        return ans;
    }
};
