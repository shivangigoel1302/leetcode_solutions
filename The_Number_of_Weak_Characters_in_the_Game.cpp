class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](vector<int>&v1,vector<int>&v2){
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return v1[0] <v2[0];
        });

         int ans = 0;
        int maxa = INT_MIN;
        for(int i = properties.size()-1; i >=0 ; i--){
            if(properties[i][1] < maxa){
                ans++;
            }
            maxa =  max(maxa,properties[i][1]);
        }
        return ans;
    }
};
