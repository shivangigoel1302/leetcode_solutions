class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int l = 0;
        int h = tokens.size()-1;
        int ans = 0;
        while( l<= h && (P >= tokens[l] || score >0)){
            while(l <= h && P >= tokens[l]){
                score++;
                P-=tokens[l];
                l++;
            }
            ans = max(ans,score);
            if(l <= h && score >0){
                score--;
                P+=tokens[h];
                h--;
            }
        }

        return ans;
    }
};
