class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = n-1;
        int prod = 1;
        stack<int>s;
        s.push(1);
        s.push(1);
        map<string,int>m;
        while(i>=0){
            if(formula[i] >= '0' && formula[i] <= '9'){
                string digits = "";
                while(formula[i] >='0' && formula[i] <= '9'){
                    digits= formula[i] + digits;
                    i--;
                }
                int num = stoi(digits);
                if(formula[i] == ')'){
                    prod*=num;
                    s.push(num);
                }
                else{
                    if(formula[i] >='A' && formula[i] <= 'Z'){
                        string temp = "";
                        temp+=formula[i];
                        m[temp] += prod*num;
                        i--;
                    }
                    else if(formula[i] >='a' && formula[i] <='z'){
                        string temp = "";
                        temp += formula[i-1];
                        temp+=formula[i];
                        m[temp] += prod*num;
                        i-=2;
                    }
                }
            }
            else{
                if(formula[i] == '('){
                    prod/=s.top();
                    s.pop();
                    i--;
                }
                else if(formula[i] >='A' && formula[i] <= 'Z'){
                    string temp = "";
                    temp+= formula[i];
                    if(i < n-1 && formula[i+1] >='a' && formula[i+1] <= 'z'){
                        temp+= formula[i+1];
                    }
                   m[temp] += prod;
                    i--;
                }
                else{
                    i--;
                }
            }
        }
        string ans = "";
        for(auto it : m){
            ans+=it.first;
            int count = it.second;
            if(count!=1){
                string c = to_string(count);
                 ans+=c;
            }

        }
        return ans;
    }
};
