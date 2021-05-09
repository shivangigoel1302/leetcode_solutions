class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        int m = restrictions.size();
        for(int i = 1; i < m ; i++){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0]);
        }
        for(int i = m-2; i >=0; i--){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0]);
        }
        int ans = 0;
        for(int i = 1; i < m; i++){
            int h1 = restrictions[i][1];
            int h2 = restrictions[i-1][1];
            int r = restrictions[i][0],l = restrictions[i-1][0];
            ans = max(ans,max(h1,h2) + (r-l-abs(h1-h2))/2);
        }
        return ans;
    }
};
// recursive solution but gave tle
// class Solution {
// public:
//     vector<vector<long>>dp;
//     bool helper(vector<int>&build, int i, int prev,unordered_map<int,int>&rest,map<pair<int,int>,bool>&m){
//         if(i == build.size()){
//             return true;
//         }

//         int j = prev+1;
//         if(rest.find(i) != rest.end()){
//             int res = rest[i];
//             if(res < prev - 1){
//                 return false;
//             }
//             j = min(j,res);
//         }
//         for(; j >= prev-1; j--){
//             build[i] = j;
//             if(m.find({i,j}) != m.end()){
//                   if(m[{i,j}]){
//                       return true;
//                   }
//                   continue;
//             }
//             if(helper(build,i+1,j,rest,m)){
//                 m[{i,j}] = true;
//                 return true;
//             }
//             m[{i,j}] = false;
//             build[i] = 0;
//         }
//         return false;
//     }
//     int maxBuilding(int n, vector<vector<int>>& restrictions) {
//         vector<int>build(n+1,0);
//         build[2] = 1;
//         map<pair<int,int>,bool>m;
//         unordered_map<int,int>rest;
//         for(int i = 0 ; i < restrictions.size(); i++){
//             rest[restrictions[i][0]] = restrictions[i][1];
//         }
//         helper(build,3,1,rest,m);
//         int maximum = 0;
//         for(int i = 1; i <=n ;i++){
//             maximum = max(maximum,build[i]);
//         }
//         return maximum;
//     }
// };


