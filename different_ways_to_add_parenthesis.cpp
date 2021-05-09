class Solution {
public:
    map<string,vector<int>>m;
    vector<int> diffWaysToCompute(string input) {
        vector<int>v;
        if(m.find(input) != m.end()){
            return m[input];
        }
        for(int i = 0 ; i  < input.size(); i++){
            if(input[i] == '+'){
                auto a = diffWaysToCompute(input.substr(0,i));
                auto b = diffWaysToCompute(input.substr(i+1));
                for(auto it1: a){
                    for(auto it2: b){
                        v.push_back(it1+it2);
                    }
                }
            }
            if(input[i] == '-'){
                auto a = diffWaysToCompute(input.substr(0,i));
                auto b = diffWaysToCompute(input.substr(i+1));
                for(auto it1: a){
                    for(auto it2: b){
                        v.push_back(it1-it2);
                    }
                }
            }
            if(input[i] == '*'){
                auto a = diffWaysToCompute(input.substr(0,i));
                auto b = diffWaysToCompute(input.substr(i+1));
                for(auto it1: a){
                    for(auto it2: b){
                        v.push_back(it1*it2);
                    }
                }
            }
        }
        if(v.empty() && input.size() >0){
            v.push_back(stoi(input));
        }
        if(!v.empty()){
            m[input] = v;
        }
        return v;
    }
};
