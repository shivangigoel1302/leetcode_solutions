class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int>m;
        for(int i = 0 ; i < hand.size(); i++){
            m[hand[i]]++;
        }
        for(auto c: m){

            if(c.second > 0){
                 for(int card = c.first ; card < c.first+W; card++){
                if(m.find(card) == m.end()){
                    return false;
                }
                if(m[card] < c.second){
                    return false;
                }
                m[card] = m[card] - c.second;
               }
            }

            //m.erase(c.first);
        }
        return true;
    }
};
