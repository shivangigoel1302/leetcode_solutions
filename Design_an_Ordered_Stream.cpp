class OrderedStream {
public:
    vector<string>v;
    int i;
    int n;
    OrderedStream(int N) {
        i = 0;
        v.resize(N);
        n = N;
    }

    vector<string> insert(int id, string value) {
        v[id-1] = value;
        vector<string>ans;
        while(i < n){
            if(v[i].size() != 0){
                ans.push_back(v[i]);
            }
            else{
                return ans;
            }
            i++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
