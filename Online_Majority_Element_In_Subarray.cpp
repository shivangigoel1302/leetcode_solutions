class MajorityChecker {
public:
    unordered_map<int,vector<int>>m;
    vector<int>a;
    int try_bound;
    MajorityChecker(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]].push_back(i);
        }
        a = arr;
        try_bound = 20;
    }
    int getrand(int l,int r){
        return rand()%(r-l+1) + l;
    }
   int get_occurrence(int num, int l, int r) {
        auto iter = m.find(num);
        if (iter == m.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }
    int query(int left, int right, int threshold) {
        for(int i = 0;i < try_bound; i++){
            int ele = a[getrand(left,right)];
            if(get_occurrence(ele,left,right) >= threshold){
                return ele;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
