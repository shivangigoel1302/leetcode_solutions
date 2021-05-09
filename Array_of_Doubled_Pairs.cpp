class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>m;
        for(int i = 0 ; i < arr.size(); i++){
            m[arr[i]]++;
        }
        for(auto it: m){
            int freq = it.second;
            int val = it.first;
            if(val < 0){
                if(val % 2){
                    return false;
                }
                if(m.find(val/2) != m.end()){
                    if(m[val/2] < m[val]){
                        return false;
                    }
                    else{
                        m[val/2] -= m[val];
                        if(m[val/2] == 0){
                            m.erase(val/2);
                        }
                        m.erase(val);
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if(m.find(val*2) != m.end()){
                    if(m[val*2] < m[val]){
                        return false;
                    }
                    else{
                        m[val*2] -= m[val];
                        if(m[val*2] == 0){
                            m.erase(val*2);
                        }
                        m.erase(val);
                    }
                }
                else{
                    return false;
                }
            }

        }
        return true;
    }
};
