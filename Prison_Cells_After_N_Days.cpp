class Solution {
public:
    vector<int>nx;
    void next(vector<int>&cells){
        for(int i = 1; i < 7; i++){
            if(cells[i-1] == cells[i+1]){
                nx[i] = 1;
            }
            else{
                nx[i] = 0;
            }
        }
        cells= nx;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        nx.resize(8);
        nx[0] = 0;
        nx[7] = 0;
        next(cells);
        N = (N-1)%14;
        for(int i = 0;i < N; i++){
            next(cells);
        }
        return cells;
    }
};
