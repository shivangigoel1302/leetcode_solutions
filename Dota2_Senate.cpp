class Solution {
public:
    string predictPartyVictory(string senate) {
        int senator[2]={0,0};
        int bans[2]={0,0};
        queue<int>q;
        for(int i = 0 ; i < senate.size(); i++){
            if(senate[i]=='R'){
                senator[0]++;
                q.push(0);
            }
            else{
                senator[1]++;
                q.push(1);
            }
        }
        while(senator[0] > 0 && senator[1] > 0){
            int x = q.front();
            q.pop();
            if(bans[x]){
                bans[x]--;
                senator[x]--;
            }
            else{
                bans[x^1]++;
                q.push(x);
            }
        }
        return senator[0] > 0? "Radiant":"Dire";
    }
};
