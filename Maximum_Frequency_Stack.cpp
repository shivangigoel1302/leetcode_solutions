class FreqStack {
public:
    map<int,int>freq;
    map<int,stack<int>>group;
    int maxfreq;
    FreqStack() {
        maxfreq = 0;
    }

    void push(int x) {
        freq[x]++;
        group[freq[x]].push(x);
        maxfreq = max(maxfreq,freq[x]);
    }

    int pop() {
        int t = group[maxfreq].top();
        freq[t]--;
        group[maxfreq].pop();
        if(group[maxfreq].empty()){
            maxfreq--;
        }
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
