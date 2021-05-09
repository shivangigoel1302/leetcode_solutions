class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int count = 0;
        int n = S.size();
        for(int i = 0 ; i < words.size(); i++){
            int m = words[i].size();
            int js =0;
            string w = words[i];
            int jw = 0;
            int f = 0;
            while(js < n){
                char c = S[js];
                int k = js;
                while(k < n && S[k] == c){
                    k++;
                }
                int l = jw;
                while(l < m && w[l] == c ){
                    l++;
                }
                if(l - jw !=0 && k-js >= l-jw && (k - js == l - jw || k - js >= 3)){
                    f =0;
                }
                else{
                    f = 1;
                    break;
                }
                js = k;
                jw =l;
            }
            if(jw != m){
                f = 1;
            }
            if(f == 0){
                count++;
            }
        }
        return count;
    }
};
