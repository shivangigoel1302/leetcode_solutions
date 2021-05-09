class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for(char c: s)
            freq[c]++;
        multimap<int, char, greater <int> > dec;
        for(auto i:freq){
            dec.insert(make_pair(i.second, i.first));
        }
        string res;
        for(auto i: dec){
            int num=i.first;
            while(num){
                res.push_back(i.second);
                num-=1;
            }
        }
        return res;
    }
};
