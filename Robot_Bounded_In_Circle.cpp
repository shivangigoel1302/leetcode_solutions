class Solution {
public:
    bool isRobotBounded(string instructions) {
        int north=0,west=1,south=2,east=3;
        int x=0,y=0,dir=0;
        for(auto c: instructions){
            if(c == 'L'){
                dir = (dir + 1)%4;
            }
            else if(c == 'R'){
                dir = (dir+3)%4;
            }
            else if(dir == 0){
                y++;
            }
            else if(dir == 1){
                x--;
            }
            else if(dir == 2){
                y--;
            }
            else{
                x++;
            }
        }
        return dir!=0 || (x == 0 && y == 0);
    }
};
