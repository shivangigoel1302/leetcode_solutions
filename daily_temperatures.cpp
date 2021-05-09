class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>v(T.size());
        if(T.size() ==0){
            return v;
        }
        stack<int>s;
        s.push(T.size() -1);
        v[T.size() - 1] = 0;
        for(int i = T.size()-2 ; i >= 0 ; i--){

            while(!s.empty() && T[i] >= T[s.top()] ){
                s.pop();

            }
            if(s.empty()){
                v[i] = 0;
            }
            else{
                v[i] = s.top() - i;
            }
            s.push(i);
        }
        return v;
    }
};
