class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size());
        int ldist = 0;
        int rdist = 0;
        int l=0,r=0;
        for(int i = 1; i < boxes.size(); i++){
            if(boxes[i] == '1'){
                rdist += i;
                r+=1;
            }
        }
        for(int i = 0 ; i < boxes.size(); i++){
            ans[i] = ldist + rdist;
            if(boxes[i] == '1'){
                l++;
            }
            ldist += l;
            rdist -= r;
            if(i+1 < boxes.size() && boxes[i+1] == '1'){
                r--;
            }
        }
        return ans;
    }
};
