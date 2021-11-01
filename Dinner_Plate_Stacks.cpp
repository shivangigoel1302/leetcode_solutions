class DinnerPlates {
public:
    vector<stack<int>>v;
    set<int>for_push;
    int c;
    DinnerPlates(int capacity) {
        c = capacity;
        v.clear();
        for_push.insert(0);
    }

    void push(int val) {
       int idx = *for_push.begin();
        if(v.size() <= idx){
            stack<int>st;
            st.push(val);
            v.push_back(st);
            for_push.insert(v.size());
        }
        else{
            v[idx].push(val);
        }
        if(v[idx].size() == c){
            for_push.erase(idx);
        }
    }

    int pop() {
        if(v.size() == 0){
            return -1;
        }
        int res = v.back().top();
        if(v.back().size() == c){
            for_push.insert(v.size()-1);
        }
        v.back().pop();
        while(v.size() && v.back().empty()){
            v.pop_back();
        }
        return res;
    }

    int popAtStack(int index) {
        if(index >= v.size() || v[index].empty()){
            return -1;
        }
        if(v[index].size() == c){
            for_push.insert(index);
        }
        int res = v[index].top();
        v[index].pop();
        if(index == v.size()-1 && v[index].empty()){
            v.pop_back();
        }
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
