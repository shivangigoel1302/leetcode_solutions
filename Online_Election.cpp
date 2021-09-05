class TopVotedCandidate {
public:
    vector<int>p,t,status;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        t = times;
        status.resize(t.size());
        status[0] = persons[0];
        unordered_map<int,int>m;
        int maxfreq = 1;
        int l = persons[0];
        m[persons[0]] = 1;
        for(int i = 1; i < times.size(); i++){
            m[persons[i]]++;
            if(m[persons[i]] > maxfreq){
                maxfreq = m[persons[i]];
                l = persons[i];
            }
            else if(m[persons[i]] == maxfreq){
                l = persons[i];
            }
            status[i] = l;
        }
    }

    int q(int time) {
        auto idx = upper_bound(t.begin(),t.end(),time);
        int i = --idx - t.begin();
        return status[i];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
