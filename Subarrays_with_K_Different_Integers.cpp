class Solution {
public:
    int findsub(vector<int>A,int K){
        int j = 0;
        int count = 0;
        map<int,int>m;
        for(int i = 0 ; i < A.size(); i++){
            m[A[i]]++;
            while(m.size() > K){
                m[A[j]]--;
                if(m[A[j]] == 0){
                    m.erase(A[j]);
                }
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return findsub(A,K) - findsub(A,K-1);
    }
};
