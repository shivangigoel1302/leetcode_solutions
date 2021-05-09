class Solution {
public:
    bool isPathCrossing(string path) {
        if(path.size() == 0){
            return true;
        }
        int a = 0;
        int b =0;
        set<pair<int,int>>s;
        s.insert({a,b});
        for(int i = 0 ; i < path.size(); i++){
            if(path[i] == 'N'){
                b++;
            }
            if(path[i] == 'S'){
                b--;
            }
            if(path[i] == 'E'){
                a++;
            }
            if(path[i] == 'W'){
                a--;
            }
            if(s.find({a,b}) !=s.end()){
                return true;
            }
            s.insert({a,b});
        }
        return false;
    }
};
