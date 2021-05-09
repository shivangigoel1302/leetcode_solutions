class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int,int>m;
        set<int>s;
        int start = 0;
        int i = 0;
        int len = 0;
        while(i < tree.size()){
            m[tree[i]]++;
            s.insert(tree[i]);
            if(s.size() > 2){
                len = max(len, i- start);
            }
            while(start < i && s.size() > 2){
                m[tree[start]]--;
                if(m[tree[start]] == 0){
                    s.erase(tree[start]);
                }
                start++;
            }
            i++;
        }
        len = max(len,i-start);
        return len;
    }
};
