class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() == 0){
            return 0;
        }
        int maxlen = 0;
        for(int i =  1 ; i < A.size()-1; ){
            if(A[i] > A[i-1] && A[i] > A[i+1]){
                int count = 1;
                int j = i;
                while(j >0 && A[j] > A[j-1]){
                    count++;
                    j--;
                }
                while(i < A.size()-1 && A[i] > A[i+1]){
                    i++;
                    count++;
                }
                maxlen = max(maxlen,count);
            }
            else{
                i++;
            }
        }
        return maxlen;
    }
};
