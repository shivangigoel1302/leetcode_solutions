class Solution {
public:
    int findmax(int j, string s){
        int maximum = j;
        for(int i = j; i < s.size(); i++){
            cout<<(s[i]-'0')<<","<<s[maximum]<<" ";
            if(s[i]-'0' >= s[maximum]-'0'){
                maximum = i;
            }
        }
        return maximum;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            int idx = findmax(i,s);
            cout<<idx<<" ";
            if(idx == i){
                continue;
            }
            if(s[idx] == s[i]){
                continue;
            }
            else{
                swap(s[i],s[idx]);
                break;
            }
        }
        num = stoi(s);
        return num;
    }
};
