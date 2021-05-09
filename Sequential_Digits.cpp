class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i = 1; i <=9 ; i++){
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(n >= low && n <= high){
                ans.push_back(n);
            }
            if(n%10 == 9){
                continue;
            }
            int n1 = n%10+1;
            n = n*10 + n1;
            if(n <= high){
                q.push(n);
            }
        }
        return ans;
    }
};
