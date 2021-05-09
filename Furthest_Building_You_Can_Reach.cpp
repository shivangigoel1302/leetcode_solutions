class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>q;
        int i = 0;
        while(i < heights.size()-1){
            if(heights[i+1] <= heights[i]){
                i++;
                continue;
            }
            int diff = heights[i+1]-heights[i];
            if(bricks >= diff){
                bricks -= diff;

                q.push(diff);
            }
            else if(ladders > 0){
                if(q.size()){
                    int t = q.top();
                    if(t > diff){
                        bricks += t;
                        bricks -= diff;
                        q.pop();
                        q.push(diff);
                    }
                }
                ladders-=1;
            }
            else{
                break;
            }
            i++;
        }
        return i;
    }
};
