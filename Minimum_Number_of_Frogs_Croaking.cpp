class Solution {
public:
    int minNumberOfFrogs(string frogs) {
       map<string,int>m;
        int ans = 0;
        int count = 0;
        for(int i = 0 ; i < frogs.size();i++){
            if(frogs[i] == 'c'){
                m["c"]++;
                count++;
            }
            else if(frogs[i] =='r'){
                if(m["c"] <= 0)return -1;
                m["c"]--;
                m["cr"]++;
            }
              else if(frogs[i] =='o'){
                if(m["cr"] <= 0)return -1;
                m["cr"]--;
                m["cro"]++;
            }
              else if(frogs[i] =='a'){
                if(m["cro"] <= 0)return -1;
                m["cro"]--;
                m["croa"]++;
            }
              else if(frogs[i] =='k'){
                if(m["croa"] <= 0)return -1;
                m["croa"]--;
                m["croak"]++;
                  count--;
            }
            ans = max(ans,count);
        }
        if(m["c"] != 0 || m["cr"] != 0 || m["cro"]!=0|| m["croa"]!=0 ){
            return -1;
        }
        return ans;
    }
};
