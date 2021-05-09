class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_map<int,int>ans;
        unordered_map<int,int>curr;

        for(auto x: arr){
            unordered_map<int,int>temp;
            for(auto y: curr){
                temp.insert({y.first | x,1});
            }
            temp.insert({x,1});
            curr = temp;
            for(auto i : curr){
                ans.insert({i.first,1});
            }
        }
        return (int)ans.size();
    }
};
