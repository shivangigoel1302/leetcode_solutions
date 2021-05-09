class Solution {
public:

    string findReplaceString(string& S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
       map<int, pair<string, string>> replace;
    string ans = S;
    for (int i = 0; i < indexes.size(); ++i)
        if (S.substr(indexes[i], sources[i].size()) == sources[i])
            replace.insert({indexes[i], {sources[i], targets[i]}});

    int offset = 0;
    for (auto& kv : replace) {
        int i = kv.first + offset;
        string& ss = kv.second.first;
        string& tt = kv.second.second;
        ans.erase(i, ss.size());
        ans.insert(i, tt);
        offset += tt.size() - ss.size();
    }
    return ans;
    }
};
