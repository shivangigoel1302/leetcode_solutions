class ExamRoom {
public:
    vector<int>seats;
    int n;
    ExamRoom(int N) {
       n = N;
    }

    int seat() {
        if(seats.size() == 0){
            seats.push_back(0);
            return 0;
        }
        int d = max(seats[0],n-1-seats[seats.size()-1]);
        for(int i = 0 ; i < seats.size()-1 ; i++){
            d = max(d,(seats[i+1]-seats[i])/2);
        }
        if(seats[0] == d){
            seats.insert(seats.begin(),0);
            return 0;
        }
        for(int i = 0 ; i < seats.size()-1; i++){
            if((seats[i+1] - seats[i])/2 == d){
                seats.insert(seats.begin() + 1 + i, (seats[i+1] + seats[i])/2);
                return seats[i+1];
            }
        }
        seats.push_back(n-1);
        return n-1;
    }

    void leave(int p) {
        for(int i = 0 ;i < seats.size(); i++){
            if(seats[i] == p){
                seats.erase(seats.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
