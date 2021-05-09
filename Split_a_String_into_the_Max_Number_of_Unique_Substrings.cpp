class Solution {
public:

    void helper(string s, int start,vector<string>v,map<string,bool>&m,int &maximum){
        if(start >= s.size()){
            int size = v.size();
            if(size > maximum){
                cout<<v.size();
                maximum = v.size();

            }
        }
        for(int end = start; end < s.size(); end++){
            if(m.find(s.substr(start,end-start+1)) == m.end()){
                v.push_back(s.substr(start,end-start+1));
                m[s.substr(start,end-start+1)] = true;
                helper(s,end+1,v,m,maximum);
                v.pop_back();
                m.erase(s.substr(start,end-start+1));
            }

        }
    }
    int maxUniqueSplit(string s) {
        vector<string>v;
        map<string,bool>m;
        int maximum  = INT_MIN;
        helper(s,0,v,m,maximum);
        return maximum;
    }
};
