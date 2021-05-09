class SnapshotArray {
public:
    vector<vector<pair<int,int>>>v;
    int s;

    SnapshotArray(int length) {
        v.resize(length);
        s=0;
        for(int i = 0 ; i < length; i++){
            v[i].push_back({s,0});
        }
    }

    void set(int index, int val) {
        v[index].push_back({s,val});
    }

    int snap() {
        s++;
        return s-1;
    }

    int get(int index, int snap_id) {
        int i;
        for(i = 0 ; i < v[index].size(); i++){
            if(v[index][i].first > snap_id){
                return v[index][i-1].second;
            }
        }
        return v[index][i-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
