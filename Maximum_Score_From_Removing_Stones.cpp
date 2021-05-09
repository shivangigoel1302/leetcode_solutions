class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int count = 0;
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x!= 0 && y != 0){

                count++;
                if(x!= 1){
                    pq.push(--x);
                }
                if(y != 1){
                    pq.push(--y);
                }
            }
        }
        return count;
    }
};
