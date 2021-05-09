class Solution {
public:
    int balancedString(string s) {
        map<char,int>need;
        int k = s.size()/4;
        for(int i = 0 ; i < s.size(); i++){
            need[s[i]]++;
        }
        int chars = 0;
        for(auto i : need){
            need[i.first]-= k;

        }
        for(auto i : need){
           if(i.second > 0){
                chars++;
            }
        }
        if(chars == 0) return 0;
        map<char,int>window;
        int l = 0;
        int r = 0;
        int count =0;
        int ans = INT_MAX;
        while(r < s.size()){
            char c = s[r];
            r++;
            if(need[c] > 0){
                window[c]++;
                if(window[c] == need[c]){
                    count++;
                }
            }
            while(l < r && count == chars){
                ans = min(ans,r-l);
                //cout<<ans<<" ";
                char d = s[l];
                l++;

                //l++;
               // cout<<d<<" "<<need[d]<<" ,";
                if(need[d] > 0){
                     window[d]--;
                    if(need[d] > window[d]){
                    count--;
                   }
                }

            }
            //r++;
        }
        return ans;
    }
};
