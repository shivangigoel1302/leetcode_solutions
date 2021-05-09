class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int>m;
        stack<int>s;
        for(int i = n-1 ; i >=0 ; i--){
            while(!s.empty() && nums2[i] >= s.top()){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int>v;
        for(int i = 0 ; i < nums1.size(); i++){
            v.push_back(m[nums1[i]]);
        }
        return v;
    }
};
