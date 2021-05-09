class Solution {
public:
    int getMaxLen(vector<int>& nums) {
     int start=-1,ineg=-1,len=0;
        int countneg = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                start = -1;
                ineg =-1;
                countneg = 0;
                continue;
            }
            if(start == -1) start = i;
            if(nums[i] < 0){
                countneg++;
                if(ineg == -1) ineg = i;

            }
            if(countneg%2 == 0){
                len = max(len,i-start + 1);
            }
            else{
                len = max(len,i-ineg);
            }
        }
        return len;
    }
};
