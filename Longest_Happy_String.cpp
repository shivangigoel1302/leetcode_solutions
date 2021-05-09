class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>>v={{a,'a'},{b,'b'},{c,'c'}};
        sort(v.begin(),v.end());
        char last = 'd';
        string output = "";
        while(true){
            if(last != v[2].second){
                for(int i = 0; i < 2 && v[2].first >0 ; i++){
                    v[2].first--;
                    output += v[2].second;
                    last = v[2].second;
                }
            }
            else if(v[1].first > 0){
                v[1].first--;
                output+=v[1].second;
                last = v[1].first;
            }
            if(last == v[2].second && v[0].first + v[1].first == 0){
                break;
            }
            sort(v.begin(),v.end());
        }
        return output;
    }
};
