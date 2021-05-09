class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        int unique = 0;
        for(int i = 0; i < arr.size(); i++){
            if(m.count(arr[i])){
                m[arr[i]]++;
            }
            else{
                unique++;
                m[arr[i]] = 1;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it: m){
            pq.push({it.second,it.first});
        }
        while(k > 0 && !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(k - curr.first >= 0){
                unique--;
            }
            k = max(0,k-curr.first);
        }
        return unique;
    }
};
