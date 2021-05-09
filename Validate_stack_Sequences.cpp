class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i = 0;
        int j = 0;
        while(i < pushed.size()){
            while(!s.empty() && s.top() == popped[j]){
                s.pop();
                j++;
            }
            s.push(pushed[i]);
            i++;
        }
        while(j < popped.size()){
            if(s.top() != popped[j]){
                return false;
            }
            s.pop();
            j++;
        }
        return true;
    }
};
