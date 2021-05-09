class Solution {
public:
    bool isValid(vector<int>&position, int mid, int m){
        int low = position[0];
        m--;
        for(int i = 1; i < position.size(); i++){
            if(position[i] - low >= mid){
                m--;
                low = position[i];
                if(m == 0){
                    break;
                }
            }
        }
        if(m >= 1){
            return false;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 0;
        int e = position[position.size() - 1];
        int ans = 1;
        while(s<=e){
            int mid = (s+e)/2;
            if(isValid(position,mid,m)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        }
        return ans;
    }
};
