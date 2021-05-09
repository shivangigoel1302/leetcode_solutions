class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        vector<int>moves(machines.size(),0);
        int sum = 0;
        for(auto i: machines){
            sum += i;
        }
        int n = machines.size();
        if(sum %n != 0){
            return -1;
        }
        int req = sum/n;
        int ans = 0;
        for(int i = 0 ; i < moves.size()-1; i++){
            int delta = machines[i] - req;
            machines[i+1] += delta;
            if(delta < 0){
                moves[i+1] += -delta;
            }
            else{
                moves[i] += delta;
            }
            ans = max(ans,moves[i]);
        }
        ans = max(ans, moves[n-1]);
        return ans;
    }
};
