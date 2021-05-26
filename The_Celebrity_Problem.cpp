public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        // code here
        vector<int>indegree(n,0);
        vector<int>outdegree(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
