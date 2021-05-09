class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ind(groupSizes.size()+1);
        int n = groupSizes.size();
        for(int i = 0 ; i < groupSizes.size(); i++){
            ind[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(int i = 1; i <= n; i++){
            int c = 0;
            while(c < ind[i].size()){
                int j = 0;
                vector<int>temp(i);
                while(j < i){
                  temp[j] = ind[i][c+j];
                    j++;
                }
                ans.push_back(temp);
                c = c+i;
            }
        }
        return ans;
    }
};
