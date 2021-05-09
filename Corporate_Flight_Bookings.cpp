class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>seat(n+1,0);
        for(int i = 0; i < bookings.size(); i++){
            seat[bookings[i][0]-1] += bookings[i][2];
            seat[bookings[i][1]] -= bookings[i][2];
        }
        for(int i = 1 ; i < seat.size(); i++){
            seat[i] += seat[i-1];
        }
        seat.pop_back();
        return seat;
    }
};
