class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>m;
        int sum = 0;
        int count = 0;
      m[0] = 0;
        for(int i = 0 ; i < time.size(); i++){
            if(time[i]%60 == 0){
                count += m[0];
            }
            else if(m.find(60 - time[i]%60) != m.end()){
                count += m[60 - time[i]%60];
            }
            m[time[i]%60]++;
        }
        return count;
    }
};
