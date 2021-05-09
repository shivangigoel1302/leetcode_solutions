class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int age[121] ={0};
        for(int i = 0 ; i < ages.size(); i++){
            age[ages[i]] ++;
        }
        int ans = 0;
        for(int agea = 0 ; agea <= 120 ; agea++){
            int counta = age[agea];
            for(int ageb = 0 ; ageb <= 120 ; ageb++){
                int countb = age[ageb];
                if(agea *0.5 + 7 >= ageb || agea<ageb || (agea<100 && ageb >100)){
                    continue;
                }
                ans+=counta*countb;
                if(agea==ageb){
                    ans -= counta;
                }
            }
        }
        return ans;
    }
};
