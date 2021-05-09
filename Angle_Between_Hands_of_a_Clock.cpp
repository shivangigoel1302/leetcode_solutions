class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
    double hr = (hour + (1/(60*1.0) )*minutes)*5;
        //cout<<hr<<" ";
        double diff = min(abs(hr-minutes),abs(60 - abs(hr-minutes)));
        return diff * 6;
    }
};
