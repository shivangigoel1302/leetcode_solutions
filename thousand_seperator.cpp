class Solution {
public:
    string thousandSeparator(int n) {
        if(n<1000){
            return to_string(n);
        }
        string ans = to_string(n);
        string result ="";
        int count = 0;
        for(int i = ans.size() -1 ; i >=0 ; i--){
            result=ans[i] +result;
            count++;
            if(count == 3){
                result= '.' +result;
                count = 0;
            }
        }
        if(result[0] == '.'){
            return result.substr(1);
        }
        return result;
    }
};
