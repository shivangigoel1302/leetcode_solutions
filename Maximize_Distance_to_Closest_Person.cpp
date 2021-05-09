class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int>left(seats.size(),n);
        vector<int>right(seats.size(),n);
        for(int i = 0 ; i < seats.size(); i++){
            if(seats[i] == 1 ){
                left[i] = 0;
            }
            else if(i>0){
                left[i] = left [i-1] +1;
            }
        }
        for(int i = seats.size()-1 ; i >=0 ; i--){
            if(seats[i] == 1){
                right[i] = 0;
            }
            else if( i < seats.size()-1){
                right[i] = right[i+1] +1;
            }
        }
        int maximum = INT_MIN;
        int index = 0;
        for(int i = 0 ; i <left.size(); i++){
             if(seats[i] == 1){
                continue;
            }
            int minimum = min(left[i],right[i]);

            if(minimum > maximum){
                maximum = minimum;
                index = i;
            }
        }

        return maximum;
    }
};
