class MyCalendar {
public:
    vector<pair<int,int>>calendar;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(int i = 0; i < calendar.size(); i++){
            if(calendar[i].first < end && start < calendar[i].second){
                return false;
            }

        }
        calendar.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
