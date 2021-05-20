class FindSumPairs {
public:
    vector<int>v1;
    vector<int>v2;
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(auto i : nums1){
            m1[i]++;
        }
        for(auto j : nums2){
            m2[j]++;
        }
    }

    void add(int index, int val) {
        m2[v2[index]]--;
        v2[index] += val;
        m2[v2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for(auto i: m1){
            int a = i.second;
            int b = 0;
            if(m2.find(tot-i.first) != m2.end()){
                b = m2[tot-i.first];
            }
            ans += a*b;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
