// class Solution {
// public:
//     bool isvalid(vector<int>v){
//         if(v[0] + v[1] <= v[2]){
//             return false;
//         }

//         return true;
//     }
//     void helper(vector<int>nums, int i , int &count,int s,vector<int>v){
//         if( s == 3){
//             if(isvalid(v)){
//                 count++;
//             }
//             return;
//         }
//         for(int j =i ; j < nums.size(); j++){
//             v.push_back(nums[j]);
//             helper(nums,j+1,count, s+1,v);
//             v.pop_back();
//         }
//     }
//     int triangleNumber(vector<int>& nums) {
//         int count = 0;
//         vector<int>v;
//         sort(nums.begin(),nums.end());
//         helper(nums,0, count,0,v);
//         return count;
//     }
// };
class Solution {
public:
    int binarysearch(vector<int>nums,int l, int r, int x){
        while(r>=l && r < nums.size()){
            int mid = (l+r)/2;
            if(nums[mid] >=x){
                r=mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0 ; i < nums.size() - 2; i++){
            int k = i+2;
            for(int j = i+1; j < nums.size()-1 && nums[i]!=0; j++){
                k = binarysearch(nums,k,nums.size()-1, nums[i] +nums[j]);
                count+=k-j-1;
            }
        }
        return count;
    }
};
