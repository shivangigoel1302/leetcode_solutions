class Solution {
public:
    void findpermute(string &s){
        int n = s.length();
        for(int i = n-1; i > 0; i--){
            if(s[i] > s[i-1]){
                int minimum = s[i];
                int j = i+1;
                int idx = i;
                while(j < n){
                    if(minimum - s[i-1] >= s[j] - s[i-1] && s[j] - s[i-1] > 0){
                        minimum = s[j];
                        idx = j;
                    }
                    j++;
                }
               // cout<<idx<<" ";
                swap(s[i-1],s[idx]);
                reverse(s.begin() + i,s.end());
                break;
            }
        }
        return;
    }
    int compare(string orig,string n){

        int cnt = 0;

        for(int i = 0; i < orig.size(); i++){
            if(orig[i] != n[i]){
                int j = i+1;
                while(j < n.size() && n[i] != orig[j]){
                    j++;
                }

                while(j > i){
                    cnt++;
                    swap(orig[j],orig[j-1]);
                    j--;
                }

            }
        }
        return cnt;
    }
    int getMinSwaps(string num, int k) {
        string original = num;

        while(k--){
            findpermute(num);
        }
       // cout<<num;
        return compare(num,original);

    }
};
