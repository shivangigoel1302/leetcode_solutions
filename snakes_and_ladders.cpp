class Solution {
public:
    int get (int n,int i){
        int q = (i-1)/n;
        int rem = (i-1)%n;
        int r = n-1-q;
        int c = r%2 != n%2 ? rem:n-1-rem;
        return r*n+c;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        map<int,int>dist;
        dist[1] = 0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int s = q.front();
            q.pop();
            //cout<<dist[s]<<" ";
            if(s == n*n ) return dist[s];
            for(int i = s+1; i <= min(s+6,n*n); i++){
                int rc = get(n,i);
                int r = rc/n;
                int c = rc%n;
                int fin = board[r][c] == -1? i:board[r][c];
                //cout<<r<<" "<<c<<" ";
                //cout<<fin<<" ";
                if(dist.find(fin) == dist.end()){
                    dist[fin] = dist[s] +1;
                    //cout<<fin<<","<<dist[fin]<<" ";
                    q.push(fin);
                }
            }
        }
        return -1;
    }
};
