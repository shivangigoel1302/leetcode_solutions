class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        n--;
        string start = "1";
        while(n--){
            string result = "";
            string temp = start;
            int k = 0 ;
            while(k < temp.size()){
                int number = temp[k] -'0';
                int count = 1;
                while(temp[k+1]- '0' == number){
                    k++;
                    count++;
                }
                k++;
                char c = count+ '0';
                result.push_back(c);
                result.push_back(number+'0');
            }
            start = result;
        }
        return start;
    }
};
