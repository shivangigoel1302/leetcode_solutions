class Solution {
public:
    int mod;
    bool issame(int i,string s,int j,long long len){
        if(s.substr(i,len) != s.substr(j,len)){
            return false;
        }
        return true;

    }
    bool match(long long mid,string s, vector<long long>roll, string&ans){
        mod = 1e9+7;
        unordered_map<long long,vector<int>>m;
        long long curr = 0;
        for(int i = 0 ; i <mid ; i++){
            curr += roll[mid-i-1]*(s[i]-'a'+1);
            curr %= mod;
        }
        m[curr].push_back(0);

        for(int i = 1; i + mid <= s.size(); i++){
            curr = ((curr -roll[mid-1]*(s[i-1] -'a' + 1))%mod + mod)%mod;
            curr *= 26;
            curr%=mod;
            curr += (s[i+mid-1] - 'a' + 1);

            if(m.find(curr) != m.end()){

                for(int j = 0 ; j < m[curr].size(); j++){

                    if(issame(m[curr][j],s,i,mid)){
                        ans = s.substr(i,mid);

                        return true;
                    }
                }
            }
            m[curr].push_back(i);
        }

        return false;
    }
    string longestDupSubstring(string s) {
       if(s.size() == 0){
           return "";
       }
        int l = 1;
        string fin ="";
        int r = s.size();
        mod = 1e9+7;
        vector<long long >roll(r);
        roll[0] = 1;
        for(int i = 1 ; i < r; i++){
            roll[i] = (26*roll[i-1])%mod;
        }
        string ans = "";
        while(l <= r){
            long long mid = (l+r)/2;
            //cout<<mid<<" ";
            if(match(mid,s,roll,ans)){
                if(fin.size() < ans.size()){
                    fin = ans;
                }
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return fin;
    }
};
