class Solution {
public:
    bool isAlert(string name, set<string>time){
         auto it = time.begin();
        while(it!=time.end()){
            auto j = it;
             string t = *it;
            string hour = t.substr(0,2);
               int range = stoi(hour) +1;
                string newTime ="";
                if(range <= 9){
                     newTime = "0"+ to_string(range)+t.substr(2);
                }
                else{
                    newTime = to_string(range)+t.substr(2);
                }
            int count = 0;
            while(j != time.end()){
              string present = *j;
                if(newTime < present){
                    break;
                }
                count++;
               j++;

            }
            if(count >=3){
                return true;
            }
           it++;
        }
        return false;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,set<string>>m;
        for(int i = 0 ; i < keyName.size(); i++){
            m[keyName[i]].insert(keyTime[i]);
        }
         vector<string>v;
        for(auto it : m){
            if(isAlert(it.first,it.second)){
                v.push_back(it.first);
            }
        }
                return v;
    }
};
