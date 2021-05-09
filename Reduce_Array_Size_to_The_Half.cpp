class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i = 0;
        map<int,vector<int>,greater<int>>m;
        while(i < arr.size()){
            int j = i;
            while(j < arr.size() && arr[j] == arr[i]){
                j++;
            }
            int count = j-i;
            m[count].push_back(arr[i]);
            i = j;
        }
        int ans = 0;
        int minimum = arr.size()/2;
        for(auto i : m){

            if(minimum <= 0){
                return ans;
            }
            int amt = minimum/i.first + (minimum%i.first >0);
            int a = min(amt, (int)i.second.size());
            ans += a;
            minimum -= a * i.first;
        }
        return ans;
    }
};
