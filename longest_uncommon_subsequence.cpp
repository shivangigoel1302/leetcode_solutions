class Solution {
public:
    bool issub(string a,string b){
       int x  = a.length();
        int cnt=0;
        for(int i=0 ; i<b.length();i++)
        {
            if(cnt < x && b[i] == a[cnt]) cnt++;
        }

        return (cnt==x)?1:0;
    }
    int findLUSlength(vector<string>& strs) {
        int maxlen = -1;
        for(int i = 0 ; i < strs.size(); i++){
            bool found = false;
            for(int j = 0 ; j < strs.size(); j++){
                if(j!=i){

                    if(issub(strs[i],strs[j])){

                        found = true;
                        break;
                    }
                }
            }
            if(!found && int(strs[i].size()) > maxlen){
                maxlen = strs[i].size();
            }
        }
        return maxlen;
    }
};
