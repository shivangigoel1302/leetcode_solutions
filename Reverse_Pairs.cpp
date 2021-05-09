class Solution {
public:
    void merge(vector<int>&nums, int l, int r, int mid){
        vector<int>ans(r-l+1);
        int k = 0;
        int i = l,j=mid+1;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                ans[k++] = nums[i++];
            }
            else{
                ans[k++] = nums[j++];
            }
        }
        while(i <= mid){
            ans[k++] = nums[i++];
        }
        while(j <= r){
            ans[k++] = nums[j++];
        }
        i = l;
        k = 0;
        while(k <= r-l){
            nums[i++] = ans[k++];
        }
        return;
    }
    int mergesort(vector<int>&nums, int l ,int r){
        if(l >= r){
            return 0;
        }
        long long int mid = (l+r)/2;
        long long int count = mergesort(nums,l,mid) + mergesort(nums,mid+1,r);
        long long int j = mid+1;
        for(int i = l; i <=mid; i++){
            while(j <= r && nums[i] > (long long)nums[j]*2){
                j++;
            }
            count += j - (mid+1);
        }
        merge(nums,l,r,mid);
        return count;
    }
    int reversePairs(vector<int>& nums) {

       return mergesort(nums,0,nums.size()-1);


    }
};
