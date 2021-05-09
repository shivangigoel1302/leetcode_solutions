class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1 ;
        vector<int>v;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                if(nums[l] == target){
                    v.push_back(l);
                }
                else{
                   int i = mid;
                    while(nums[i] == target){
                        i--;
                    }
                    v.push_back(i+1);
                }
                if(nums[r] == target){
                    v.push_back(r);
                }
                else{
                   int i = mid;
                    while(nums[i] == target){
                        i++;
                    }
                    v.push_back(i-1);
                }
                break;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(v.size() ==0){
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};
