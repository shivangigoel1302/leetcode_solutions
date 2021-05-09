class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char,pair<int,int>>m;
        int c = 0;

        for(int i = 0 ; i < 5; i++){
            for(int j = 0 ; j < 5; j++){
                char ch = c+'a';
                m[ch] ={i,j};
                //cout<<ch<<"--"<<i<<" "<<j<<endl;
                c++;
            }
        }
        m['z'] = {5,0};
        pair<int,int> curr = {0,0};
        string ans = "";
        for(int i = 0 ; i < target.size(); i++){
            pair<int,int>req = m[target[i]];
            if(req.first == curr.first && req.second == curr.second){
                ans += '!';
                continue;
            }
            else if(req.first == curr.first){
                int diff = req.second - curr.second;
                if(diff > 0){
                    while(diff--){
                        ans += 'R';
                    }
                }
                else{
                    while(diff++){
                        ans += 'L';
                    }
                }
                curr = req;

            }
            else if(req.second == curr.second){
                int diff = req.first - curr.first;
                if(diff > 0){
                    while(diff--){
                        ans += 'D';
                    }
                }
                else{
                    while(diff++){
                        ans += 'U';
                    }
                }
                curr = req;

            }
            else{
                int xdiff = req.first - curr.first;
                int ydiff = req.second - curr.second;
                curr = req;
                if(xdiff > 0 && ydiff > 0){

                     while(xdiff--){
                        ans += 'D';
                    }
                     while(ydiff--){
                        ans += 'R';
                    }

                }
                else if(xdiff < 0 && ydiff > 0){
                     while(xdiff++){
                        ans += 'U';
                    }
                     while(ydiff--){
                        ans += 'R';
                    }

                }
                else if(xdiff > 0 && ydiff < 0){
                    while(ydiff++){
                        ans += 'L';
                    }
                    while(xdiff--){
                        ans += 'D';
                    }
                }
                else if(xdiff < 0 && ydiff < 0){
                     while(xdiff++){
                        ans += 'U';
                    }
                     while(ydiff++){
                        ans += 'L';
                    }
                }


            }
            ans += '!';
        }
        return ans;
    }
};
