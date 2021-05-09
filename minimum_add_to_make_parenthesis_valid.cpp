class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0;
        stack<char>parenthesis;
        for(auto c: S){
            if(c == '('){
                parenthesis.push(c);
            }
            else{
                if(parenthesis.empty()){
                    count++;
                }
                else{
                    parenthesis.pop();
                }
            }
        }
        while(!parenthesis.empty()){
            count++;
            parenthesis.pop();
        }
        return count;
    }
};
