class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>m;
        for(int i = 0 ; i < answers.size(); i++){
           m[answers[i]]++;
        }
        int rabbit = 0;
        for(auto r : m){
            if( r.first == 0) rabbit += r.second;
            else{
                rabbit += (r.second/(r.first+1))*(r.first + 1);
                if(r.second % (r.first +1)){
                    rabbit += r.first +1;
                }
            }
        }
        return rabbit;
    }
};
