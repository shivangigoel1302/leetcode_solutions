class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1){
            if(target[0] == 1){
                return true;
            }
            return false;
        }
        priority_queue<long long int>pq;
        long long int sum = 0;
        int n = target.size();
        for(int i = 0 ; i < n; i++){
            pq.push(target[i]);
            sum += target[i];
        }
        while(pq.top() != 1){
            long long int x = pq.top();
            pq.pop();
            sum -= x;
            long long int q;
            if(x%sum == 0){
                q = x/sum;
                q--;
            }
            else{
                q = x/sum;
            }
            if(q < 1){
                return false;
            }
            long long int temp = x - q*sum;
            sum += temp;
            pq.push(temp);

        }
        return true;
    }
};
