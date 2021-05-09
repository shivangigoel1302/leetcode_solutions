class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
       int n = A.size();
       long long ans = 0;
       for(int i = 0 ; i < n ;){
           int t = i;
           while(i < n && A[i] <=R){
               if(A[i] < L){
                   int count = 0;
                   while(i < n && A[i] <L){
                       count++;
                       i++;
                   }
                   ans -= (count*(count+1)/2);
               }
               else{i++;}
           }
           ans += (i-t)*(i-t+1)/2;
           i++;
       }
        return ans;
    }
};
