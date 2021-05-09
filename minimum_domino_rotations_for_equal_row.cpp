class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int countA[7]={0},countB[7]={0},Same[7]={0};

        for(int i = 0 ; i < A.size(); i++){
            int a = A[i],b = B[i];
            countA[a] +=1;
            countB[b] +=1;
            if(a==b){
                Same[a] +=1;
            }
        }
        int ans = INT_MAX;
        for(int i = 1 ; i < 7 ; i++){
            if(countA[i] + countB[i] - Same[i] == A.size()){

                int swaps = min(countA[i], countB[i]) - Same[i];
                ans = min(ans,swaps);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
