class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        if(height.size()==0)
        {
            return 0;
        }
        vector<int>leftmax(height.size());
        vector<int>rightmax(height.size());
        leftmax[0]=height[0];
        for(int i=1;i<height.size();i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        rightmax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        for(int i=0;i<height.size();i++)
        {
            ans+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ans;
    }
};
